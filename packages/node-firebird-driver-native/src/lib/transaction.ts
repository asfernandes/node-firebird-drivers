import { AttachmentImpl } from './attachment';
import { createTpb } from './fb-util';

import { TransactionOptions } from 'node-firebird-driver';
import { AbstractTransaction } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** Transaction implementation. */
export class TransactionImpl extends AbstractTransaction {
	// Override declarations.
	override attachment: AttachmentImpl;

	transactionHandle?: fb.Transaction;

	static async start(attachment: AttachmentImpl, options?: TransactionOptions): Promise<TransactionImpl> {
		const transaction = new TransactionImpl(attachment);

		return await attachment.client.statusAction(async status => {
			const tpb = createTpb(options);
			transaction.transactionHandle = await attachment!.attachmentHandle!.startTransactionAsync(status, tpb.length, tpb);
			return transaction;
		});
	}

	/** Commits and release this transaction object. */
	protected async internalCommit(): Promise<void> {
		await this.attachment.client.statusAction(status => this.transactionHandle!.commitAsync(status));
		this.transactionHandle = undefined;
	}

	/** Commits and maintains this transaction object for subsequent work. */
	protected async internalCommitRetaining(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transactionHandle!.commitRetainingAsync(status));
	}

	/** Rollbacks and release this transaction object. */
	protected async internalRollback(): Promise<void> {
		await this.attachment.client.statusAction(status => this.transactionHandle!.rollbackAsync(status));
		this.transactionHandle = undefined;
	}

	/** Rollbacks and maintains this transaction object for subsequent work. */
	protected async internalRollbackRetaining(): Promise<void> {
		return await this.attachment.client.statusAction(status => this.transactionHandle!.rollbackRetainingAsync(status));
	}
}
