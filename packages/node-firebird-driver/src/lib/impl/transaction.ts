import { AbstractAttachment } from './attachment';

import { Transaction } from '..';


/** AbstractTransaction implementation. */
export abstract class AbstractTransaction implements Transaction {
	protected constructor(public attachment: AbstractAttachment) {
	}

	/** Commits and release this transaction object. */
	async commit(): Promise<void> {
		return await this.internalCommit();
	}

	/** Commits and maintains this transaction object for subsequent work. */
	async commitRetaining(): Promise<void> {
		return await this.internalCommitRetaining();
	}

	/** Rollbacks and release this transaction object. */
	async rollback(): Promise<void> {
		return await this.internalRollback();
	}

	/** Rollbacks and maintains this transaction object for subsequent work. */
	async rollbackRetaining(): Promise<void> {
		return await this.internalRollbackRetaining();
	}

	protected abstract async internalCommit(): Promise<void>;
	protected abstract async internalCommitRetaining(): Promise<void>;
	protected abstract async internalRollback(): Promise<void>;
	protected abstract async internalRollbackRetaining(): Promise<void>;
}
