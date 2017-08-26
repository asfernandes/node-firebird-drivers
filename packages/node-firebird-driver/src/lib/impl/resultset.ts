import { AbstractStatement } from './statement';
import { AbstractTransaction } from './transaction';

import { FetchOptions, ResultSet } from '..';


/** AbstractResultSet implementation. */
export abstract class AbstractResultSet implements ResultSet {
	finished = false;
	diposeStatementOnClose = false;

	/** Default result set's fetch options. */
	defaultFetchOptions: FetchOptions;

	protected constructor(public statement?: AbstractStatement, public transaction?: AbstractTransaction) {
	}

	/** Closes this result set. */
	async close(): Promise<void> {
		this.check();

		if (this.diposeStatementOnClose) {
			this.diposeStatementOnClose = false;
			await this.statement!.dispose();
			return;
		}

		await this.internalClose();

		this.statement!.resultSet = undefined;
		this.statement = undefined;
	}

	/** Fetchs data from this result set. */
	async fetch(options?: FetchOptions): Promise<Array<Array<any>>> {
		this.check();

		if (this.finished)
			return [];

		const fetchRet = await this.internalFetch(
			options || this.defaultFetchOptions || this.statement!.defaultFetchOptions || this.statement!.attachment!.defaultFetchOptions ||
				this.statement!.attachment!.client!.defaultFetchOptions);

		if (fetchRet.finished)
			this.finished = true;

		return fetchRet.rows;
	}

	private check() {
		if (!this.statement)
			throw new Error('ResultSet is already closed.');
	}

	protected abstract async internalClose(): Promise<void>;
	protected abstract async internalFetch(options?: FetchOptions): Promise<{ finished: boolean; rows: Array<Array<any>> }>;
}
