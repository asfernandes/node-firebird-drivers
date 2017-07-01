import { AbstractStatement } from './statement';

import { FetchOptions, ResultSet } from '..';


/** AbstractResultSet implementation. */
export abstract class AbstractResultSet implements ResultSet {
	finished = false;
	diposeStatementOnClose = false;

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;

	protected constructor(public statement: AbstractStatement) {
	}

	/** Closes this result set. */
	async close(): Promise<void> {
		if (this.diposeStatementOnClose) {
			this.diposeStatementOnClose = false;
			await this.statement.dispose();
			return;
		}

		await this.internalClose();

		this.statement.resultSet = null;
		this.statement = null;
	}

	/** Fetchs data from this result set. */
	async fetch(options?: FetchOptions): Promise<Array<Array<any>>> {
		if (this.finished)
			return await [];

		const fetchRet = await this.internalFetch(
			options || this.statement.defaultFetchOptions || this.statement.attachment.defaultFetchOptions ||
				this.statement.attachment.client.defaultFetchOptions);

		if (fetchRet.finished)
			this.finished = true;

		return fetchRet.rows;
	}

	protected abstract async internalClose(): Promise<void>;
	protected abstract async internalFetch(options?: FetchOptions): Promise<{ finished: boolean; rows: Array<Array<any>> }>;
}
