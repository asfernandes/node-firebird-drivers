import { BlobStreamImpl } from './blob';
import { ClientImpl } from './client';
import { StatementImpl } from './statement';
import { TransactionImpl } from './transaction';
import { EventsImpl } from './events';
import { createDpb } from './fb-util';

import {
  Blob,
  ConnectOptions,
  CreateBlobOptions,
  CreateDatabaseOptions,
  PrepareOptions,
  TransactionOptions,
} from 'node-firebird-driver';

import { AbstractAttachment, cancelType } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';

function escapeSqlString(value: string): string {
  return value.replace(/'/g, "''");
}

function assertSafeIdentifier(value: string, optionName: string): string {
  if (!/^[A-Za-z_][A-Za-z0-9_]*$/.test(value)) {
    throw new Error(`Invalid ${optionName}: ${value}`);
  }
  return value;
}

/**
 * Builds a `CREATE DATABASE` SQL statement for IUtil::executeCreateDatabase.
 * The DPB-based creation API (isc_dpb_*) has no way to set a database's default
 * character set/collation, so this is the only path that can express it.
 */
function buildCreateDatabaseStatement(uri: string, options: CreateDatabaseOptions): string {
  let stmt = `CREATE DATABASE '${escapeSqlString(uri)}'`;

  if (options.username) {
    stmt += ` USER '${escapeSqlString(options.username)}'`;
  }
  if (options.password) {
    stmt += ` PASSWORD '${escapeSqlString(options.password)}'`;
  }
  if (options.pageSize) {
    stmt += ` PAGE_SIZE ${Number(options.pageSize)}`;
  }
  stmt += ` DEFAULT CHARACTER SET ${assertSafeIdentifier(options.defaultCharSet!, 'defaultCharSet')}`;
  if (options.defaultCollation) {
    stmt += ` COLLATION ${assertSafeIdentifier(options.defaultCollation, 'defaultCollation')}`;
  }

  return stmt;
}

/** Attachment implementation. */
export class AttachmentImpl extends AbstractAttachment {
  // Override declarations.
  declare client: ClientImpl;

  attachmentHandle?: fb.Attachment;

  static async connect(client: ClientImpl, uri: string, options?: ConnectOptions): Promise<AttachmentImpl> {
    const attachment = new AttachmentImpl(client);
    attachment.charSetForNONE = options?.charSetForNONE ?? 'utf8';

    return await client.statusAction(async (status) => {
      const dpb = createDpb(options);
      attachment.attachmentHandle = await client!.dispatcher!.attachDatabaseAsync(status, uri, dpb.length, dpb);
      return attachment;
    });
  }

  static async createDatabase(
    client: ClientImpl,
    uri: string,
    options?: CreateDatabaseOptions,
  ): Promise<AttachmentImpl> {
    const attachment = new AttachmentImpl(client);
    attachment.charSetForNONE = options?.charSetForNONE ?? 'utf8';

    if (options?.defaultCharSet) {
      // Only take this path when defaultCharSet is explicitly requested, rather than always
      // creating databases through executeCreateDatabase: that API takes a bare SQL statement
      // with no DPB, so forcedWrite/role/setDatabaseReadWriteMode (DPB-only, no CREATE DATABASE
      // clause exists for them) would silently stop working for every caller below.
      const stmt = buildCreateDatabaseStatement(uri, options);

      return await client.statusAction(async (status) => {
        attachment.attachmentHandle = await client!.util!.executeCreateDatabaseAsync(
          status,
          Buffer.byteLength(stmt, 'utf8'),
          stmt,
          3,
          undefined,
        );
        return attachment;
      });
    }

    return await client.statusAction(async (status) => {
      const dpb = createDpb(options);
      attachment.attachmentHandle = await client!.dispatcher!.createDatabaseAsync(status, uri, dpb.length, dpb);
      return attachment;
    });
  }

  /** Disconnects this attachment. */
  protected async internalDisconnect(): Promise<void> {
    await this.client.statusAction((status) => this.attachmentHandle!.detachAsync(status));
    this.attachmentHandle = undefined;
  }

  /** Drops the database and release this attachment. */
  protected async internalDropDatabase(): Promise<void> {
    await this.client.statusAction((status) => this.attachmentHandle!.dropDatabaseAsync(status));
    this.attachmentHandle = undefined;
  }

  /** Enable/disable cancellation of operations in this attachment. */
  protected async internalEnableCancellation(enable: boolean): Promise<void> {
    await this.client.statusAction((status) =>
      this.attachmentHandle!.cancelOperationAsync(status, enable ? cancelType.enable : cancelType.disable),
    );
  }

  /** Cancel a running operation in this attachment. */
  protected async internalCancelOperation(forcibleAbort: boolean): Promise<void> {
    await this.client.statusAction((status) =>
      this.attachmentHandle!.cancelOperationAsync(status, forcibleAbort ? cancelType.abort : cancelType.raise),
    );
  }

  /** Starts a new transaction. */
  protected async internalStartTransaction(options?: TransactionOptions): Promise<TransactionImpl> {
    return await TransactionImpl.start(this, options);
  }

  protected async internalCreateBlob(
    transaction: TransactionImpl,
    options?: CreateBlobOptions,
  ): Promise<BlobStreamImpl> {
    return await BlobStreamImpl.create(this, transaction, options);
  }

  protected async internalOpenBlob(transaction: TransactionImpl, blob: Blob): Promise<BlobStreamImpl> {
    return await BlobStreamImpl.open(this, transaction, blob);
  }

  /** Prepares a query. */
  protected async internalPrepare(
    transaction: TransactionImpl,
    sqlStmt: string,
    options?: PrepareOptions,
  ): Promise<StatementImpl> {
    return await StatementImpl.prepare(this, transaction, sqlStmt, options);
  }

  protected async internalQueueEvents(
    names: string[],
    callBack: (counters: [string, number][]) => Promise<void>,
  ): Promise<EventsImpl> {
    return await EventsImpl.queue(this, names, callBack);
  }
}
