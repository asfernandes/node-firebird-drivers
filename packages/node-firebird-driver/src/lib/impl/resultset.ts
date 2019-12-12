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
	 * Fetchs data from this result set as Array<Array<[col1, col2, ..., colN]>>
	 */
	async fetch(options?: FetchOptions): Promise<Array<Array<any>>> {
		options = options || this.defaultFetchOptions || {};
		return (await this.fetchAs<any>({...options, asObject: false})).rows as any; // Array<Array<any>>;
	}

	/**
	 * Fetchs data from this result set as Array<T>
	 * Where <T> represents your object interface.
	 */
	async fetchObject<T>(options?: FetchOptions): Promise<T> {
		options = options || this.defaultFetchOptions || {};
		return (await this.fetchAs<any>({...options, asObject: true})).rows as any; // Array<T>;
	}

	/**
	 * Fetchs data from this result set.
	 * Returns object with columns and rows.
	 * <T> represents the row entry
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

		let rowsObj;
		if (options?.asObject && cols.length) {
			rowsObj = fetchRet.rows.map(row => {
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
			rows: rowsObj as any[] || fetchRet.rows,
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
