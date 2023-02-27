/** Client interface. */
export interface Client {
	/** Disposes this client's resources. */
	dispose(): Promise<void>;

	/** Connects to a database. */
	connect(uri: string, options?: ConnectOptions): Promise<Attachment>;

	/** Creates a database. */
	createDatabase(uri: string, options?: CreateDatabaseOptions): Promise<Attachment>;

	/** True if the client has not been disposed. */
	readonly isValid: boolean;

	/** Default connect options. */
	defaultConnectOptions?: ConnectOptions;

	/** Default create database options. */
	defaultCreateDatabaseOptions?: CreateDatabaseOptions;

	/** Default transaction options. */
	defaultTransactionOptions?: TransactionOptions;

	/** Default query's prepare options. */
	defaultPrepareOptions?: PrepareOptions;

	/** Default query's execute options. */
	defaultExecuteOptions?: ExecuteOptions;

	/** Default query's executeQuery options. */
	defaultExecuteQueryOptions?: ExecuteQueryOptions;

	/** Default result set's fetch options. */
	defaultFetchOptions?: FetchOptions;
}

/** ConnectOptions interface. */
export interface ConnectOptions {
	/** User name. */
	username?: string;

	/** User password. */
	password?: string;

	/** User role. */
	role?: string;
}

/** CreateDatabaseOptions interface. */
export interface CreateDatabaseOptions extends ConnectOptions {
	/** Forced write. */
	forcedWrite?: boolean;
}

/** TransactionIsolation enum */
export enum TransactionIsolation {
	CONSISTENCY = 'CONSISTENCY',
	READ_COMMITTED = 'READ_COMMITTED',
	SNAPSHOT = 'SNAPSHOT'
}

/** TransactionOptions interface. */
export interface TransactionOptions {
	isolation?: TransactionIsolation;
	readCommittedMode?: 'NO_RECORD_VERSION' | 'RECORD_VERSION';
	accessMode?: 'READ_ONLY' | 'READ_WRITE';
	waitMode?: 'NO_WAIT' | 'WAIT';
	noAutoUndo?: boolean;
	ignoreLimbo?: boolean;
	restartRequests?: boolean;
	autoCommit?: boolean;
	//// TODO: lockTimeOut?: number;
}

/** PrepareOptions interface. */
export interface PrepareOptions {
}

/** ExecuteOptions interface. */
export interface ExecuteOptions {
}

/** ExecuteQueryOptions interface. */
export interface ExecuteQueryOptions extends ExecuteOptions {
}

/** FetchOptions interface. */
export interface FetchOptions {
	/** Number of rows to fetch. */
	fetchSize?: number;
}

/** CreateBlobOptions interface. */
export interface CreateBlobOptions {
	type?: 'SEGMENTED' | 'STREAM';
}

/** Attachment interface. */
export interface Attachment {
	/** Disconnects this attachment. */
	disconnect(): Promise<void>;

	/** Enable/disable cancellation of operations in this attachment. */
	enableCancellation(enable: boolean): Promise<void>;

	/** Cancel a running operation in this attachment. */
	cancelOperation(forcibleAbort?: boolean): Promise<void>;

	/** Drops the database and release this attachment. */
	dropDatabase(): Promise<void>;

	/** Creates a blob and return its stream. */
	createBlob(transaction: Transaction, options?: CreateBlobOptions): Promise<BlobStream>;

	/** Opens a blob's stream. */
	openBlob(transaction: Transaction, blob: Blob): Promise<BlobStream>;

	/** Starts a new transaction. */
	startTransaction(options?: TransactionOptions): Promise<Transaction>;

	/** Prepares a query. */
	prepare(transaction: Transaction, sqlStmt: string, options?: PrepareOptions): Promise<Statement>;

	/** Executes a statement that uses the SET TRANSACTION command. Returns the new transaction. */
	executeTransaction(transaction: Transaction, sqlStmt: string,
		options?: {
			prepareOptions?: PrepareOptions
		}): Promise<Transaction>;

	/** Executes a statement that has no result set. */
	execute(transaction: Transaction, sqlStmt: string, parameters?: any[],
		options?: {
			prepareOptions?: PrepareOptions,
			executeOptions?: ExecuteOptions
		}): Promise<void>;

