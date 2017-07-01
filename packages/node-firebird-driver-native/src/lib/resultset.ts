import { StatementImpl } from './statement';
import { TransactionImpl } from './transaction';
import { createDataReader, DataReader } from './fb-util';

import { ExecuteQueryOptions, FetchOptions } from 'node-firebird-driver';
import { AbstractResultSet } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** ResultSet implementation. */
export class ResultSetImpl extends AbstractResultSet {
	// Override declarations.
	statement: StatementImpl;

	resultSetHandle: fb.ResultSet;
	outBuffer: Uint8Array;
	dataReader: DataReader;

	static async open(statement: StatementImpl, transaction: TransactionImpl, parameters?: Array<any>,
			options?: ExecuteQueryOptions): Promise<ResultSetImpl> {
		const resultSet = new ResultSetImpl(statement);

		return await statement.attachment.client.statusAction(async status => {
			//// FIXME: options
			resultSet.dataReader = createDataReader(status, statement.attachment.client, transaction, statement.outMetadata);

			statement.dataWriter(statement.inBuffer, parameters);

			resultSet.resultSetHandle = await statement.statementHandle.openCursorAsync(status, transaction.transactionHandle,
				statement.inMetadata, statement.inBuffer, statement.outMetadata, 0);
			resultSet.outBuffer = new Uint8Array(statement.outMetadata.getMessageLengthSync(status));

			return resultSet;
		});
	}

	/** Closes this result set. */
	protected async internalClose(): Promise<void> {
		await this.statement.attachment.client.statusAction(async status => {
			await this.resultSetHandle.closeAsync(status);

			this.resultSetHandle = null;
		});
	}

	/** Fetchs data from this result set. */
	protected async internalFetch(options?: FetchOptions): Promise<{ finished: boolean; rows: Array<Array<any>> }> {
		return await this.statement.attachment.client.statusAction(async status => {
			const rows = [];

			while (true) {
				if (await this.resultSetHandle.fetchNextAsync(status, this.outBuffer) == fb.Status.RESULT_OK)
					rows.push(await this.dataReader(this.outBuffer));
				else {
					return { finished: true, rows: await rows };
				}
			}
		});
	}
}
