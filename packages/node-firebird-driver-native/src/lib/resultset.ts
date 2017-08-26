import { StatementImpl } from './statement';
import { TransactionImpl } from './transaction';
import { readBlob, writeBlob } from './fb-util';

import { ExecuteQueryOptions, FetchOptions } from 'node-firebird-driver';
import { AbstractResultSet } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** ResultSet implementation. */
export class ResultSetImpl extends AbstractResultSet {
	// Override declarations.
	statement: StatementImpl;
	transaction: TransactionImpl;

	resultSetHandle?: fb.ResultSet;

	static async open(statement: StatementImpl, transaction: TransactionImpl, parameters?: Array<any>,
			options?: ExecuteQueryOptions): Promise<ResultSetImpl> {
		const resultSet = new ResultSetImpl(statement, transaction);

		return await statement.attachment.client.statusAction(async status => {
			//// FIXME: options

			await statement.dataWriter(statement.inBuffer, parameters, (blobId, buffer) => writeBlob(status, transaction, blobId, buffer));

			resultSet.resultSetHandle = await statement.statementHandle!.openCursorAsync(status, transaction.transactionHandle,
				statement.inMetadata, statement.inBuffer, statement.outMetadata, 0);

			return resultSet;
		});
	}

	/** Closes this result set. */
	protected async internalClose(): Promise<void> {
		await this.statement.attachment.client.statusAction(async status => {
			await this.resultSetHandle!.closeAsync(status);

			this.resultSetHandle = undefined;
		});
	}

	/** Fetchs data from this result set. */
	protected async internalFetch(options?: FetchOptions): Promise<{ finished: boolean; rows: Array<Array<any>> }> {
		return await this.statement.attachment.client.statusAction(async status => {
			const rows = [];
			const buffers = [this.statement.outBuffer, new Uint8Array(this.statement.outMetadata!.getMessageLengthSync(status))];
			let buffer = 0;
			let nextFetch = this.resultSetHandle!.fetchNextAsync(status, buffers[buffer]);

			while (true) {
				if (await nextFetch == fb.Status.RESULT_OK) {
					const buffer1 = buffer;
					buffer = ++buffer % 2;

					const finish = options && options.fetchSize && rows.length + 1 >= options.fetchSize;

					if (!finish)
						nextFetch = this.resultSetHandle!.fetchNextAsync(status, buffers[buffer]);

					rows.push(await this.statement.dataReader(
						buffers[buffer1], blobId => readBlob(status, this.transaction, blobId)));

					if (finish)
						return { finished: false, rows: rows };
				}
				else {
					return { finished: true, rows: rows };
				}
			}
		});
	}
}