	/** Executes a statement that returns a single record as [col1, col2, ..., colN]. */
	executeSingleton(transaction: Transaction, sqlStmt: string, parameters?: any[],
		options?: {
			prepareOptions?: PrepareOptions,
			executeOptions?: ExecuteOptions
		}): Promise<any[]>;

	/** Executes a statement that returns a single record as an object. */
	executeSingletonAsObject<T extends object>(transaction: Transaction, sqlStmt: string, parameters?: any[],
		options?: {
			prepareOptions?: PrepareOptions,
			executeOptions?: ExecuteOptions
		}): Promise<T>;

	/**
	 * Executes a statement that returns a single record as [col1, col2, ..., colN].
	 * @deprecated since version 2.4.0 and will be removed in next major version. Replaced by executeSingleton.
	 */
	executeReturning(transaction: Transaction, sqlStmt: string, parameters?: any[],
		options?: {
			prepareOptions?: PrepareOptions,
			executeOptions?: ExecuteOptions
		}): Promise<any[]>;

	/**
	 * Executes a statement that returns a single record as an object.
	 * @deprecated since version 2.4.0 and will be removed in next major version. Replaced by executeSingletonAsObject.
	 */
	executeReturningAsObject<T extends object>(transaction: Transaction, sqlStmt: string, parameters?: any[],
		options?: {
			prepareOptions?: PrepareOptions,
			executeOptions?: ExecuteOptions
		}): Promise<T>;

	/** Executes a statement that has result set. */
	executeQuery(transaction: Transaction, sqlStmt: string, parameters?: any[],
		options?: {
			prepareOptions?: PrepareOptions,
			executeOptions?: ExecuteQueryOptions
		}): Promise<ResultSet>;

	queueEvents(names: string[], callBack: (counters: [string, number][]) => Promise<void>): Promise<Events>;

	/** True if the attachment is connected. */
	readonly isValid: boolean;

	/** Default transaction options. */
	defaultTransactionOptions?: TransactionOptions;

	/** Default query's prepare options. */
	defaultPrepareOptions?: PrepareOptions;

	/** Default query's execute options. */
	defaultExecuteOptions?: ExecuteOptions;

	/** Default query's executeQuery options. */
	defaultExecuteQueryOptions?: ExecuteQueryOptions;

	/** Default result set's fetch options. */
	defaultFetchOptions?: FetchOptions;
}

/** Transaction interface. */
export interface Transaction {
	/** Commits and release this transaction object. */
	commit(): Promise<void>;

	/** Commits and maintains this transaction object for subsequent work. */
	commitRetaining(): Promise<void>;

	/** Rollbacks and release this transaction object. */
	rollback(): Promise<void>;

	/** Rollbacks and maintains this transaction object for subsequent work. */
	rollbackRetaining(): Promise<void>;

	/** True if the transaction is active. */
	readonly isValid: boolean;
}

/** Statement interface. */
export interface Statement {
	/** Disposes this statement's resources. */
	dispose(): Promise<void>;

	/** Executes a prepared statement that uses the SET TRANSACTION command. Returns the new transaction. */
	executeTransaction(transaction: Transaction): Promise<Transaction>;

	/** Executes a prepared statement that has no result set. */
	execute(transaction: Transaction, parameters?: any[], options?: ExecuteOptions): Promise<void>;

	/** Executes a statement that returns a single record as [col1, col2, ..., colN]. */
	executeSingleton(transaction: Transaction, parameters?: any[], executeOptions?: ExecuteOptions): Promise<any[]>;

	/** Executes a statement that returns a single record as an object. */
	executeSingletonAsObject<T extends object>(transaction: Transaction, parameters?: any[], executeOptions?: ExecuteOptions): Promise<T>;

	/**
	 * Executes a statement that returns a single record as [col1, col2, ..., colN].
	 * @deprecated since version 2.4.0 and will be removed in next major version. Replaced by executeSingleton.
	 */
	executeReturning(transaction: Transaction, parameters?: any[], executeOptions?: ExecuteOptions): Promise<any[]>;

	/**
	 * Executes a statement that returns a single record as an object.
	 * @deprecated since version 2.4.0 and will be removed in next major version. Replaced by executeSingletonAsObject.
	 */
	executeReturningAsObject<T extends object>(transaction: Transaction, parameters?: any[],
		options?: ExecuteOptions): Promise<T>;

