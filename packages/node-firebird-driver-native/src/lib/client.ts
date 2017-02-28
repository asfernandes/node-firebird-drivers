import { AttachmentImpl } from './attachment';

import {
	Attachment,
	Client,
	ConnectOptions,
	CreateDatabaseOptions,
	ExecuteOptions,
	ExecuteQueryOptions,
	FetchOptions,
	PrepareOptions,
	TransactionOptions
} from 'node-firebird-driver';

import * as fb from 'node-firebird-native-api';

import * as os from 'os';


/** Gets the default platform Firebird client library filename. */
export function getDefaultLibraryFilename(): string {
	return os.platform() == 'win32' ? 'fbclient.dll' : 'libfbclient.so';
}

/** Creates a client for a given library filename. */
export function createNativeClient(library: string): Client {
	return new ClientImpl(library);
}


/** Client implementation. */
export class ClientImpl implements Client {
	master: fb.Master;
	dispatcher: fb.Provider;
	util: fb.Util;
	attachments = new Set<AttachmentImpl>();

	/** Default connect options. */
	defaultConnectOptions: ConnectOptions;

	/** Set default create database options. */
	defaultCreateDatabaseOptions: CreateDatabaseOptions;

	/** Default transaction options. */
	defaultTransactionOptions: TransactionOptions;

	/** Default query's prepare options. */
	defaultPrepareOptions: PrepareOptions;

	/** Default query's execute options. */
	defaultExecuteOptions: ExecuteOptions;

	/** Default query's executeQuery options. */
	defaultExecuteQueryOptions: ExecuteQueryOptions;

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;

	constructor(library: string) {
		this.master = fb.getMaster(library);
		this.dispatcher = this.master.getDispatcherSync();
		this.util = this.master.getUtilInterfaceSync();
	}

	async statusAction<T>(action: (status: fb.Status) => Promise<T>): Promise<T> {
		const status = this.master.getStatusSync();
		try {
			return await action(status);
		}
		finally {
			status.disposeSync();
		}
	}

	/** Disposes this client's resources. */
	async dispose(): Promise<void> {
		try {
			for (const attachment of this.attachments)
				await attachment.disconnect();
		}
		finally {
			this.attachments.clear();
		}

		await this.statusAction(async status => {
			const fb_shutrsn_app_stopped = -3;
			await this.dispatcher.shutdownAsync(status, 0, fb_shutrsn_app_stopped);
		});

		this.dispatcher.releaseSync();
		fb.disposeMaster(this.master);

		this.dispatcher = null;
		this.master = null;

		return await null;
	}

	/** Connects to a database. */
	async connect(uri: string, options?: ConnectOptions): Promise<Attachment> {
		return await AttachmentImpl.connect(this, uri, options);
	}

	/** Creates a database. */
	async createDatabase(uri: string, options?: CreateDatabaseOptions): Promise<Attachment> {
		return await AttachmentImpl.createDatabase(this, uri, options);
	}
}
