import { AbstractBlobStream } from './blob';
import { AbstractClient } from './client';
import { AbstractResultSet } from './resultset';
import { AbstractStatement } from './statement';
import { AbstractTransaction } from './transaction';
import { AbstractEvents } from './events';

import {
	Attachment,
	Blob,
	ExecuteOptions,
	ExecuteQueryOptions,
	Events,
	FetchOptions,
	PrepareOptions,
	TransactionOptions,
	Parameters
} from '..';
import { parseParams } from './parser';

const adjustPrepareOptions = (prepareOptions?: PrepareOptions, parameters?: Parameters) =>
	parameters && !Array.isArray(parameters) && !prepareOptions ? { namedParams: true } : prepareOptions;

/** AbstractAttachment implementation. */
export abstract class AbstractAttachment implements Attachment {
	events = new Set<Events>();
	statements = new Set<AbstractStatement>();
	transactions = new Set<AbstractTransaction>();

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

		await this.preDispose();
		await this.internalDisconnect();
		await this.postDispose();
	}

	/** Drops the database and release this attachment. */
	async dropDatabase(): Promise<void> {
		this.check();

		await this.preDispose();
		await this.internalDropDatabase();
		await this.postDispose();
	}

	/** Executes a statement that uses the SET TRANSACTION command. Returns the new transaction. */
	async executeTransaction(transaction: AbstractTransaction, sqlStmt: string,
			options?: {
				prepareOptions?: PrepareOptions
			}): Promise<AbstractTransaction> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, options && options.prepareOptions);
		try {
			const newTransaction = await statement.executeTransaction(transaction);
			this.transactions.add(newTransaction);
			return newTransaction;
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that has no result set. */
	async execute(transaction: AbstractTransaction, sqlStmt: string, parameters?: Parameters,
			options?: {
				prepareOptions?: PrepareOptions,
				executeOptions?: ExecuteOptions
			}): Promise<void> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, adjustPrepareOptions(options?.prepareOptions, parameters));
		try {
			return await statement.execute(transaction, parameters, options?.executeOptions);
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that returns a single record. */
	async executeSingleton(transaction: AbstractTransaction, sqlStmt: string, parameters?: Parameters,
			options?: {
				prepareOptions?: PrepareOptions,
				executeOptions?: ExecuteOptions
			}): Promise<Array<any>> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, adjustPrepareOptions(options?.prepareOptions, parameters));
		try {
			return await statement.executeSingleton(transaction, parameters, options && options.executeOptions);
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that returns a single record in object form. */
	async executeSingletonAsObject<T extends object>(transaction: AbstractTransaction, sqlStmt: string, parameters?: Parameters,
			options?: {
				prepareOptions?: PrepareOptions,
				executeOptions?: ExecuteOptions
			}): Promise<T> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, adjustPrepareOptions(options?.prepareOptions, parameters));
		try {
			return await statement.executeSingletonAsObject(transaction, parameters, options && options.executeOptions);
		}
		finally {
			await statement.dispose();
		}
	}

	/** Executes a statement that returns a single record. */
	async executeReturning(transaction: AbstractTransaction, sqlStmt: string, parameters?: Parameters,
			options?: {
				prepareOptions?: PrepareOptions,
				executeOptions?: ExecuteOptions
			}): Promise<Array<any>> {
		return await this.executeSingleton(transaction, sqlStmt, parameters, options);
	}

	/** Executes a statement that returns a single record in object form. */
	async executeReturningAsObject<T extends object>(transaction: AbstractTransaction, sqlStmt: string, parameters?: Parameters,
			options?: {
				prepareOptions?: PrepareOptions,
				executeOptions?: ExecuteOptions
			}): Promise<T> {
		return await this.executeSingletonAsObject<T>(transaction, sqlStmt, parameters, options);
	}

	/** Executes a statement that has result set. */
	async executeQuery(transaction: AbstractTransaction, sqlStmt: string, parameters?: Parameters,
			options?: {
				prepareOptions?: PrepareOptions,
				executeOptions?: ExecuteQueryOptions
			}): Promise<AbstractResultSet> {
		this.check();

		const statement = await this.prepare(transaction, sqlStmt, adjustPrepareOptions(options?.prepareOptions, parameters));
		try {
			const resultSet = await statement.executeQuery(transaction, parameters, options?.executeOptions);
			resultSet.diposeStatementOnClose = true;
			return resultSet;
		}
		catch (e) {
			await statement.dispose();
			throw e;
		}
	}

	async queueEvents(names: string[], callBack: (counters: [string, number][]) => Promise<void>): Promise<Events> {
		this.check();

		const trimmedNames = names.map(name => {
			const trimmedName = name.trimRight();

			if (Buffer.from(trimmedName).byteLength > 255)
				throw new Error(`Invalid event name: ${name}.`);

			return trimmedName;
		});

		const events = await this.internalQueueEvents(trimmedNames, callBack);
		this.events.add(events);

		return events;
	}

	async createBlob(transaction: AbstractTransaction): Promise<AbstractBlobStream> {
		return await this.internalCreateBlob(transaction);
	}

	async openBlob(transaction: AbstractTransaction, blob: Blob): Promise<AbstractBlobStream> {
		return await this.internalOpenBlob(transaction, blob);
	}

	/** Starts a new transaction. */
	async startTransaction(options?: TransactionOptions): Promise<AbstractTransaction> {
		this.check();

		const transaction = await this.internalStartTransaction(
			options || this.defaultTransactionOptions || this.client!.defaultTransactionOptions);
		this.transactions.add(transaction);
		return transaction;
	}

	/** Prepares a query. */
	async prepare(transaction: AbstractTransaction, sqlStmt: string, options?: PrepareOptions): Promise<AbstractStatement> {
		this.check();

		const parsed = options?.namedParams ? parseParams(sqlStmt) : undefined;

		const statement = await this.internalPrepare(transaction, parsed ? parsed.sqlStmt : sqlStmt,
			options || this.defaultPrepareOptions || this.client!.defaultPrepareOptions);

		if (parsed?.paramNames) {
			statement.paramNames = parsed.paramNames;
		}

		this.statements.add(statement);
		return statement;
	}

	get isValid(): boolean {
		return !!this.client;
	}

	private check() {
		if (!this.isValid)
			throw new Error('Attachment is already disconnected.');
	}

	private async preDispose() {
		try {
			await Promise.all(Array.from(this.events).map(events => events.cancel()));
			await Promise.all(Array.from(this.statements).map(statement => statement.dispose()));
			await Promise.all(Array.from(this.transactions).map(transaction => transaction.rollback()));
		}
		finally {
			this.events.clear();
			this.statements.clear();
			this.transactions.clear();
		}
	}

	private async postDispose() {
		this.client!.attachments.delete(this);
		this.client = undefined;
	}

	protected abstract internalDisconnect(): Promise<void>;
	protected abstract internalDropDatabase(): Promise<void>;
	protected abstract internalCreateBlob(transaction: AbstractTransaction): Promise<AbstractBlobStream>;
	protected abstract internalOpenBlob(transaction: AbstractTransaction, blob: Blob): Promise<AbstractBlobStream>;
	protected abstract internalPrepare(transaction: AbstractTransaction, sqlStmt: string, options?: PrepareOptions):
		Promise<AbstractStatement>;
	protected abstract internalStartTransaction(options?: TransactionOptions): Promise<AbstractTransaction>;
	protected abstract internalQueueEvents(names: string[], callBack: (counters: [string, number][]) => Promise<void>):
		Promise<AbstractEvents>;
}