	/** Executes a prepared statement that has result set. */
	executeQuery(transaction: Transaction, parameters?: any[], options?: ExecuteQueryOptions): Promise<ResultSet>;

	/**
	 * Set cursor name of a SELECT ... FOR UPDATE statement.
	 *
	 * Use with ResultSet.fetch({ fetchSize: 1 }) and other statement with WHERE CURRENT OF <cursorName>.
	 */
	setCursorName(cursorName: string): Promise<void>;

	getExecPathText(): Promise<string | undefined>;

	/** True if the statement has not been disposed. */
	readonly isValid: boolean;

	/** Gets the query's result columns labels. Returns empty array for queries without result. */
	readonly columnLabels: Promise<string[]>;

	/** When true, query result must be obtained with method executeQuery. */
	readonly hasResultSet: boolean;

	/** Default query's execute options. */
	defaultExecuteOptions?: ExecuteOptions;

	/** Default query's executeQuery options. */
	defaultExecuteQueryOptions?: ExecuteQueryOptions;

	/** Default result set's fetch options. */
	defaultFetchOptions?: FetchOptions;
}

/** ResultSet interface. */
export interface ResultSet {
	/** Closes this result set. */
	close(): Promise<void>;

	/**
	 * Fetchs data from this result set as [col1, col2, ..., colN][].
	 *
	 * If an exception is found after fetching a row but before reaching options.fetchSize, its throw is delayed for the next fetch call.
	 *
	 * If result set has no more rows, returns an empty array.
	 */
	fetch(options?: FetchOptions): Promise<any[][]>;

	/**
	 * Fetchs data from this result set as T[].
	 * Where <T> represents your object interface.
	 *
	 * If an exception is found after fetching a row but before reaching options.fetchSize, its throw is delayed for the next fetch call.
	 *
	 * If result set has no more rows, returns an empty array.
	 */
	fetchAsObject<T extends object>(options?: FetchOptions): Promise<T[]>;

	/** True if the ResultSet is open. */
	readonly isValid: boolean;

	/** Default result set's fetch options. */
	defaultFetchOptions?: FetchOptions;
}

export interface Events {
	cancel(): Promise<void>;

	/** True if the events' attachment is valid. */
	readonly isValid: boolean;
}

/** Blob class. */
export class Blob {
	/** Gets the blob's attachment. */
	readonly attachment: Attachment;

	/** Gets the blob's id. */
	readonly id = new Uint8Array(8);

	constructor(attachment: Attachment, id: Uint8Array) {
		this.attachment = attachment;
		this.id.set(id);
	}

	/** True if the blob's attachment is valid. */
	get isValid(): boolean {
		return this.attachment.isValid;
	}
}

export enum BlobSeekWhence {
	START = 0,
	CURRENT = 1,
	END = 2
}

/** BlobStream class. */
export abstract class BlobStream {
	/** Gets the blob's. */
	readonly blob: Blob;

	/** Gets the blob's stream length in bytes.  */
	abstract get length(): Promise<number>;

	protected constructor(blob: Blob) {
		this.blob = blob;
	}

	/** Closes the blob's stream. */
	abstract close(): Promise<void>;

	/** Cancels the blob's creation. */
	abstract cancel(): Promise<void>;

	/** Seeks into the blob stream and return the new position. */
	abstract seek(offset: number, whence?: BlobSeekWhence): Promise<number>;

	/**
	 * Reads data from the blob and return the number of bytes read or -1 for end-of-stream.
	 * The number of bytes read may be less than the buffer' size while more data to be read exists.
	 */
	abstract read(buffer: Buffer): Promise<number>;

	/** Writes data to the blob. */
	abstract write(buffer: Buffer): Promise<void>;

	/** True if the blob stream is open. */
	abstract get isValid(): boolean;
}

/** TIME WITH TIME ZONE and TIMESTAMP WITH TIME ZONE to be sent as parameter */
export interface ZonedDate {
	date: Date;
	timeZone: string;
}

/** TIME WITH TIME ZONE and TIMESTAMP WITH TIME ZONE returned by Firebird */
export interface ZonedDateEx extends ZonedDate {
	offset: number;
}
