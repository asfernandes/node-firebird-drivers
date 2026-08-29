import { Buffer } from 'node:buffer';
import { connect as connectSocket, Socket } from 'node:net';
import { hostname, userInfo } from 'node:os';

import { cancelType, commonInfo, statementInfo } from 'node-firebird-driver/dist/lib/impl';

import {
  buildAttachmentDpb,
  buildConnectPluginList,
  buildRemainingPluginList,
  normalizeLogin,
  writeMultiPartConnectParameter,
} from './auth-helpers';
import { ClientAuthPlugin, createAuthPlugin } from './auth/plugins';
import {
  authPlugin,
  connectParameter,
  dsql,
  protocolRequest,
  statementFlag,
  wireCrypt,
  wireOp,
  wirePacketType,
  wireProtocolFeature,
  wireProtocol,
} from './constants';
import { buildEventBlock, calculateEventCounts, getEventHost, parseAuxiliaryPort } from './event-helpers';
import { buildPackedMessage, readPackedMessageBuffer } from './packed-message';
import {
  AcceptMessage,
  AttachmentHandle,
  BlobHandle,
  BlobSegmentResponse,
  CursorHandle,
  EventCallback,
  EventHandle,
  EventMessage,
  EventSubscription,
  InlineBlobResponse,
  ResponseMessage,
  StatementHandle,
  StatementMetadata,
  TransactionHandle,
  WireProtocolOptions,
} from './protocol-types';
import { SocketChannel } from './socket-channel';
import { parseStatementMetadata } from './statement-metadata';
import { assertSuccessfulResponse, parseStatusVector } from './status';
import { createWireCryptSession } from './wire-crypt';
import { writeTraditionalClumplet, XdrWriter } from './xdr';

export type {
  AttachmentHandle,
  BlobHandle,
  BlobSegmentResponse,
  CursorHandle,
  EventHandle,
  StatementColumn,
  StatementHandle,
  TransactionHandle,
  WireProtocolOptions,
} from './protocol-types';

type AuthPluginName = authPlugin.Name;

const FETCH_NO_DATA = 100;
const FETCH_ROW_BATCH_SIZE = 400;

interface CursorFetchState {
  readonly rows: Buffer[];
  exhausted: boolean;
  pendingError?: unknown;
}

const STATEMENT_BASE_INFO_ITEMS = Buffer.from([statementInfo.sqlStmtType, statementInfo.sqlStmtFlags]);
const STATEMENT_SELECT_INFO_ITEMS = Buffer.from([
  statementInfo.sqlSelect,
  statementInfo.sqlDescribeVars,
  statementInfo.sqlSqldaSeq,
  statementInfo.sqlType,
  statementInfo.sqlSubType,
  statementInfo.sqlScale,
  statementInfo.sqlLength,
  statementInfo.sqlField,
  statementInfo.sqlAlias,
  statementInfo.sqlRelation,
  statementInfo.sqlRelationAlias,
  statementInfo.sqlOwner,
  statementInfo.sqlDescribeEnd,
]);
const STATEMENT_BIND_INFO_ITEMS = Buffer.from([
  statementInfo.sqlBind,
  statementInfo.sqlDescribeVars,
  statementInfo.sqlSqldaSeq,
  statementInfo.sqlType,
  statementInfo.sqlSubType,
  statementInfo.sqlScale,
  statementInfo.sqlLength,
  statementInfo.sqlDescribeEnd,
]);
const INFO_BUFFER_LENGTH = 32767;
const BLOB_SEEK_RELATIVE = 1;
const BLOB_SEEK_FROM_END = 2;

export class WireProtocol {
  private socket?: Socket;
  private channel?: SocketChannel;
  private eventSocket?: Socket;
  private eventChannel?: SocketChannel;
  private eventLoopPromise?: Promise<void>;
  private mainChannelQueue: Promise<void> = Promise.resolve();
  private attachmentHandle?: number;
  private currentPluginName: AuthPluginName = authPlugin.list[0];
  private currentPlugin?: ClientAuthPlugin;
  private clientAuthListSent = false;
  private wireCryptEnabled = false;
  private acceptedProtocolVersion?: number;
  private acceptedPacketType = wirePacketType.batchSend;
  private readonly pendingServerKeys: Buffer[] = [];
  private readonly statementMetadata = new Map<number, StatementMetadata>();
  private readonly cursorFetchStates = new Map<number, CursorFetchState>();
  private readonly eventSubscriptions = new Map<number, EventSubscription>();
  private readonly inlineBlobs = new Map<string, InlineBlobResponse>();
  private readonly blobPositions = new Map<number, number>();
  private readonly blobSeekStates = new Map<number, { data: Buffer; position: number }>();
  private nextEventId = 1;

  constructor(private readonly options: WireProtocolOptions) {}

  async attach(database: string, dpb: Buffer): Promise<AttachmentHandle> {
    return await this.runMainChannelTask(async () => {
      if (this.attachmentHandle) {
        throw new Error('A database is already attached on this protocol instance.');
      }

      await this.openSocket();
      const attachAuthData = await this.performConnectHandshake(database);
      return await this.executeAttachmentOperation(wireOp.attach, database, dpb, attachAuthData, 'attach');
    });
  }

  async createDatabase(database: string, dpb: Buffer): Promise<AttachmentHandle> {
    return await this.runMainChannelTask(async () => {
      if (this.attachmentHandle) {
        throw new Error('A database is already attached on this protocol instance.');
      }

      await this.openSocket();
      const attachAuthData = await this.performConnectHandshake(database);
      return await this.executeAttachmentOperation(wireOp.create, database, dpb, attachAuthData, 'create');
    });
  }

  async detach(attachment: AttachmentHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      if (this.attachmentHandle !== attachment.handle) {
        throw new Error('Attachment handle is not active.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.detach);
      writer.writeInt32(0);
      await this.channel!.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while detaching.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird detach failed');
      this.attachmentHandle = undefined;
      this.cursorFetchStates.clear();
    });
  }

  async dropDatabase(attachment: AttachmentHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      if (this.attachmentHandle !== attachment.handle) {
        throw new Error('Attachment handle is not active.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.dropDatabase);
      writer.writeInt32(0);
      await this.channel!.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while dropping the database.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird drop database failed');
      this.attachmentHandle = undefined;
      this.cursorFetchStates.clear();
    });
  }

