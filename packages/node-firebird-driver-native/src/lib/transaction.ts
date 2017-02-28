import { AttachmentImpl } from './attachment';

import { Transaction, TransactionOptions } from 'node-firebird-driver';

import * as fb from 'node-firebird-native-api';


/** Transaction implementation. */
export class TransactionImpl implements Transaction {
	transaction: fb.Transaction;

	static async start(attachment: AttachmentImpl, options?: TransactionOptions): Promise<TransactionImpl> {
		const transaction = new TransactionImpl(attachment);

		return await attachment.client.statusAction(async status => {
			transaction.transaction = await attachment.attachment.startTransactionAsync(status, 0, null);	//// FIXME: options
			return transaction;
		});
	}

	private constructor(public attachment: AttachmentImpl) {
	}

	/** Commits and release this transaction object. */
	async commit(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transaction.commitAsync(status));
	}

	/** Commits and maintains this transaction object for subsequent work. */
	async commitRetaining(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transaction.commitRetainingAsync(status));
	}

	/** Rollbacks and release this transaction object. */
	async rollback(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transaction.rollbackAsync(status));
	}

	/** Rollbacks and maintains this transaction object for subsequent work. */
	async rollbackRetaining(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transaction.rollbackRetainingAsync(status));
	}
}
