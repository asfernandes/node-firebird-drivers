import { AbstractAttachment } from './attachment';
import { AbstractResultSet } from './resultset';
import { AbstractTransaction } from './transaction';

import {
	ExecuteOptions,
	ExecuteQueryOptions,
	FetchOptions,
	Statement
} from '..';


/** AbstractStatement implementation. */
export abstract class AbstractStatement implements Statement {
	resultSet?: AbstractResultSet;

	abstract getExecPathText(): Promise<string | undefined>;

	/** Gets the query's result columns labels. Returns empty array for queries without result. */
	abstract get columnLabels(): Promise<string[]>

	/** When true, query result must be obtained with method executeQuery. */
	readonly hasResultSet: boolean;

	/** Default query's execute options. */
	defaultExecuteOptions: ExecuteOptions;

	/** Default query's executeQuery options. */
	defaultExecuteQueryOptions: ExecuteQueryOptions;

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;

	protected constructor(public attachment?: AbstractAttachment) {
	}

	/** Disposes this statement's resources. */
	async dispose(): Promise<void> {
		this.check();

		if (this.resultSet)
			await this.resultSet.close();

		await this.internalDispose();

		this.attachment!.statements.delete(this);
		this.attachment = undefined;
	}

	/** Executes a prepared statement that uses the SET TRANSACTION command. Returns the new transaction. */
	async executeTransaction(transaction: AbstractTransaction): Promise<AbstractTransaction> {
		this.check();

		//// TODO: check opened resultSet.
		return await this.internalExecuteTransaction(transaction);
	}

	/** Executes a prepared statement that has no result set. */
	async execute(transaction: AbstractTransaction, parameters?: any[], options?: ExecuteOptions): Promise<void> {
		this.check();

		//// TODO: check opened resultSet.
		await this.internalExecute(transaction, parameters,
			options || this.attachment!.defaultExecuteOptions || this.attachment!.client!.defaultExecuteOptions);
	}

	/** Executes a statement that returns a single record as [col1, col2, ..., colN]. */
	async executeSingleton(transaction: AbstractTransaction, parameters?: any[], options?: ExecuteOptions): Promise<any[]> {
		this.check();

		//// TODO: check opened resultSet.
		return await this.internalExecute(transaction, parameters,
			options || this.attachment!.defaultExecuteOptions || this.attachment!.client!.defaultExecuteOptions);
	}

	/** Executes a statement that returns a single record as an object. */
	async executeSingletonAsObject<T extends object>(transaction: AbstractTransaction, parameters?: any[],
			options?: ExecuteOptions): Promise<T> {
		this.check();

		const row = await this.executeSingleton(transaction, parameters, options);
		const cols = (await this?.columnLabels) || [];

		const obj = {} as T;

		// Loop on row column value.
		row.forEach((v: any, idx: number) => {
			const col = cols[idx];
			(obj as any)[col] = v;
		});

		return obj;
	}

	/** Executes a statement that returns a single record as [col1, col2, ..., colN]. */
	async executeReturning(transaction: AbstractTransaction, parameters?: any[], options?: ExecuteOptions): Promise<any[]> {
		return await this.executeSingleton(transaction, parameters, options);
	}

	/** Executes a statement that returns a single record as an object. */
	async executeReturningAsObject<T extends object>(transaction: AbstractTransaction, parameters?: any[],
			options?: ExecuteOptions): Promise<T> {
		return await this.executeSingletonAsObject<T>(transaction, parameters, options);
	}

	/** Executes a prepared statement that has result set. */
	async executeQuery(transaction: AbstractTransaction, parameters?: any[], options?: ExecuteQueryOptions):
			Promise<AbstractResultSet> {
		this.check();

		//// TODO: check opened resultSet.
		const resultSet = await this.internalExecuteQuery(transaction, parameters,
			options || this.attachment!.defaultExecuteQueryOptions || this.attachment!.client!.defaultExecuteQueryOptions);
		this.resultSet = resultSet;
		return resultSet;
	}

	get isValid(): boolean {
		return !!this.attachment;
	}

	private check() {
		if (!this.isValid)
			throw new Error('Statement is already disposed.');
	}

	public abstract setCursorName(cursorName: string): Promise<void>;

	protected abstract internalDispose(): Promise<void>;
	protected abstract internalExecuteTransaction(transaction: AbstractTransaction): Promise<AbstractTransaction>;
	protected abstract internalExecute(transaction: AbstractTransaction, parameters?: any[], options?: ExecuteOptions):
		Promise<any[]>;
	protected abstract internalExecuteQuery(transaction: AbstractTransaction, parameters?: any[], options?: ExecuteQueryOptions):
		Promise<AbstractResultSet>;
}
