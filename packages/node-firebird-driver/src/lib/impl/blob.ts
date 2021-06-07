import { AbstractAttachment } from './attachment';

import { Blob, BlobStream } from '..';


/** AbstractBlobStream implementation. */
export abstract class AbstractBlobStream extends BlobStream {
	protected constructor(blob: Blob, public attachment: AbstractAttachment) {
		super(blob);
	}

	get length(): Promise<number> {
		return this.internalGetLength();
	}

	async close(): Promise<void> {
		return await this.internalClose();
	}

	async cancel(): Promise<void> {
		return await this.internalCancel();
	}

	async read(buffer: Buffer): Promise<number> {
		return await this.internalRead(buffer);
	}

	async write(buffer: Buffer): Promise<void> {
		return await this.internalWrite(buffer);
	}

	protected abstract internalGetLength(): Promise<number>;
	protected abstract internalClose(): Promise<void>;
	protected abstract internalCancel(): Promise<void>;
	protected abstract internalRead(buffer: Buffer): Promise<number>;
	protected abstract internalWrite(buffer: Buffer): Promise<void>;
}
