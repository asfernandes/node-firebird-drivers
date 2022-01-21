import { AbstractAttachment } from './attachment';

import { Events } from '..';


/** AbstractStatement implementation. */
export abstract class AbstractEvents implements Events {
	protected constructor(public attachment?: AbstractAttachment) {
	}

	/** Cancel this events' resources. */
	async cancel(): Promise<void> {
		this.check();

		await this.internalCancel();

		this.attachment?.events.delete(this);
		this.attachment = undefined;
	}

	get isValid(): boolean {
		return !!this.attachment;
	}

	private check() {
		if (!this.isValid)
			throw new Error('Events are already cancelled.');
	}

	protected abstract internalCancel(): Promise<void>;
}
