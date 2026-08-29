import { BlobStreamImpl } from './blob';
import { ClientImpl } from './client';
import { parseDatabaseUri } from './database-uri';
import { EventsImpl } from './events';
import { createDpb } from './fb-util';
import { StatementImpl } from './statement';
import { TransactionImpl } from './transaction';

import {
  Blob,
  ConnectOptions,
  CreateBlobOptions,
  CreateDatabaseOptions,
  PrepareOptions,
  TransactionOptions,
} from 'node-firebird-driver';
import { AbstractAttachment, cancelType } from 'node-firebird-driver/dist/lib/impl';

import { AttachmentHandle, WireProtocol } from './wire-protocol';
export { parseDatabaseUri } from './database-uri';

export class AttachmentImpl extends AbstractAttachment {
  declare client: ClientImpl;
  protocol?: WireProtocol;
  attachmentHandle?: AttachmentHandle;

  private constructor(client: ClientImpl) {
    super(client);
  }

  static async connect(client: ClientImpl, uri: string, options?: ConnectOptions): Promise<AttachmentImpl> {
    return await AttachmentImpl.open(client, uri, options, false);
  }

  static async createDatabase(
    client: ClientImpl,
    uri: string,
    options?: CreateDatabaseOptions,
  ): Promise<AttachmentImpl> {
    return await AttachmentImpl.open(client, uri, options, true);
  }

  private static async open(
    client: ClientImpl,
    uri: string,
    options: ConnectOptions | CreateDatabaseOptions | undefined,
    createDatabase: boolean,
  ): Promise<AttachmentImpl> {
    const attachment = new AttachmentImpl(client);
    attachment.charSetForNONE = options?.charSetForNONE ?? 'utf8';

    const parsed = parseDatabaseUri(uri);
    const username = options?.username ?? process.env.ISC_USER ?? '';
    const password = options?.password ?? process.env.ISC_PASSWORD ?? '';

    attachment.protocol = new WireProtocol({
      host: parsed.host,
      port: parsed.port,
      username,
      password,
      timeoutMs: client.wireOptions.timeoutMs,
      statementTimeoutMs: client.wireOptions.statementTimeoutMs,
    });

    const dpb = createDpb(options);
    attachment.attachmentHandle = createDatabase
      ? await attachment.protocol.createDatabase(parsed.database, dpb)
      : await attachment.protocol.attach(parsed.database, dpb);

    return attachment;
  }

  protected override async internalDisconnect(): Promise<void> {
    try {
      await this.protocol!.detach(this.attachmentHandle!);
    } finally {
      await this.protocol!.close();
      this.protocol = undefined;
      this.attachmentHandle = undefined;
    }
  }

  protected override async internalDropDatabase(): Promise<void> {
    try {
      await this.protocol!.dropDatabase(this.attachmentHandle!);
    } finally {
      await this.protocol!.close();
      this.protocol = undefined;
      this.attachmentHandle = undefined;
    }
  }

  protected override async internalEnableCancellation(enable: boolean): Promise<void> {
    await this.protocol!.cancelOperation(enable ? cancelType.enable : cancelType.disable);
  }

  protected override async internalCancelOperation(forcibleAbort: boolean): Promise<void> {
    await this.protocol!.cancelOperation(forcibleAbort ? cancelType.abort : cancelType.raise);
  }

  protected override async internalStartTransaction(options?: TransactionOptions): Promise<TransactionImpl> {
    return await TransactionImpl.start(this, options);
  }

  protected override async internalCreateBlob(
    transaction: TransactionImpl,
    options?: CreateBlobOptions,
  ): Promise<BlobStreamImpl> {
    return await BlobStreamImpl.create(this, transaction, options);
  }

  protected override async internalOpenBlob(transaction: TransactionImpl, blob: Blob): Promise<BlobStreamImpl> {
    return await BlobStreamImpl.open(this, transaction, blob);
  }

  protected override async internalPrepare(
    transaction: TransactionImpl,
    sqlStmt: string,
    options?: PrepareOptions,
  ): Promise<StatementImpl> {
    return await StatementImpl.prepare(this, transaction, sqlStmt, options);
  }

  protected override async internalQueueEvents(
    names: string[],
    callBack: (counters: [string, number][]) => Promise<void>,
  ): Promise<EventsImpl> {
    return await EventsImpl.queue(this, names, callBack);
  }
}
