import { AttachmentImpl } from './attachment';
import { ResultSetImpl } from './resultset';
import { TransactionImpl } from './transaction';

import {
	ExecuteOptions,
	ExecuteQueryOptions,
	PrepareOptions
} from 'node-firebird-driver';

import { AbstractStatement } from 'node-firebird-driver/dist/lib/impl';

import { createDataWriter, DataWriter, fixMetadata } from './fb-util';

import * as fb from 'node-firebird-native-api';


/** Statement implementation. */
export class StatementImpl extends AbstractStatement {
	// Override declarations.
	attachment: AttachmentImpl;
	///resultSet: ResultSetImpl;

	statementHandle: fb.Statement;
	inMetadata: fb.MessageMetadata;
	outMetadata: fb.MessageMetadata;
	inBuffer: Uint8Array;
	dataWriter: DataWriter;

	static async prepare(attachment: AttachmentImpl, transaction: TransactionImpl, sqlStmt: string, options?: PrepareOptions):
			Promise<StatementImpl> {
		const statement = new StatementImpl(attachment);

		return await attachment.client.statusAction(async status => {
			//// FIXME: options/flags, dialect
			statement.statementHandle = await attachment.attachmentHandle.prepareAsync(status, transaction.transactionHandle,
				0, sqlStmt, 3, fb.Statement.PREPARE_PREFETCH_ALL);

			statement.inMetadata = fixMetadata(status, await statement.statementHandle.getInputMetadataAsync(status));
			statement.outMetadata = fixMetadata(status, await statement.statementHandle.getOutputMetadataAsync(status));

			statement.inBuffer = new Uint8Array(statement.inMetadata.getMessageLengthSync(status));
			statement.dataWriter = createDataWriter(status, attachment.client, transaction, statement.inMetadata);

			return statement;
		});
	}

	/** Disposes this statement's resources. */
	protected async internalDispose(): Promise<void> {
		if (this.outMetadata) {
			this.outMetadata.releaseSync();
			this.outMetadata = null;
		}

		if (this.inMetadata) {
			this.inMetadata.releaseSync();
			this.inMetadata = null;
		}

		await this.attachment.client.statusAction(status => this.statementHandle.freeAsync(status));

		this.statementHandle = null;
	}

	/** Executes a prepared statement that uses the SET TRANSACTION command. Returns the new transaction. */
	protected async internalExecuteTransaction(transaction: TransactionImpl): Promise<TransactionImpl> {
		throw new Error('Uninplemented method: executeTransaction.');
	}

	/** Executes a prepared statement that has no result set. */
	protected async internalExecute(transaction: TransactionImpl, parameters?: Array<any>, options?: ExecuteOptions): Promise<void> {
		return await this.attachment.client.statusAction(async status => {
			await this.dataWriter(this.inBuffer, parameters);

			const newTransaction = await this.statementHandle.executeAsync(status, transaction.transactionHandle,
				this.inMetadata, this.inBuffer, this.outMetadata, null);

			if (newTransaction && transaction.transactionHandle != newTransaction)
				{}	//// FIXME: newTransaction.releaseSync();
		});
	}

	/** Executes a prepared statement that has result set. */
	protected async internalExecuteQuery(transaction: TransactionImpl, parameters?: Array<any>, options?: ExecuteQueryOptions):
			Promise<ResultSetImpl> {
		return await ResultSetImpl.open(this, transaction as TransactionImpl, parameters, options);
	}
}
