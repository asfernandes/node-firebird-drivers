import { AbstractAttachment } from './attachment';

import {
	Client,
	ConnectOptions,
	CreateDatabaseOptions,
	ExecuteOptions,
	ExecuteQueryOptions,
	FetchOptions,
	PrepareOptions,
	TransactionOptions
} from '..';


/** AbstractClient implementation. */
export abstract class AbstractClient implements Client {
	attachments = new Set<AbstractAttachment>();

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

	/** Disposes this client's resources. */
	async dispose(): Promise<void> {
		try {
			for (const attachment of this.attachments)
				await attachment.disconnect();
		}
		finally {
			this.attachments.clear();
		}

		await this.internalDispose();
	}

	/** Connects to a database. */
	async connect(uri: string, options?: ConnectOptions): Promise<AbstractAttachment> {
		const attachment = await this.internalConnect(uri, options || this.defaultConnectOptions);
		this.attachments.add(attachment);
		return attachment;
	}

	/** Creates a database. */
	async createDatabase(uri: string, options?: CreateDatabaseOptions): Promise<AbstractAttachment> {
		const attachment = await this.internalCreateDatabase(uri, options || this.defaultCreateDatabaseOptions);
		this.attachments.add(attachment);
		return attachment;
	}

	protected abstract async internalDispose(): Promise<void>;
	protected abstract async internalConnect(uri: string, options?: ConnectOptions): Promise<AbstractAttachment>;
	protected abstract async internalCreateDatabase(uri: string, options?: CreateDatabaseOptions): Promise<AbstractAttachment>;
}
