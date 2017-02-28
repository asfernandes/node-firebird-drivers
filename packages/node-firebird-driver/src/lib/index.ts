/** Client interface. */
export interface Client {
	/** Disposes this client's resources. */
	dispose(): Promise<void>;

	/** Connects to a database. */
	connect(uri: string, options?: ConnectOptions): Promise<Attachment>;

	/** Creates a database. */
	createDatabase(uri: string, options?: CreateDatabaseOptions): Promise<Attachment>;

	/** Default connect options. */
	defaultConnectOptions: ConnectOptions;

	/** Default create database options. */
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
}

/** ConnectOptions interface. */
export interface ConnectOptions {
	/** User name. */
	username?: string;

	/** User password. */
	password?: string;
}

/** CreateDatabaseOptions interface. */
export interface CreateDatabaseOptions extends ConnectOptions {
}

/** TransactionOptions interface. */
export interface TransactionOptions {
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
}

/** Attachment interface. */
export interface Attachment {
	/** Disconnects this attachment. */
	disconnect(): Promise<void>;

	/** Drops the database and release this attachment. */
	dropDatabase(): Promise<void>;

	/** Starts a new transaction. */
	startTransaction(options?: TransactionOptions): Promise<Transaction>;

	/** Prepares a query. */
	prepare(transaction: Transaction, sqlStmt: string, options?: PrepareOptions): Promise<Statement>;

	/** Executes a statement that uses the SET TRANSACTION command. Returns the new transaction. */
	executeTransaction(transaction: Transaction, sqlStmt: string, prepareOptions?: PrepareOptions): Promise<Transaction>;

	/** Executes a statement that has no result set. */
	execute(transaction: Transaction, sqlStmt: string, parameters?: Array<any>,
		prepareOptions?: PrepareOptions, executeOptions?: ExecuteOptions): Promise<void>;

	/** Executes a statement that has result set. */
	executeQuery(transaction: Transaction, sqlStmt: string, parameters?: Array<any>,
		prepareOptions?: PrepareOptions, executeOptions?: ExecuteQueryOptions): Promise<ResultSet>;

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
}

/** Statement interface. */
export interface Statement {
	/** Disposes this statement's resources. */
	dispose(): Promise<void>;

	/** Executes a prepared statement that uses the SET TRANSACTION command. Returns the new transaction. */
	executeTransaction(transaction: Transaction): Promise<Transaction>;

	/** Executes a prepared statement that has no result set. */
	execute(transaction: Transaction, parameters?: Array<any>, options?: ExecuteOptions): Promise<void>;

	/** Executes a prepared statement that has result set. */
	executeQuery(transaction: Transaction, parameters?: Array<any>, options?: ExecuteQueryOptions): Promise<ResultSet>;

	/** Default query's execute options. */
	defaultExecuteOptions: ExecuteOptions;

	/** Default query's executeQuery options. */
	defaultExecuteQueryOptions: ExecuteQueryOptions;

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;
}

/** ResultSet interface. */
export interface ResultSet {
	/** Closes this result set. */
	close(): Promise<void>;

	/** Fetchs data from this result set. */
	fetch(options?: FetchOptions): Promise<Array<Array<any>>>;

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;
}

//// TODO: Event support.
