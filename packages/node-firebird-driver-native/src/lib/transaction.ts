import { AttachmentImpl } from './attachment';

import { TransactionOptions } from 'node-firebird-driver';
import { AbstractTransaction } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** Transaction implementation. */
export class TransactionImpl extends AbstractTransaction {
	// Override declarations.
	attachment: AttachmentImpl;

	transactionHandle: fb.Transaction;

	static async start(attachment: AttachmentImpl, options?: TransactionOptions): Promise<TransactionImpl> {
		const transaction = new TransactionImpl(attachment);

		return await attachment.client.statusAction(async status => {
			transaction.transactionHandle = await attachment.attachmentHandle.startTransactionAsync(status, 0, null);	//// FIXME: options
			return transaction;
		});
	}

	/** Commits and release this transaction object. */
	protected async internalCommit(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transactionHandle.commitAsync(status));
	}

	/** Commits and maintains this transaction object for subsequent work. */
	protected async internalCommitRetaining(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transactionHandle.commitRetainingAsync(status));
	}

	/** Rollbacks and release this transaction object. */
	protected async internalRollback(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transactionHandle.rollbackAsync(status));
	}

	/** Rollbacks and maintains this transaction object for subsequent work. */
	protected async internalRollbackRetaining(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transactionHandle.rollbackRetainingAsync(status));
	}
}
