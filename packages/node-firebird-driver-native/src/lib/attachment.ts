import { ClientImpl } from './client';
import { StatementImpl } from './statement';
import { TransactionImpl } from './transaction';
import { createDpb } from './fb-util';

import {
	ConnectOptions,
	CreateDatabaseOptions,
	PrepareOptions,
	TransactionOptions
} from 'node-firebird-driver';

import { AbstractAttachment } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** Attachment implementation. */
export class AttachmentImpl extends AbstractAttachment {
	// Override declarations.
	client: ClientImpl;

	attachmentHandle: fb.Attachment;

	static async connect(client: ClientImpl, uri: string, options?: ConnectOptions): Promise<AttachmentImpl> {
		const attachment = new AttachmentImpl(client);

		return await client.statusAction(async status => {
			const dpb = createDpb(options);
			attachment.attachmentHandle = await client.dispatcher.attachDatabaseAsync(status, uri, dpb.length, dpb);
			return attachment;
		});
	}

	static async createDatabase(client: ClientImpl, uri: string, options?: CreateDatabaseOptions): Promise<AttachmentImpl> {
		const attachment = new AttachmentImpl(client);

		return await client.statusAction(async status => {
			const dpb = createDpb(options);
			attachment.attachmentHandle = await client.dispatcher.createDatabaseAsync(status, uri, dpb.length, dpb);
			return attachment;
		});
	}

	/** Disconnects this attachment. */
	protected async internalDisconnect(): Promise<void> {
		await this.client.statusAction(status => this.attachmentHandle.detachAsync(status));
		this.attachmentHandle = null;
	}

	/** Drops the database and release this attachment. */
	protected async internalDropDatabase(): Promise<void> {
		await this.client.statusAction(status => this.attachmentHandle.dropDatabaseAsync(status));
		this.attachmentHandle = null;
	}

	/** Starts a new transaction. */
	protected async internalStartTransaction(options?: TransactionOptions): Promise<TransactionImpl> {
		return await TransactionImpl.start(this, options);
	}

	/** Prepares a query. */
	protected async internalPrepare(transaction: TransactionImpl, sqlStmt: string, options?: PrepareOptions): Promise<StatementImpl> {
		return await StatementImpl.prepare(this, transaction, sqlStmt, options);
	}
}
