import { AttachmentImpl } from './attachment';
import { ResultSetImpl } from './resultset';
import { TransactionImpl } from './transaction';

import { ExecuteOptions, ExecuteQueryOptions, FetchOptions, PrepareOptions, ResultSet, Statement, Transaction } from 'node-firebird-driver';

import { createDataWriter, DataWriter, fixMetadata } from './fb-util';

import * as fb from 'node-firebird-native-api';


/** Transaction implementation. */
export class StatementImpl implements Statement {
	statement: fb.Statement;
	resultSet: ResultSetImpl;
	inMetadata: fb.MessageMetadata;
	outMetadata: fb.MessageMetadata;
	inBuffer: Uint8Array;
	dataWriter: DataWriter;

	/** Default query's execute options. */
	defaultExecuteOptions: ExecuteOptions;

	/** Default query's executeQuery options. */
	defaultExecuteQueryOptions: ExecuteQueryOptions;

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;

	static async prepare(attachment: AttachmentImpl, transaction: TransactionImpl, sqlStmt: string, options?: PrepareOptions):
			Promise<StatementImpl> {
		const statement = new StatementImpl(attachment);

		return await attachment.client.statusAction(async status => {
			//// FIXME: options/flags, dialect
			statement.statement = await attachment.attachment.prepareAsync(status, transaction.transaction, 0, sqlStmt, 3,
				fb.Statement.PREPARE_PREFETCH_ALL);

			statement.inMetadata = fixMetadata(status, await statement.statement.getInputMetadataAsync(status));
			statement.outMetadata = fixMetadata(status, await statement.statement.getOutputMetadataAsync(status));

			statement.inBuffer = new Uint8Array(statement.inMetadata.getMessageLengthSync(status));
			statement.dataWriter = createDataWriter(status, attachment.client, transaction, statement.inMetadata);

			attachment.statements.add(statement);

			return statement;
		});
	}

	private constructor(public attachment: AttachmentImpl) {
	}

	/** Disposes this statement's resources. */
	async dispose(): Promise<void> {
		if (this.resultSet)
			await this.resultSet.close();

		if (this.outMetadata) {
			this.outMetadata.releaseSync();
			this.outMetadata = null;
		}

		if (this.inMetadata) {
			this.inMetadata.releaseSync();
			this.inMetadata = null;
		}

		await this.attachment.client.statusAction(status => this.statement.freeAsync(status));

		this.attachment.statements.delete(this);
		this.attachment = null;
		this.statement = null;

		return await null;
	}

	/** Executes a prepared statement that uses the SET TRANSACTION command. Returns the new transaction. */
	async executeTransaction(transaction: Transaction): Promise<Transaction> {
		//// TODO: check opened resultSet.
		throw new Error('Uninplemented method: executeTransaction.');
	}

	/** Executes a prepared statement that has no result set. */
	async execute(transaction: Transaction, parameters?: Array<any>, options?: ExecuteOptions): Promise<void> {
		//// TODO: check opened resultSet.

		return await this.attachment.client.statusAction(async status => {
			const transactionImpl = transaction as TransactionImpl;

			await this.dataWriter(this.inBuffer, parameters);

			const newTransaction = await this.statement.executeAsync(status, transactionImpl.transaction,
				this.inMetadata, this.inBuffer, this.outMetadata, null);

			if (newTransaction && transactionImpl.transaction != newTransaction)
				{}	//// FIXME: newTransaction.releaseSync();
		});
	}

	/** Executes a prepared statement that has result set. */
	async executeQuery(transaction: Transaction, parameters?: Array<any>, options?: ExecuteQueryOptions): Promise<ResultSet> {
		//// TODO: check opened resultSet.
		return await ResultSetImpl.open(this, transaction as TransactionImpl, parameters, options);
	}
}