  async ping(): Promise<void> {
    await this.runMainChannelTask(async () => {
      if (!this.channel) {
        throw new Error('Wire protocol socket is not open.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.ping);
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while pinging.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird ping failed');
    });
  }

  async queueEvents(names: readonly string[], callback: EventCallback): Promise<EventHandle> {
    return await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before queueing events.');
      }

      await this.ensureEventChannel();

      const eventHandle: EventHandle = {
        id: this.nextEventId++,
        names: [...names],
      };

      const subscription: EventSubscription = {
        ...eventHandle,
        callback,
        eventBuffer: buildEventBlock(names),
      };
      this.eventSubscriptions.set(eventHandle.id, subscription);

      try {
        await this.sendQueueEvents(subscription);
        return eventHandle;
      } catch (error) {
        this.eventSubscriptions.delete(subscription.id);
        throw error;
      }
    });
  }

  async cancelEvents(event: EventHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      const subscription = this.eventSubscriptions.get(event.id);
      if (!subscription) {
        return;
      }

      this.eventSubscriptions.delete(event.id);

      if (!this.channel || this.attachmentHandle == undefined) {
        return;
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.cancelEvents);
      writer.writeInt32(0);
      writer.writeInt32(event.id);
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while cancelling events.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird cancel events failed');
    });
  }

  async cancelOperation(kind: number): Promise<void> {
    if (!this.channel) {
      throw new Error('Wire protocol socket is not open.');
    }

    if (kind === cancelType.abort) {
      await this.close();
      return;
    }

    const writer = new XdrWriter();
    writer.writeInt32(wireOp.cancel);
    writer.writeInt32(kind);
    await this.channel.write(writer.toBuffer());
  }

  async startTransaction(tpb: Buffer): Promise<TransactionHandle> {
    return await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before starting a transaction.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.transaction);
      writer.writeInt32(0);
      writer.writeBuffer(tpb);
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while starting a transaction.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird start transaction failed');
      return { handle: response.handle };
    });
  }

  async commit(transaction: TransactionHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishTransaction(wireOp.commit, transaction, 'commit');
    });
  }

  async rollback(transaction: TransactionHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishTransaction(wireOp.rollback, transaction, 'rollback');
    });
  }

  async commitRetaining(transaction: TransactionHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishTransaction(wireOp.commitRetaining, transaction, 'commit retaining');
    });
  }

  async rollbackRetaining(transaction: TransactionHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishTransaction(wireOp.rollbackRetaining, transaction, 'rollback retaining');
    });
  }

  async createBlob(transaction: TransactionHandle, bpb: Uint8Array = Buffer.alloc(0)): Promise<BlobHandle> {
    return await this.runMainChannelTask(async () => {
      return await this.openOrCreateBlob(wireOp.createBlob2, transaction, Buffer.alloc(8), bpb, 'create blob');
    });
  }

  async openBlob(
    transaction: TransactionHandle,
    blobId: Uint8Array,
    bpb: Uint8Array = Buffer.alloc(0),
  ): Promise<BlobHandle> {
    return await this.runMainChannelTask(async () => {
      return await this.openOrCreateBlob(wireOp.openBlob2, transaction, blobId, bpb, 'open blob');
    });
  }

  async getSegment(blob: BlobHandle, bufferLength: number): Promise<BlobSegmentResponse> {
    return await this.runMainChannelTask(async () => {
      const localBlobState = this.blobSeekStates.get(blob.handle);
      if (localBlobState) {
        return this.readLocalBlobSegment(blob, localBlobState, bufferLength);
      }

      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before reading a blob segment.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.getSegment);
      writer.writeInt32(blob.handle);
      writer.writeInt32(bufferLength);
      writer.writeBuffer(Buffer.alloc(0));
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while getting a blob segment.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird get blob segment failed');
      this.blobPositions.set(
        blob.handle,
        (this.blobPositions.get(blob.handle) ?? 0) + this.getPackedBlobLength(response.data),
      );
      return {
        state: response.handle,
        data: response.data,
      };
    });
  }

  async putSegment(blob: BlobHandle, segment: Buffer): Promise<void> {
    await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before writing a blob segment.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.putSegment);
      writer.writeInt32(blob.handle);
      writer.writeInt32(segment.length);
      writer.writeBuffer(segment);
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while putting a blob segment.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird put blob segment failed');
      this.blobPositions.set(blob.handle, (this.blobPositions.get(blob.handle) ?? 0) + segment.length);
    });
  }

  async seekBlob(blob: BlobHandle, mode: number, offset: number): Promise<number> {
    return await this.runMainChannelTask(async () => {
      const localBlobState = this.blobSeekStates.get(blob.handle);
      if (localBlobState) {
        const currentPosition = localBlobState.position;
        const basePosition =
          mode === BLOB_SEEK_RELATIVE ? currentPosition : mode === BLOB_SEEK_FROM_END ? localBlobState.data.length : 0;
        const position = Math.max(0, Math.min(localBlobState.data.length, basePosition + offset));
        localBlobState.position = position;
        this.blobPositions.set(blob.handle, position);
        return position;
      }

      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before seeking a blob.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.seekBlob);
      writer.writeInt32(blob.handle);
      writer.writeInt32(mode);
      writer.writeInt32(offset);
      if (this.acceptedPacketType === wirePacketType.lazySend) {
        writer.writeInt32(wireOp.ping);
      }
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while seeking a blob.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird seek blob failed');
      if (this.acceptedPacketType === wirePacketType.lazySend) {
        const syncOperation = await this.readOperation();
        if (syncOperation !== wireOp.response) {
          throw new Error(`Unexpected operation ${syncOperation} while syncing seek blob.`);
        }

        const syncResponse = await this.readResponse();
        assertSuccessfulResponse(syncResponse.status, 'Firebird seek blob sync failed');
      }
      const position = response.handle !== 0 ? response.handle : response.quad.readInt32BE(4);
      this.blobPositions.set(blob.handle, position);
      return position;
    });
  }

  async closeBlob(blob: BlobHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishBlob(wireOp.closeBlob, blob, 'close blob');
    });
  }

  async cancelBlob(blob: BlobHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishBlob(wireOp.cancelBlob, blob, 'cancel blob');
    });
  }

  async allocateStatement(): Promise<StatementHandle> {
    return await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before allocating a statement.');
      }

      const writer = new XdrWriter();

      writer.writeInt32(wireOp.allocateStatement);
      writer.writeInt32(0);

      if (this.acceptedPacketType === wirePacketType.lazySend) {
        writer.writeInt32(wireOp.ping);
      }

      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while allocating a statement.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird allocate statement failed');

      if (this.acceptedPacketType === wirePacketType.lazySend) {
        const syncOperation = await this.readOperation();
        if (syncOperation !== wireOp.response) {
          throw new Error(`Unexpected operation ${syncOperation} while syncing statement allocation.`);
        }

        const syncResponse = await this.readResponse();
        assertSuccessfulResponse(syncResponse.status, 'Firebird allocate statement sync failed');
      }

      return { handle: response.handle };
    });
  }

  async allocateAndPrepareStatement(
    transaction: TransactionHandle,
    sql: string,
    sqlDialect = 3,
  ): Promise<StatementHandle> {
    return await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before allocating a statement.');
      }

      if (!(this.supportsProtocol(wireProtocol.version11) && this.acceptedPacketType === wirePacketType.lazySend)) {
        const allocateWriter = new XdrWriter();
        allocateWriter.writeInt32(wireOp.allocateStatement);
        allocateWriter.writeInt32(0);
        await this.channel.write(allocateWriter.toBuffer());

        const allocateOperation = await this.readOperation();
        if (allocateOperation !== wireOp.response) {
          throw new Error(`Unexpected operation ${allocateOperation} while allocating a statement.`);
        }

        const allocateResponse = await this.readResponse();
        assertSuccessfulResponse(allocateResponse.status, 'Firebird allocate statement failed');

        const statement = { handle: allocateResponse.handle };

        const prepareWriter = new XdrWriter();
        prepareWriter.writeInt32(wireOp.prepareStatement);
        prepareWriter.writeInt32(transaction.handle);
        prepareWriter.writeInt32(statement.handle);
        prepareWriter.writeInt32(sqlDialect);
        prepareWriter.writeString(sql);
        prepareWriter.writeBuffer(STATEMENT_BASE_INFO_ITEMS);
        prepareWriter.writeInt32(INFO_BUFFER_LENGTH);
        await this.channel.write(prepareWriter.toBuffer());

        const prepareOperation = await this.readOperation();
        if (prepareOperation !== wireOp.response) {
          throw new Error(`Unexpected operation ${prepareOperation} while preparing a statement.`);
        }

        const prepareResponse = await this.readResponse();
        await this.storePreparedStatementMetadata(statement, prepareResponse, 'Firebird prepare statement failed');

        return statement;
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.allocateStatement);
      writer.writeInt32(0);
      writer.writeInt32(wireOp.prepareStatement);
      writer.writeInt32(transaction.handle);
      writer.writeInt32(wireProtocolFeature.invalidObjectHandle);
      writer.writeInt32(sqlDialect);
      writer.writeString(sql);
      writer.writeBuffer(STATEMENT_BASE_INFO_ITEMS);
      writer.writeInt32(INFO_BUFFER_LENGTH);
      await this.channel.write(writer.toBuffer());

      const allocateOperation = await this.readOperation();
      if (allocateOperation !== wireOp.response) {
        throw new Error(`Unexpected operation ${allocateOperation} while allocating a statement.`);
      }

      const allocateResponse = await this.readResponse();
      assertSuccessfulResponse(allocateResponse.status, 'Firebird allocate statement failed');

      const statement = { handle: allocateResponse.handle };

      const prepareOperation = await this.readOperation();
      if (prepareOperation !== wireOp.response) {
        throw new Error(`Unexpected operation ${prepareOperation} while preparing a statement.`);
      }

      const prepareResponse = await this.readResponse();
      await this.storePreparedStatementMetadata(statement, prepareResponse, 'prepare statement failed');

      return statement;
    });
  }

  async prepareStatement(
    transaction: TransactionHandle,
    statement: StatementHandle,
    sql: string,
    sqlDialect = 3,
  ): Promise<void> {
    await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before preparing a statement.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.prepareStatement);
      writer.writeInt32(transaction.handle);
      writer.writeInt32(statement.handle);
      writer.writeInt32(sqlDialect);
      writer.writeString(sql);
      writer.writeBuffer(STATEMENT_BASE_INFO_ITEMS);
      writer.writeInt32(INFO_BUFFER_LENGTH);
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while preparing a statement.`);
      }

      const response = await this.readResponse();
      await this.storePreparedStatementMetadata(statement, response, 'Firebird prepare statement failed');
    });
  }

  async executeStatement(
    transaction: TransactionHandle,
    statement: StatementHandle,
    inputMessage?: Buffer,
  ): Promise<Buffer | undefined> {
    return await this.runMainChannelTask(async () => {
      return await this.executePreparedStatement(transaction, statement, inputMessage, false);
    });
  }

  async executeStatementReturning(
    transaction: TransactionHandle,
    statement: StatementHandle,
    inputMessage?: Buffer,
  ): Promise<Buffer | undefined> {
    return await this.runMainChannelTask(async () => {
      return await this.executePreparedStatement(transaction, statement, inputMessage, true);
    });
  }

  async setCursorName(statement: StatementHandle, cursorName: string): Promise<void> {
    await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before setting a cursor name.');
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.setCursor);
      writer.writeInt32(statement.handle);
      writer.writeString(cursorName);
      writer.writeInt32(0);
      await this.channel.write(writer.toBuffer());

      const operation = await this.readOperation();
      if (operation !== wireOp.response) {
        throw new Error(`Unexpected operation ${operation} while setting a cursor name.`);
      }

      const response = await this.readResponse();
      assertSuccessfulResponse(response.status, 'Firebird set cursor name failed');
    });
  }

  async getSqlInfo(statement: StatementHandle, items: Buffer): Promise<Buffer> {
    return await this.runMainChannelTask(async () => {
      return await this.getInfo(wireOp.infoSql, statement.handle, items, 'sql info');
    });
  }

  async getBlobInfo(blob: BlobHandle, items: Buffer): Promise<Buffer> {
    return await this.runMainChannelTask(async () => {
      return await this.getInfo(wireOp.infoBlob, blob.handle, items, 'blob info');
    });
  }

  getStatementMetadata(statement: StatementHandle): StatementMetadata {
    const metadata = this.statementMetadata.get(statement.handle);
    if (!metadata) {
      throw new Error('Statement metadata is not available.');
    }

    return metadata;
  }

  async openCursor(
    transaction: TransactionHandle,
    statement: StatementHandle,
    inputMessage?: Buffer,
  ): Promise<CursorHandle> {
    return await this.runMainChannelTask(async () => {
      const metadata = this.getStatementMetadata(statement);

      if ((metadata.flags & statementFlag.hasCursor) === 0) {
        throw new Error('Statement does not produce a cursor.');
      }

      await this.executePreparedStatement(transaction, statement, inputMessage, false);
      this.cursorFetchStates.set(statement.handle, { rows: [], exhausted: false });

      return {
        statement,
        transaction,
        columns: metadata.outputColumns,
        fetchBlr: metadata.outputBlr,
        fetchMessageLength: metadata.outputMessageLength,
      };
    });
  }

  async fetchNext(cursor: CursorHandle): Promise<Buffer | undefined> {
    return await this.runMainChannelTask(async () => {
      if (!this.channel || this.attachmentHandle == undefined) {
        throw new Error('A database must be attached before fetching from a cursor.');
      }

      const metadata = this.statementMetadata.get(cursor.statement.handle);
      if (!metadata) {
        throw new Error('Statement metadata is not available for cursor fetch.');
      }

      const fetchState = this.cursorFetchStates.get(cursor.statement.handle) ?? {
        rows: [],
        exhausted: false,
        pendingError: undefined,
      };
      this.cursorFetchStates.set(cursor.statement.handle, fetchState);

      if (fetchState.rows.length > 0) {
        return fetchState.rows.shift();
      }

      if (fetchState.pendingError !== undefined) {
        const pendingError = fetchState.pendingError;
        delete fetchState.pendingError;
        throw pendingError;
      }

      if (fetchState.exhausted) {
        return undefined;
      }

      const writer = new XdrWriter();
      writer.writeInt32(wireOp.fetch);
      writer.writeInt32(cursor.statement.handle);
      writer.writeBuffer(cursor.fetchBlr);
      writer.writeInt32(0);
      writer.writeInt32(FETCH_ROW_BATCH_SIZE);
      await this.channel.write(writer.toBuffer());

      let operation = await this.readOperationWithInlineBlobs();
      if (operation === wireOp.response) {
        const response = await this.readResponse();
        assertSuccessfulResponse(response.status, 'Firebird fetch cursor row failed');
        return undefined;
      }

      if (operation !== wireOp.fetchResponse) {
        throw new Error(`Unexpected operation ${operation} while fetching a cursor row.`);
      }

      while (true) {
        const status = (await this.channel.readExactly(4)).readInt32BE(0);
        const messages = (await this.channel.readExactly(4)).readInt32BE(0);

        if (messages === 0) {
          if (status === FETCH_NO_DATA) {
            fetchState.exhausted = true;
          } else if (status !== 0) {
            fetchState.pendingError = new Error(`Firebird cursor fetch failed with status ${status}.`);
          }
          break;
        }

        if (messages !== 1) {
          throw new Error(`Unsupported cursor fetch batch size ${messages}.`);
        }

        fetchState.rows.push(
          await readPackedMessageBuffer(this.channel, metadata.outputColumns, metadata.outputMessageLength),
        );

        operation = await this.readOperationWithInlineBlobs();
        if (operation === wireOp.response) {
          const response = await this.readResponse();
          try {
            assertSuccessfulResponse(response.status, 'Firebird fetch cursor row failed');
          } catch (error) {
            fetchState.pendingError = error;
            break;
          }

          fetchState.pendingError = new Error(
            `Unexpected operation ${operation} while completing a cursor fetch batch.`,
          );
          break;
        }

        if (operation !== wireOp.fetchResponse) {
          throw new Error(`Unexpected operation ${operation} while completing a cursor fetch batch.`);
        }
      }

      if (fetchState.rows.length > 0) {
        return fetchState.rows.shift();
      }

      if (fetchState.pendingError !== undefined) {
        const pendingError = fetchState.pendingError;
        delete fetchState.pendingError;
        throw pendingError;
      }

      return undefined;
    });
  }

  async closeCursor(statement: StatementHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishStatement(statement, dsql.close, 'close cursor');
    });
  }

  async freeStatement(statement: StatementHandle): Promise<void> {
    await this.runMainChannelTask(async () => {
      await this.finishStatement(statement, dsql.drop, 'free statement');
    });
  }

  async close(): Promise<void> {
    if (this.eventSocket) {
      const eventSocket = this.eventSocket;
      this.eventChannel = undefined;
      this.eventSocket = undefined;
      eventSocket.destroy();
    }

    if (this.channel) {
      const writer = new XdrWriter();
      writer.writeInt32(wireOp.disconnect);
      await this.channel.write(writer.toBuffer()).catch(() => undefined);
    }

    if (this.socket) {
      const socket = this.socket;
      await new Promise<void>((resolve) => {
        let settled = false;

        const finish = () => {
          if (settled) {
            return;
          }

          settled = true;
          socket.off('close', onClose);
          clearTimeout(destroyTimer);
          resolve();
        };

        const onClose = () => finish();

        const destroyTimer = setTimeout(() => {
          socket.destroy();
          finish();
        }, this.options.timeoutMs ?? 5000);

        destroyTimer.unref();

        socket.once('close', onClose);
        socket.end();
      }).catch(() => undefined);
    }

    this.channel = undefined;
    this.socket = undefined;
    this.attachmentHandle = undefined;
    this.wireCryptEnabled = false;
    this.acceptedProtocolVersion = undefined;
    this.acceptedPacketType = wirePacketType.batchSend;
    this.pendingServerKeys.length = 0;
    this.eventSubscriptions.clear();
    this.cursorFetchStates.clear();
    this.inlineBlobs.clear();
  }

  private async openSocket(): Promise<void> {
    if (this.socket) {
      return;
    }

    const socket = connectSocket({
      host: this.options.host,
      port: this.options.port ?? 3050,
      timeout: this.options.timeoutMs ?? 5000,
    });

    await new Promise<void>((resolve, reject) => {
      socket.once('connect', () => resolve());
      socket.once('error', (error) => reject(error));
      socket.once('timeout', () => reject(new Error('Firebird socket connection timed out.')));
    });

    this.socket = socket;
    this.channel = new SocketChannel(socket);
  }

  private async runMainChannelTask<T>(task: () => Promise<T>): Promise<T> {
    const previous = this.mainChannelQueue;
    let release: () => void = undefined!;
    this.mainChannelQueue = new Promise<void>((resolve) => {
      release = resolve;
    });

    await previous;

    try {
      return await task();
    } finally {
      release();
    }
  }

  private async ensureEventChannel(): Promise<void> {
    if (this.eventChannel) {
      return;
    }

    if (!this.channel || this.attachmentHandle == undefined || !this.socket) {
      throw new Error('A database must be attached before opening the event channel.');
    }

    const writer = new XdrWriter();
    writer.writeInt32(wireOp.connectRequest);
    writer.writeInt32(protocolRequest.async);
    writer.writeInt32(0);
    writer.writeInt32(0);
    await this.channel.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while opening the event channel.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, 'Firebird open event channel failed');

    const eventPort = parseAuxiliaryPort(response.data);
    const eventHost = getEventHost(this.socket.remoteAddress, this.options.host);
    const eventSocket = connectSocket({
      host: eventHost,
      port: eventPort,
      timeout: this.options.timeoutMs ?? 5000,
    });

    await new Promise<void>((resolve, reject) => {
      eventSocket.once('connect', () => resolve());
      eventSocket.once('error', (error) => reject(error));
      eventSocket.once('timeout', () => reject(new Error('Firebird event socket connection timed out.')));
    });

    this.eventSocket = eventSocket;
    this.eventChannel = new SocketChannel(eventSocket);
    this.eventLoopPromise = this.runEventLoop();
    this.eventLoopPromise.catch(() => undefined);
  }

  private async finishTransaction(
    operationCode: number,
    transaction: TransactionHandle,
    actionName: string,
  ): Promise<void> {
    if (!this.channel || this.attachmentHandle == undefined) {
      throw new Error(`A database must be attached before ${actionName}.`);
    }

    const writer = new XdrWriter();
    writer.writeInt32(operationCode);
    writer.writeInt32(transaction.handle);
    await this.channel.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while executing transaction ${actionName}.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, `Firebird ${actionName} failed`);

    if (operationCode === wireOp.commit || operationCode === wireOp.rollback) {
      this.clearInlineBlobsForTransaction(transaction.handle);
    }
  }

  private async finishStatement(statement: StatementHandle, option: number, actionName: string): Promise<void> {
    if (!this.channel || this.attachmentHandle == undefined) {
      throw new Error(`A database must be attached before ${actionName}.`);
    }

    const writer = new XdrWriter();

    writer.writeInt32(wireOp.freeStatement);
    writer.writeInt32(statement.handle);
    writer.writeInt32(option);

    if (this.acceptedPacketType === wirePacketType.lazySend) {
      writer.writeInt32(wireOp.ping);
    }

    await this.channel.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while executing ${actionName}.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, `Firebird ${actionName} failed`);

    if (this.acceptedPacketType === wirePacketType.lazySend) {
      const syncOperation = await this.readOperation();
      if (syncOperation !== wireOp.response) {
        throw new Error(`Unexpected operation ${syncOperation} while syncing ${actionName}.`);
      }

      const syncResponse = await this.readResponse();
      assertSuccessfulResponse(syncResponse.status, `Firebird ${actionName} sync failed`);
    }

    if ((option & dsql.drop) !== 0) {
      this.statementMetadata.delete(statement.handle);
    }

    this.cursorFetchStates.delete(statement.handle);
  }

  private async storePreparedStatementMetadata(
    statement: StatementHandle,
    response: ResponseMessage,
    actionName: string,
  ): Promise<void> {
    assertSuccessfulResponse(response.status, actionName);

    const selectInfo = await this.getInfo(
      wireOp.infoSql,
      statement.handle,
      STATEMENT_SELECT_INFO_ITEMS,
      'statement output metadata',
    );
    const bindInfo = await this.getInfo(
      wireOp.infoSql,
      statement.handle,
      STATEMENT_BIND_INFO_ITEMS,
      'statement input metadata',
    );

    const metadataInfo = this.concatInfoBuffers([response.data, selectInfo, bindInfo]);
    this.statementMetadata.set(statement.handle, parseStatementMetadata(metadataInfo));
  }

  private async openOrCreateBlob(
    operationCode: number,
    transaction: TransactionHandle,
    blobId: Uint8Array,
    bpb: Uint8Array,
    actionName: string,
  ): Promise<BlobHandle> {
    if (!this.channel || this.attachmentHandle == undefined) {
      throw new Error(`A database must be attached before ${actionName}.`);
    }

    if (blobId.length !== 8) {
      throw new Error('Blob id must contain exactly 8 bytes.');
    }

    const writer = new XdrWriter();
    writer.writeInt32(operationCode);
    writer.writeBuffer(Buffer.from(bpb));
    writer.writeInt32(transaction.handle);
    writer.writeBytes(Buffer.from(blobId));
    await this.channel.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while executing ${actionName}.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, `Firebird ${actionName} failed`);
    const blobHandle = {
      handle: response.handle,
      id: Buffer.from(response.quad),
      transaction,
      bpb: Buffer.from(bpb),
    };

    if (operationCode === wireOp.openBlob2 && this.isStreamBlobParameterBuffer(bpb)) {
      const data = await this.readAllBlobSegments(blobHandle);
      this.blobSeekStates.set(blobHandle.handle, { data, position: 0 });
      this.blobPositions.set(blobHandle.handle, 0);
    }

    return blobHandle;
  }

  private async finishBlob(operationCode: number, blob: BlobHandle, actionName: string): Promise<void> {
    if (!this.channel || this.attachmentHandle == undefined) {
      throw new Error(`A database must be attached before ${actionName}.`);
    }

    const writer = new XdrWriter();
    writer.writeInt32(operationCode);
    writer.writeInt32(blob.handle);
    if (this.acceptedPacketType === wirePacketType.lazySend) {
      writer.writeInt32(wireOp.ping);
    }
    await this.channel.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while executing ${actionName}.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, `Firebird ${actionName} failed`);
    this.blobPositions.delete(blob.handle);
    this.blobSeekStates.delete(blob.handle);

    if (this.acceptedPacketType === wirePacketType.lazySend) {
      const syncOperation = await this.readOperation();
      if (syncOperation !== wireOp.response) {
        throw new Error(`Unexpected operation ${syncOperation} while syncing ${actionName}.`);
      }

      const syncResponse = await this.readResponse();
      assertSuccessfulResponse(syncResponse.status, `Firebird ${actionName} sync failed`);
    }
  }

  private readLocalBlobSegment(
    blob: BlobHandle,
    localBlobState: { data: Buffer; position: number },
    bufferLength: number,
  ): BlobSegmentResponse {
    const maxSegmentLength = Math.max(0, bufferLength - 2);
    const remainingLength = localBlobState.data.length - localBlobState.position;

    if (remainingLength <= 0 || maxSegmentLength <= 0) {
      return {
        state: 2,
        data: Buffer.alloc(0),
      };
    }

    const segmentLength = Math.min(remainingLength, maxSegmentLength);
    const packedSegment = Buffer.alloc(2 + segmentLength);
    packedSegment.writeUInt16LE(segmentLength, 0);
    localBlobState.data.copy(packedSegment, 2, localBlobState.position, localBlobState.position + segmentLength);
    localBlobState.position += segmentLength;
    this.blobPositions.set(blob.handle, localBlobState.position);

    return {
      state: localBlobState.position >= localBlobState.data.length ? 2 : 0,
      data: packedSegment,
    };
  }

  private async readAllBlobSegments(blob: BlobHandle): Promise<Buffer> {
    const chunks: Buffer[] = [];

    while (true) {
      const response = await this.getRemoteBlobSegment(blob, INFO_BUFFER_LENGTH);
      const segmentLength = this.getPackedBlobLength(response.data);

      if (segmentLength > 0) {
        chunks.push(...this.unpackPackedBlobSegments(response.data));
      }

      if (response.handle === 2 || segmentLength === 0) {
        break;
      }
    }

    return Buffer.concat(chunks);
  }

  private async getRemoteBlobSegment(blob: BlobHandle, bufferLength: number): Promise<ResponseMessage> {
    if (!this.channel || this.attachmentHandle == undefined) {
      throw new Error('A database must be attached before reading a blob segment.');
    }

    const writer = new XdrWriter();
    writer.writeInt32(wireOp.getSegment);
    writer.writeInt32(blob.handle);
    writer.writeInt32(bufferLength);
    writer.writeBuffer(Buffer.alloc(0));
    await this.channel.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while getting a blob segment.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, 'Firebird get blob segment failed');
    return response;
  }

  private unpackPackedBlobSegments(buffer: Buffer): Buffer[] {
    const segments: Buffer[] = [];
    let offset = 0;

    while (offset + 2 <= buffer.length) {
      const length = buffer.readUInt16LE(offset);
      offset += 2;

      if (offset + length > buffer.length) {
        throw new Error('Invalid packed blob segment buffer.');
      }

      segments.push(Buffer.from(buffer.subarray(offset, offset + length)));
      offset += length;
    }

    if (offset !== buffer.length) {
      throw new Error('Packed blob segment buffer has trailing bytes.');
    }

    return segments;
  }

  private getPackedBlobLength(buffer: Buffer): number {
    return this.unpackPackedBlobSegments(buffer).reduce((totalLength, segment) => totalLength + segment.length, 0);
  }

  private isStreamBlobParameterBuffer(bpb: Uint8Array): boolean {
    for (let offset = 1; offset + 1 < bpb.length; ) {
      const item = bpb[offset++];
      const length = bpb[offset++];

      if (offset + length > bpb.length) {
        break;
      }

      if (item === 3 && length === 1 && bpb[offset] === 1) {
        return true;
      }

      offset += length;
    }

    return false;
  }

  private async executePreparedStatement(
    transaction: TransactionHandle,
    statement: StatementHandle,
    inputMessage: Buffer | undefined,
    withOutput: boolean,
  ): Promise<Buffer | undefined> {
    if (!this.channel || this.attachmentHandle == undefined) {
      throw new Error('A database must be attached before executing a statement.');
    }

    const metadata = this.getStatementMetadata(statement);
    const writer = new XdrWriter();
    const hasInput = metadata.inputColumns.length > 0;

    writer.writeInt32(withOutput ? wireOp.execute2 : wireOp.execute);
    writer.writeInt32(statement.handle);
    writer.writeInt32(transaction.handle);
    writer.writeBuffer(hasInput ? metadata.inputBlr : Buffer.alloc(0));
    writer.writeInt32(0);
    writer.writeInt32(hasInput ? 1 : 0);

    if (hasInput) {
      writer.writeBytes(buildPackedMessage(metadata.inputColumns, metadata.inputMessageLength, inputMessage));
    }

    if (withOutput) {
      writer.writeBuffer(metadata.outputBlr);
      writer.writeInt32(0);
    }

    if (this.supportsProtocol(wireProtocol.version16)) {
      writer.writeInt32(0);
    }

    if (this.supportsProtocol(wireProtocol.version18)) {
      writer.writeInt32(0);
    }

    if (this.supportsProtocol(wireProtocol.version19)) {
      writer.writeInt32(wireProtocolFeature.inlineBlobMaxSize);
    }

    await this.channel.write(writer.toBuffer());

    let outputMessage: Buffer | undefined;
    let operation = await this.readOperationWithInlineBlobs();

    if (withOutput && operation === wireOp.sqlResponse) {
      const messages = (await this.channel.readExactly(4)).readInt32BE(0);

      if (messages > 0) {
        outputMessage = await readPackedMessageBuffer(
          this.channel,
          metadata.outputColumns,
          metadata.outputMessageLength,
        );
      }

      operation = await this.readOperationWithInlineBlobs();
    }

    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while executing a statement.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, 'Firebird execute statement failed');

    return outputMessage;
  }

  private async getInfo(operationCode: number, handle: number, items: Buffer, actionName: string): Promise<Buffer> {
    if (!this.channel || this.attachmentHandle == undefined) {
      throw new Error(`A database must be attached before ${actionName}.`);
    }

    const writer = new XdrWriter();
    writer.writeInt32(operationCode);
    writer.writeInt32(handle);
    writer.writeInt32(0);
    writer.writeBuffer(items);
    writer.writeInt32(INFO_BUFFER_LENGTH);
    await this.channel.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while executing ${actionName}.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, `Firebird ${actionName} failed`);
    return response.data;
  }

  private async writeConnect(database: string): Promise<void> {
    const systemUserName = this.getSystemUserName();
    const identification = Buffer.concat([
      writeTraditionalClumplet(connectParameter.login, Buffer.from(this.options.username, 'utf8')),
      writeTraditionalClumplet(connectParameter.pluginName, Buffer.from(this.currentPluginName, 'utf8')),
      writeTraditionalClumplet(connectParameter.pluginList, Buffer.from(buildConnectPluginList(), 'utf8')),
      writeMultiPartConnectParameter(connectParameter.specificData, this.currentPlugin!.initialData),
      writeTraditionalClumplet(connectParameter.clientCrypt, Buffer.from([wireCrypt.enabled])),
      writeTraditionalClumplet(connectParameter.user, Buffer.from(systemUserName, 'utf8')),
      writeTraditionalClumplet(connectParameter.host, Buffer.from(hostname(), 'utf8')),
      writeTraditionalClumplet(connectParameter.userVerification, Buffer.alloc(0)),
    ]);

    const writer = new XdrWriter();
    writer.writeInt32(wireOp.connect);
    writer.writeInt32(0);
    writer.writeInt32(wireProtocol.connectVersion3);
    writer.writeInt32(wireProtocol.archGeneric);
    writer.writeString(database);
    writer.writeInt32(wireProtocol.supportedProtocols.length);
    writer.writeBuffer(identification);

    let weight = wireProtocol.supportedProtocols.length;

    for (const protocolVersion of wireProtocol.supportedProtocols) {
      writer.writeInt32(protocolVersion);
      writer.writeInt32(wireProtocol.archGeneric);
      writer.writeInt32(wirePacketType.lazySend);
      writer.writeInt32(wirePacketType.lazySend);
      writer.writeInt32(weight--);
    }

    await this.channel!.write(writer.toBuffer());
  }

  private async writeAttachmentOperation(operation: number, database: string, dpb: Buffer): Promise<void> {
    const writer = new XdrWriter();
    writer.writeInt32(operation);
    writer.writeInt32(0);
    writer.writeString(database);
    writer.writeBuffer(dpb);
    await this.channel!.write(writer.toBuffer());
  }

  private async performConnectHandshake(database: string): Promise<Buffer | undefined> {
    this.currentPluginName = authPlugin.list[0];
    this.currentPlugin = createAuthPlugin(this.currentPluginName, this.options.password);
    this.clientAuthListSent = false;
    this.pendingServerKeys.length = 0;
    this.acceptedProtocolVersion = undefined;
    this.acceptedPacketType = wirePacketType.batchSend;
    this.inlineBlobs.clear();

    await this.writeConnect(database);

    while (true) {
      const operation = await this.readOperation();

      if (operation === wireOp.accept) {
        this.noteAcceptedProtocol(await this.readAcceptMessage(false));
        return this.currentPlugin.initialData;
      }

      if (operation === wireOp.acceptData || operation === wireOp.condAccept) {
        const accept = await this.readAcceptMessage(true);
        this.noteAcceptedProtocol(accept);
        this.recordServerKeys(accept.keys);
        const attachAuthData = accept.authenticated ? undefined : this.processAcceptPlugin(accept);

        if (operation === wireOp.condAccept && !accept.authenticated) {
          await this.writeContinueAuthentication(attachAuthData ?? Buffer.alloc(0));
          continue;
        }

        if (accept.authenticated) {
          await this.enableWireCryptIfAvailable();
        }

        return attachAuthData;
      }

      if (operation === wireOp.contAuth) {
        const authData = await this.readContinueAuthenticationMessage();
        this.recordServerKeys(authData.keys);
        const response = this.processAcceptPlugin(authData);
        await this.writeContinueAuthentication(response);
        continue;
      }

      if (operation === wireOp.response) {
        const response = await this.readResponse();
        assertSuccessfulResponse(response.status, 'Firebird connect failed');
        this.recordServerKeys(response.data);
        await this.enableWireCryptIfAvailable();
        return undefined;
      }

      if (operation === wireOp.reject) {
        throw new Error('Firebird server rejected all proposed wire protocols.');
      }

      throw new Error(`Unexpected operation ${operation} during connect handshake.`);
    }
  }

  private async executeAttachmentOperation(
    operation: number,
    database: string,
    baseDpb: Buffer,
    attachAuthData: Buffer | undefined,
    actionName: string,
  ): Promise<AttachmentHandle> {
    const dpb = buildAttachmentDpb(baseDpb, attachAuthData, this.currentPluginName);
    await this.writeAttachmentOperation(operation, database, dpb);

    while (true) {
      const responseOperation = await this.readOperation();
      if (responseOperation === wireOp.contAuth) {
        const authData = await this.readContinueAuthenticationMessage();
        this.recordServerKeys(authData.keys);
        const response = this.processAcceptPlugin(authData);
        await this.writeContinueAuthentication(response);
        continue;
      }

      if (responseOperation === wireOp.response) {
        const response = await this.readResponse();
        assertSuccessfulResponse(response.status, `Firebird ${actionName} failed`);
        this.recordServerKeys(response.data);
        await this.enableWireCryptIfAvailable();
        this.attachmentHandle = response.handle;
        return { handle: response.handle };
      }

      throw new Error(`Unexpected operation ${responseOperation} during ${actionName}.`);
    }
  }

  private processAcceptPlugin(message: AcceptMessage): Buffer {
    if (message.pluginName && message.pluginName !== this.currentPluginName) {
      if (!authPlugin.list.includes(message.pluginName as AuthPluginName)) {
        throw new Error(`Firebird requested unsupported authentication plugin ${message.pluginName}.`);
      }

      this.currentPluginName = message.pluginName as AuthPluginName;
      this.currentPlugin = createAuthPlugin(this.currentPluginName, this.options.password);
      this.clientAuthListSent = false;
    }

    if (!this.currentPlugin) {
      throw new Error('No authentication plugin is active.');
    }

    if (message.data.length === 0) {
      return this.currentPlugin.initialData;
    }

    return this.currentPlugin.continueAuthentication(
      normalizeLogin(this.options.username),
      this.options.password,
      message.data,
    );
  }

  private async writeContinueAuthentication(data: Buffer): Promise<void> {
    const writer = new XdrWriter();
    writer.writeInt32(wireOp.contAuth);
    writer.writeBuffer(data);
    writer.writeString(this.currentPluginName);
    writer.writeString(this.clientAuthListSent ? '' : buildRemainingPluginList(this.currentPluginName));
    writer.writeBuffer(Buffer.alloc(0));
    await this.channel!.write(writer.toBuffer());
    this.clientAuthListSent = true;
  }

  private recordServerKeys(keys: Buffer): void {
    if (keys.length > 0) {
      this.pendingServerKeys.push(Buffer.from(keys));
    }
  }

  private async enableWireCryptIfAvailable(): Promise<void> {
    if (this.wireCryptEnabled || !this.channel || !this.currentPlugin) {
      return;
    }

    const sessionKey = this.currentPlugin.getSessionKey();
    if (!sessionKey || this.pendingServerKeys.length === 0) {
      return;
    }

    const session = createWireCryptSession(this.pendingServerKeys, sessionKey);
    if (!session) {
      return;
    }

    const writer = new XdrWriter();
    writer.writeInt32(wireOp.crypt);
    writer.writeString(session.pluginName);
    writer.writeString(session.keyType);
    await this.channel.write(writer.toBuffer());

    this.channel.setTransforms({
      incoming: (buffer) => session.incoming.transform(buffer),
      outgoing: (buffer) => session.outgoing.transform(buffer),
    });

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while enabling wire encryption.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, 'Firebird wire encryption setup failed');
    this.pendingServerKeys.length = 0;
    this.wireCryptEnabled = true;
  }

  private concatInfoBuffers(buffers: readonly Buffer[]): Buffer {
    return Buffer.concat(
      buffers
        .filter((buffer) => buffer.length > 0)
        .map((buffer, index) =>
          index + 1 < buffers.length && buffer[buffer.length - 1] === commonInfo.end ? buffer.subarray(0, -1) : buffer,
        ),
    );
  }

  private async runEventLoop(): Promise<void> {
    try {
      while (this.eventChannel) {
        const operation = await this.readOperationFrom(this.eventChannel);

        if (operation === wireOp.event) {
          const event = await this.readEventMessage(this.eventChannel);
          await this.dispatchEvent(event);
          continue;
        }

        if (operation === wireOp.disconnect) {
          break;
        }

        throw new Error(`Unexpected operation ${operation} on the Firebird event channel.`);
      }
    } catch (error) {
      if (this.eventChannel) {
        throw error;
      }
    } finally {
      this.eventChannel = undefined;

      if (this.eventSocket) {
        const eventSocket = this.eventSocket;
        this.eventSocket = undefined;
        eventSocket.destroy();
      }
    }
  }

  private async dispatchEvent(event: EventMessage): Promise<void> {
    const subscription = this.eventSubscriptions.get(event.requestId);

    if (!subscription) {
      return;
    }

    const counters = calculateEventCounts(subscription.eventBuffer, event.items, subscription.names);
    subscription.eventBuffer = Buffer.from(event.items);

    if (this.eventSubscriptions.get(subscription.id) === subscription) {
      await this.runMainChannelTask(async () => {
        if (this.eventSubscriptions.get(subscription.id) !== subscription) {
          return;
        }

        await this.sendQueueEvents(subscription);
      });
    }

    await subscription.callback(counters);
  }

  findInlineBlob(transactionHandle: number, blobId: Uint8Array): InlineBlobResponse | undefined {
    return this.inlineBlobs.get(this.inlineBlobKey(transactionHandle, blobId));
  }

  private getSystemUserName(): string {
    try {
      return userInfo().username ?? 'node-firebird-driver-wire';
    } catch {
      return 'node-firebird-driver-wire';
    }
  }

  private async readOperation(): Promise<number> {
    return await this.readOperationFrom(this.channel!);
  }

  private async readOperationWithInlineBlobs(): Promise<number> {
    while (true) {
      const operation = await this.readOperation();
      if (operation !== wireOp.inlineBlob) {
        return operation;
      }

      this.storeInlineBlob(await this.readInlineBlobResponse());
    }
  }

  private async sendQueueEvents(subscription: EventSubscription): Promise<void> {
    const writer = new XdrWriter();
    writer.writeInt32(wireOp.queEvents);
    writer.writeInt32(0);
    writer.writeBuffer(subscription.eventBuffer);
    writer.writeInt32(0);
    writer.writeInt32(0);
    writer.writeInt32(subscription.id);
    await this.channel!.write(writer.toBuffer());

    const operation = await this.readOperation();
    if (operation !== wireOp.response) {
      throw new Error(`Unexpected operation ${operation} while queueing events.`);
    }

    const response = await this.readResponse();
    assertSuccessfulResponse(response.status, 'Firebird queue events failed');
  }

  private async readOperationFrom(channel: SocketChannel): Promise<number> {
    while (true) {
      const operationBuffer = await channel.readExactly(4);
      const operation = operationBuffer.readInt32BE(0);
      if (operation !== wireOp.dummy) {
        return operation;
      }
    }
  }

  private async readAcceptMessage(withAuthenticationData: boolean): Promise<AcceptMessage> {
    const protocolVersion = (await this.channel!.readExactly(4)).readInt32BE(0);
    const architecture = (await this.channel!.readExactly(4)).readInt32BE(0);
    const packetType = (await this.channel!.readExactly(4)).readInt32BE(0);

    if (!withAuthenticationData) {
      return {
        protocolVersion,
        architecture,
        packetType,
        authenticated: false,
        pluginName: '',
        data: Buffer.alloc(0),
        keys: Buffer.alloc(0),
      };
    }

    const data = await this.readXdrBuffer();
    const pluginName = await this.readXdrString();
    const authenticated = (await this.channel!.readExactly(4)).readInt32BE(0) === 1;
    const keys = await this.readXdrBuffer();

    return { protocolVersion, architecture, packetType, authenticated, pluginName, data, keys };
  }

  private async readContinueAuthenticationMessage(): Promise<AcceptMessage> {
    const data = await this.readXdrBuffer();
    const pluginName = await this.readXdrString();
    await this.readXdrString();
    const keys = await this.readXdrBuffer();

    return {
      protocolVersion: this.acceptedProtocolVersion ?? 0,
      architecture: wireProtocol.archGeneric,
      packetType: this.acceptedPacketType,
      authenticated: false,
      pluginName,
      data,
      keys,
    };
  }

  private async readResponse(): Promise<ResponseMessage> {
    return await this.readResponseFrom(this.channel!);
  }

  private async readEventMessage(channel: SocketChannel): Promise<EventMessage> {
    const database = (await channel.readExactly(4)).readInt32BE(0);
    const items = await this.readXdrBufferFrom(channel);
    await channel.readExactly(4);
    await channel.readExactly(4);
    const requestId = (await channel.readExactly(4)).readInt32BE(0);
    return { database, items, requestId };
  }

  private async readInlineBlobResponse(): Promise<InlineBlobResponse> {
    const transactionHandle = (await this.channel!.readExactly(4)).readInt32BE(0);
    const blobId = await this.channel!.readExactly(8);
    const info = await this.readXdrBuffer();
    const data = await this.readXdrBuffer();

    return { transactionHandle, blobId, info, data };
  }

  private async readXdrBuffer(): Promise<Buffer> {
    return await this.readXdrBufferFrom(this.channel!);
  }

  private async readXdrBufferFrom(channel: SocketChannel): Promise<Buffer> {
    const length = (await channel.readExactly(4)).readInt32BE(0);
    if (length === 0) {
      return Buffer.alloc(0);
    }
    const padded = await channel.readExactly(length + ((4 - (length % 4)) & 3));
    return padded.subarray(0, length);
  }

  private async readXdrString(): Promise<string> {
    return (await this.readXdrBuffer()).toString('utf8');
  }

  private async readResponseFrom(channel: SocketChannel): Promise<ResponseMessage> {
    const handle = (await channel.readExactly(4)).readInt32BE(0);
    const quad = await channel.readExactly(8);
    const objectId = quad.readBigInt64BE(0);
    const data = await this.readXdrBufferFrom(channel);
    const status = parseStatusVector(await this.readStatusVectorBufferFrom(channel));
    return { handle, objectId, quad, data, status };
  }

  private async readStatusVectorBufferFrom(channel: SocketChannel): Promise<Buffer> {
    const chunks: Buffer[] = [];
    while (true) {
      const tagChunk = await channel.readExactly(4);
      const tag = tagChunk.readInt32BE(0);
      chunks.push(tagChunk);
      if (tag === 0) {
        break;
      }

      const valueChunk = await channel.readExactly(4);
      chunks.push(valueChunk);
      if (tag === 2 || tag === 3 || tag === 5) {
        const length = valueChunk.readInt32BE(0);
        if (length > 0) {
          const paddedLength = length + ((4 - (length % 4)) & 3);
          const valueBuffer = await channel.readExactly(paddedLength);
          chunks.push(valueBuffer.subarray(0, length));
        }
      }
    }
    return Buffer.concat(chunks);
  }

  private supportsProtocol(version: number): boolean {
    return (this.acceptedProtocolVersion ?? 0) >= version;
  }

  private noteAcceptedProtocol(accept: AcceptMessage): void {
    this.acceptedProtocolVersion =
      accept.protocolVersion < 0 ? accept.protocolVersion & 0xffff : accept.protocolVersion;
    this.acceptedPacketType = accept.packetType & 0xff;
  }

  private storeInlineBlob(blob: InlineBlobResponse): void {
    this.inlineBlobs.set(this.inlineBlobKey(blob.transactionHandle, blob.blobId), blob);
  }

  private clearInlineBlobsForTransaction(transactionHandle: number): void {
    const prefix = `${transactionHandle}:`;

    for (const key of this.inlineBlobs.keys()) {
      if (key.startsWith(prefix)) {
        this.inlineBlobs.delete(key);
      }
    }
  }

  private inlineBlobKey(transactionHandle: number, blobId: Uint8Array): string {
    return `${transactionHandle}:${Buffer.from(blobId).toString('hex')}`;
  }
}
