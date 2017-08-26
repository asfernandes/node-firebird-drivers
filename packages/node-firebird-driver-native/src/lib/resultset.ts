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

			while (true) {
				if (await this.resultSetHandle!.fetchNextAsync(status, this.statement.outBuffer) == fb.Status.RESULT_OK) {
					rows.push(await this.statement.dataReader(
						this.statement.outBuffer, blobId => readBlob(status, this.transaction, blobId)));

					if (options && options.fetchSize && rows.length >= options.fetchSize)
						return { finished: false, rows: rows };
				}
				else {
					return { finished: true, rows: rows };
				}
			}
		});
	}
}
