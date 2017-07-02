import { AbstractClient } from './client';
import { AbstractResultSet } from './resultset';
import { AbstractStatement } from './statement';
import { AbstractTransaction } from './transaction';

import {
	Attachment,
	ExecuteOptions,
	ExecuteQueryOptions,
	FetchOptions,
	PrepareOptions,
	TransactionOptions
} from '..';


/** AbstractAttachment implementation. */
export abstract class AbstractAttachment implements Attachment {
	statements = new Set<AbstractStatement>();

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

	protected constructor(public client?: AbstractClient) {
	}

	/** Disconnects this attachment. */
	async disconnect(): Promise<void> {
		this.check();

		await this.internalDisconnect();
		await this.finishDispose();
	}

	/** Drops the database and release this attachment. */
	async dropDatabase(): Promise<void> {
		this.check();

		await this.internalDropDatabase();
		await this.finishDispose();
	}

	/** Executes a statement that uses the SET TRANSACTION command. Returns the new transaction. */
	async executeTransaction(transaction: AbstractTransaction, sqlStmt: string, prepareOptions?: PrepareOptions):
			Promise<AbstractTransaction> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, prepareOptions);
		try {
			return await statement.executeTransaction(transaction);
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that has no result set. */
	async execute(transaction: AbstractTransaction, sqlStmt: string, parameters?: Array<any>,
			prepareOptions?: PrepareOptions, executeOptions?: ExecuteOptions): Promise<void> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, prepareOptions);
		try {
			return await statement.execute(transaction, parameters, executeOptions);
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that has result set. */
	async executeQuery(transaction: AbstractTransaction, sqlStmt: string, parameters?: Array<any>,
			prepareOptions?: PrepareOptions, executeOptions?: ExecuteQueryOptions): Promise<AbstractResultSet> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, prepareOptions);
		try {
			const resultSet = await statement.executeQuery(transaction, parameters, executeOptions);
			resultSet.diposeStatementOnClose = true;
			return resultSet;
		}
		catch (e) {
			await statement.dispose();
			throw e;
		}
	}

	/** Starts a new transaction. */
	async startTransaction(options?: TransactionOptions): Promise<AbstractTransaction> {
		this.check();

		return await this.internalStartTransaction(options || this.defaultTransactionOptions || this.client!.defaultTransactionOptions);
	}

	/** Prepares a query. */
	async prepare(transaction: AbstractTransaction, sqlStmt: string, options?: PrepareOptions): Promise<AbstractStatement> {
		this.check();

		const statement = await this.internalPrepare(transaction, sqlStmt,
			options || this.defaultPrepareOptions || this.client!.defaultPrepareOptions);
		this.statements.add(statement);
		return statement;
	}

	private check() {
		if (!this.client)
			throw new Error('Attachment is already disconnected.');
	}

	private async finishDispose() {
		this.client!.attachments.delete(this);

		try {
			for (const statement of this.statements)
				await statement.dispose();
		}
		finally {
			this.statements.clear();
		}

		this.client = undefined;
	}

	protected abstract async internalDisconnect(): Promise<void>;
	protected abstract async internalDropDatabase(): Promise<void>;
	protected abstract async internalPrepare(transaction: AbstractTransaction, sqlStmt: string, options?: PrepareOptions):
		Promise<AbstractStatement>;
	protected abstract async internalStartTransaction(options?: TransactionOptions): Promise<AbstractTransaction>;
}
