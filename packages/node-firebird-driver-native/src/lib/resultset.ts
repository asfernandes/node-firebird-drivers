import { StatementImpl } from './statement';
import { TransactionImpl } from './transaction';
import { createDataReader } from './fb-util';

import { ExecuteQueryOptions, FetchOptions, ResultSet } from 'node-firebird-driver';

import * as fb from 'node-firebird-native-api';


/** Transaction implementation. */
export class ResultSetImpl implements ResultSet {
	resultSet: fb.ResultSet;
	outBuffer: Uint8Array;
	finished = false;
	diposeStatementOnClose = false;
	dataReader: (buffer: Uint8Array) => any[];

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;

	static async open(statement: StatementImpl, transaction: TransactionImpl, parameters?: Array<any>,
			options?: ExecuteQueryOptions): Promise<ResultSetImpl> {
		const resultSet = new ResultSetImpl(statement);

		return await statement.attachment.client.statusAction(async status => {
			//// FIXME: options
			resultSet.dataReader = createDataReader(status, statement.attachment.client, statement.outMetadata);

			statement.dataWriter(statement.inBuffer, parameters);

			resultSet.resultSet = await statement.statement.openCursorAsync(status, transaction.transaction,
				statement.inMetadata, statement.inBuffer, statement.outMetadata, 0);
			statement.resultSet = resultSet;
			resultSet.outBuffer = new Uint8Array(statement.outMetadata.getMessageLengthSync(status));
			return resultSet;
		});
	}

	private constructor(public statement: StatementImpl) {
	}

	/** Closes this result set. */
	async close(): Promise<void> {
		await this.statement.attachment.client.statusAction(async status => {
			if (this.diposeStatementOnClose) {
				this.diposeStatementOnClose = false;
				await this.statement.dispose();
				return;
			}

			this.resultSet.closeAsync(status);

			this.statement.resultSet = null;
			this.statement = null;
			this.resultSet = null;
		});
	}

	/** Fetchs data from this result set. */
	async fetch(options?: FetchOptions): Promise<Array<Array<any>>> {
		if (this.finished)
			return await [];

		return await this.statement.attachment.client.statusAction(async status => {
			const rows = [];

			while (true) {
				if (await this.resultSet.fetchNextAsync(status, this.outBuffer) == fb.Status.RESULT_OK)
					rows.push(await this.dataReader(this.outBuffer));
				else {
					this.finished = true;
					return await rows;
				}
			}
		});
	}
}
