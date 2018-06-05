import { AttachmentImpl } from './attachment';

import {
	Client,
	ConnectOptions,
	CreateDatabaseOptions
} from 'node-firebird-driver';

import { AbstractClient } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** Gets the default platform Firebird client library filename. */
export { getDefaultLibraryFilename } from 'node-firebird-native-api';

/** Creates a client for a given library filename. */
export function createNativeClient(library: string): Client {
	return new ClientImpl(library);
}


/** Client implementation. */
export class ClientImpl extends AbstractClient {
	master?: fb.Master;
	dispatcher?: fb.Provider;
	util?: fb.Util;

	constructor(library: string) {
		super();
		this.master = fb.getMaster(library);
		this.dispatcher = this.master.getDispatcherSync();
		this.util = this.master.getUtilInterfaceSync();
	}

	async statusAction<T>(action: (status: fb.Status) => Promise<T>): Promise<T> {
		const status = this.master!.getStatusSync()!;
		try {
			return await action(status);
		}
		finally {
			status.disposeSync();
		}
	}

	/** Connects to a database. */
	protected async internalConnect(uri: string, options?: ConnectOptions): Promise<AttachmentImpl> {
		return await AttachmentImpl.connect(this, uri, options);
	}

	/** Creates a database. */
	protected async internalCreateDatabase(uri: string, options?: CreateDatabaseOptions): Promise<AttachmentImpl> {
		return await AttachmentImpl.createDatabase(this, uri, options);
	}

	/** Disposes this client's resources. */
	protected async internalDispose(): Promise<void> {
		this.dispatcher!.releaseSync();
		fb.disposeMaster(this.master!);

		this.util = undefined;
		this.dispatcher = undefined;
		this.master = undefined;
	}
}
