import { AbstractStatement } from './statement';
import { AbstractTransaction } from './transaction';

import { FetchOptions, FetchOptionsAs, ResultSet } from '..';


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
	 * Fetchs data from this result set in it's basic raw mode.
	 */
	async fetch(options?: FetchOptions): Promise<Array<Array<any>>> {
		options = options || {};
		return (await this.fetchAs<any>({...options, json: false})).rows as Array<Array<any>>;
	}

	/**
	 * Fetchs data from this result set and results some useful properties such as column labels.
	 *
	 * If an exception is found after fetching a row but before reaching options.fetchSize, it's throw is delayed for the next fetch call.
	 *
	 * If result set has no more rows, returns an empty array.
	 */
	async fetchAs<T>(options?: FetchOptionsAs): Promise<{ rows: Array<T>, columns: string[]; }> {
		this.check();
		const cols = (await this.statement?.columnLabels) || [];
		if (this.finished)
			return {
				rows: [],
				columns: cols
			};

		const fetchRet = await this.internalFetch(
			options
			|| this.defaultFetchOptions
			|| this.statement!.defaultFetchOptions
			|| this.statement!.attachment!.defaultFetchOptions
			|| this.statement!.attachment!.client!.defaultFetchOptions
		);

		if (fetchRet.finished)
			this.finished = true;

		let output;
		if (fetchRet.rows && this.statement?.columnLabels) {
			output = fetchRet.rows.map(row => {
				const obj: any = {};
				// Loop on row column value
				row.forEach((v: any, idx: number) => {
					const col = cols[idx];
					obj[col] = v;
				});
				return obj;
			});
		}
		return {
			rows: output as any[],
			columns: cols as string[]
		};
	}

	private check() {
		if (!this.statement)
			throw new Error('ResultSet is already closed.');
	}

	protected abstract async internalClose(): Promise<void>;

	protected abstract async internalFetch(options?: FetchOptions): Promise<{ finished: boolean; rows: Array<any> }>;
}
