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

	/**
	 * Fetchs data from this result set as [col1, col2, ..., colN][].
	 *
	 * If an exception is found after fetching a row but before reaching options.fetchSize, its throw is delayed for the next fetch call.
	 *
	 * If result set has no more rows, returns an empty array.
	 */
	async fetch(options?: FetchOptions): Promise<any[][]> {
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

	/**
	 * Fetchs data from this result set as T[].
	 * Where <T> represents your object interface.
	 *
	 * If an exception is found after fetching a row but before reaching options.fetchSize, its throw is delayed for the next fetch call.
	 *
	 * If result set has no more rows, returns an empty array.
	 */
	async fetchAsObject<T extends object>(options?: FetchOptions): Promise<T[]> {
		const array = await this.fetch(options);
		const cols = (await this.statement?.columnLabels) || [];

		return array.map(row => {
			const obj = {} as T;

			// Loop on row column value.
			row.forEach((v: any, idx: number) => {
				const col = cols[idx];
				(obj as any)[col] = v;
			});

			return obj;
		});
	}

	get isValid(): boolean {
		return !!this.statement;
	}

	private check() {
		if (!this.isValid)
			throw new Error('ResultSet is already closed.');
	}

	protected abstract internalClose(): Promise<void>;

	protected abstract internalFetch(options?: FetchOptions): Promise<{ finished: boolean; rows: any[][] }>;
}
