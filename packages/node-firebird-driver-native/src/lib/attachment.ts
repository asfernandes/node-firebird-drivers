import { ClientImpl } from './client';
import { ResultSetImpl } from './resultset';
import { StatementImpl } from './statement';
import { TransactionImpl } from './transaction';
import { createDpb } from './fb-util';

import {
	Attachment,
	ConnectOptions,
	CreateDatabaseOptions,
	ExecuteOptions,
	ExecuteQueryOptions,
	FetchOptions,
	PrepareOptions,
	ResultSet,
	Statement,
	Transaction,
	TransactionOptions
} from 'node-firebird-driver';

import * as fb from 'node-firebird-native-api';


/** Attachment implementation. */
export class AttachmentImpl implements Attachment {
	attachment: fb.Attachment;
	statements = new Set<StatementImpl>();

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

	static async connect(client: ClientImpl, uri: string, options?: ConnectOptions): Promise<AttachmentImpl> {
		const attachment = new AttachmentImpl(client);

		return await client.statusAction(async status => {
			const dpb = createDpb(options || client.defaultConnectOptions);
			attachment.attachment = await client.dispatcher.attachDatabaseAsync(status, uri, dpb.length, dpb);
			client.attachments.add(attachment);
			return attachment;
		});
	}

	static async createDatabase(client: ClientImpl, uri: string, options?: CreateDatabaseOptions): Promise<AttachmentImpl> {
		const attachment = new AttachmentImpl(client);

		return await client.statusAction(async status => {
			const dpb = createDpb(options || client.defaultCreateDatabaseOptions);
			attachment.attachment = await client.dispatcher.createDatabaseAsync(status, uri, dpb.length, dpb);
			client.attachments.add(attachment);
			return attachment;
		});
	}

	private constructor(public client: ClientImpl) {
	}

	/** Disconnects this attachment. */
	async disconnect(): Promise<void> {
		await this.client.statusAction(status => this.attachment.detachAsync(status));
		await this.finishDispose();
	}

	/** Drops the database and release this attachment. */
	async dropDatabase(): Promise<void> {
		await this.client.statusAction(status => this.attachment.dropDatabaseAsync(status));
		await this.finishDispose();
	}

	/** Starts a new transaction. */
	async startTransaction(options?: TransactionOptions): Promise<Transaction> {
		return await TransactionImpl.start(this, options);
	}

	/** Prepares a query. */
	async prepare(transaction: Transaction, sqlStmt: string, options?: PrepareOptions): Promise<Statement> {
		return await StatementImpl.prepare(this, transaction as TransactionImpl, sqlStmt, options);
	}

	/** Executes a statement that uses the SET TRANSACTION command. Returns the new transaction. */
	async executeTransaction(transaction: Transaction, sqlStmt: string, prepareOptions?: PrepareOptions): Promise<Transaction> {
		const statement = await this.prepare(transaction, sqlStmt, prepareOptions);
		try {
			return await statement.executeTransaction(transaction);
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that has no result set. */
	async execute(transaction: Transaction, sqlStmt: string, parameters?: Array<any>,
			prepareOptions?: PrepareOptions, executeOptions?: ExecuteOptions): Promise<void> {
		const statement = await this.prepare(transaction, sqlStmt, prepareOptions);
		try {
			return await statement.execute(transaction, parameters, executeOptions);
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that has result set. */
	async executeQuery(transaction: Transaction, sqlStmt: string, parameters?: Array<any>,
			prepareOptions?: PrepareOptions, executeOptions?: ExecuteQueryOptions): Promise<ResultSet> {
		const statement = await this.prepare(transaction, sqlStmt, prepareOptions);
		try {
			const resultSet = await statement.executeQuery(transaction, parameters, executeOptions) as ResultSetImpl;
			resultSet.diposeStatementOnClose = true;
			return resultSet;
		}
		catch (e) {
			await statement.dispose();
			throw e;
		}
	}

	private async finishDispose() {
		this.client.attachments.delete(this);

		try {
			for (const statement of this.statements)
				await statement.dispose();
		}
		finally {
			this.statements.clear();
		}

		this.attachment = null;
		this.client = null;
	}
}
