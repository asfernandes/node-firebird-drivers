import { AttachmentImpl } from './attachment';

import { Client, ConnectOptions, CreateDatabaseOptions } from 'node-firebird-driver';
import { AbstractClient } from 'node-firebird-driver/dist/lib/impl';

export interface WireClientOptions {
  readonly timeoutMs?: number;
  readonly statementTimeoutMs?: number;
}

export function createWireClient(options?: WireClientOptions): Client {
  return new ClientImpl(options);
}

export class ClientImpl extends AbstractClient {
  constructor(readonly wireOptions: WireClientOptions = {}) {
    super();
  }

  protected override async internalConnect(uri: string, options?: ConnectOptions): Promise<AttachmentImpl> {
    return await AttachmentImpl.connect(this, uri, options);
  }

  protected override async internalCreateDatabase(
    uri: string,
    options?: CreateDatabaseOptions,
  ): Promise<AttachmentImpl> {
    return await AttachmentImpl.createDatabase(this, uri, options);
  }

  protected override async internalDispose(): Promise<void> {
    return await Promise.resolve();
  }
}
