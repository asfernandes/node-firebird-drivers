import { AbstractAttachment } from './attachment';

import { Transaction } from '..';


/** AbstractTransaction implementation. */
export abstract class AbstractTransaction implements Transaction {
	protected constructor(public attachment?: AbstractAttachment) {
	}

	/** Commits and release this transaction object. */
	async commit(): Promise<void> {
		this.check();

		await this.internalCommit();

		this.attachment!.transactions.delete(this);
		this.attachment = undefined;
	}

	/** Commits and maintains this transaction object for subsequent work. */
	async commitRetaining(): Promise<void> {
		this.check();

		return await this.internalCommitRetaining();
	}

	/** Rollbacks and release this transaction object. */
	async rollback(): Promise<void> {
		this.check();

		await this.internalRollback();

		this.attachment!.transactions.delete(this);
		this.attachment = undefined;
	}

	/** Rollbacks and maintains this transaction object for subsequent work. */
	async rollbackRetaining(): Promise<void> {
		this.check();

		return await this.internalRollbackRetaining();
	}

	get isValid(): boolean {
		return !!this.attachment;
	}

	private check() {
		if (!this.isValid)
			throw new Error('Transaction is already committed or rolled back.');
	}

	protected abstract internalCommit(): Promise<void>;
	protected abstract internalCommitRetaining(): Promise<void>;
	protected abstract internalRollback(): Promise<void>;
	protected abstract internalRollbackRetaining(): Promise<void>;
}
