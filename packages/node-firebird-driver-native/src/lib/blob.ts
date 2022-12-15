import { AttachmentImpl } from './attachment';

import { Blob, BlobSeekWhence, CreateBlobOptions } from 'node-firebird-driver';
import { AbstractBlobStream, blobInfo, createBpb, getPortableInteger } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';
import { TransactionImpl } from './transaction';


const MAX_SEGMENT_SIZE = 65535;


/** BlobStream implementation. */
export class BlobStreamImpl extends AbstractBlobStream {
	// Override declarations.
	override attachment: AttachmentImpl;

	blobHandle?: fb.Blob;

	static async create(attachment: AttachmentImpl, transaction: TransactionImpl, options?: CreateBlobOptions): Promise<BlobStreamImpl> {
		return await attachment.client.statusAction(async status => {
			const blobId = new Uint8Array(8);
			const bpb = createBpb(options);

			const blobHandle = await attachment.attachmentHandle!.createBlobAsync(
				status, transaction.transactionHandle, blobId, bpb.length, bpb);

			const blob = new Blob(attachment, blobId);

			const blobStream = new BlobStreamImpl(blob, attachment);
			blobStream.blobHandle = blobHandle;
			return blobStream;
		});
	}

	static async open(attachment: AttachmentImpl, transaction: TransactionImpl, blob: Blob): Promise<BlobStreamImpl> {
		return await attachment.client.statusAction(async status => {
			const blobStream = new BlobStreamImpl(blob, attachment);
			blobStream.blobHandle = await attachment.attachmentHandle!.openBlobAsync(
				status, transaction.transactionHandle, blob.id, 0, undefined);
			return blobStream;
		});
	}

	protected async internalGetLength(): Promise<number> {
		return await this.attachment.client.statusAction(async status => {
			const infoReq = new Uint8Array([blobInfo.totalLength]);
			const infoRet = new Uint8Array(20);
			await this.blobHandle!.getInfoAsync(status, infoReq.byteLength, infoReq, infoRet.byteLength, infoRet);

			if (infoRet[0] != blobInfo.totalLength)
				throw new Error('Unrecognized response from Blob::getInfo.');

			const size = getPortableInteger(infoRet.subarray(1), 2);

			return getPortableInteger(infoRet.subarray(3), size);
		});
	}

	protected async internalClose(): Promise<void> {
		await this.attachment.client.statusAction(status => this.blobHandle!.closeAsync(status));
		this.blobHandle = undefined;
	}

	protected async internalCancel(): Promise<void> {
		await this.attachment.client.statusAction(status => this.blobHandle!.cancelAsync(status));
		this.blobHandle = undefined;
	}

	protected async internalSeek(offset: number, whence?: BlobSeekWhence): Promise<number> {
		return await this.attachment.client.statusAction(async status => {
			return await this.blobHandle!.seekAsync(status, whence ?? BlobSeekWhence.START, offset);
		});
	}

	protected async internalRead(buffer: Buffer): Promise<number> {
		return await this.attachment.client.statusAction(async status => {
			const readingBytes = Math.min(buffer.length, MAX_SEGMENT_SIZE);
			const segLength = new Uint32Array(1);
			const result = await this.blobHandle!.getSegmentAsync(status, readingBytes, buffer, segLength);

			if (result == fb.Status.RESULT_NO_DATA)
				return -1;

			return segLength[0];
		});
	}

	protected async internalWrite(buffer: Buffer): Promise<void> {
		await this.attachment.client.statusAction(async status => {
			while (buffer.length > 0) {
				const writingBytes = Math.min(buffer.length, MAX_SEGMENT_SIZE);
				await this.blobHandle!.putSegmentAsync(status, writingBytes, buffer);
				buffer = buffer.slice(writingBytes);
			}
		});
	}

	get isValid(): boolean {
		return !!this.blobHandle && this.attachment.isValid;
	}
}
