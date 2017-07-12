import { TransactionImpl } from './transaction';

import { blobInfo, getPortableInteger, sqlTypes, Descriptor } from 'node-firebird-driver/dist/lib/impl';
export * from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** Fix metadata descriptors to types we want to read. */
export function fixMetadata(status: fb.Status, metadata?: fb.MessageMetadata): fb.MessageMetadata | undefined {
	if (!metadata)
		return undefined;

	let ret: fb.MessageMetadata;

	const outBuilder = metadata.getBuilderSync(status)!;
	try {
		for (let i = metadata.getCountSync(status) - 1; i >= 0; --i) {
			switch (metadata.getTypeSync(status, i)) {
				// Transforms CHAR descriptors to VARCHAR.
				case sqlTypes.SQL_TEXT:
					outBuilder.setTypeSync(status, i, sqlTypes.SQL_VARYING);
					break;

				// Transforms numeric descriptors to DOUBLE PRECISION.
				case sqlTypes.SQL_SHORT:
				case sqlTypes.SQL_LONG:
				case sqlTypes.SQL_INT64:
				case sqlTypes.SQL_FLOAT:
					outBuilder.setTypeSync(status, i, sqlTypes.SQL_DOUBLE);
					outBuilder.setLengthSync(status, i, 8);
					outBuilder.setScaleSync(status, i, 0);
					break;
			}
		}

		ret = outBuilder.getMetadataSync(status)!;
	}
	finally {
		outBuilder.releaseSync();
	}

	metadata.releaseSync();

	return ret;
}

export function createDescriptors(status: fb.Status, metadata?: fb.MessageMetadata): Descriptor[] {
	if (!metadata)
		return [];

	const count = metadata.getCountSync(status);
	const ret: Descriptor[] = [];

	for (let i = 0; i < count; ++i) {
		ret.push({
			type: metadata.getTypeSync(status, i),
			subType: metadata.getSubTypeSync(status, i),
			nullOffset: metadata.getNullOffsetSync(status, i),
			offset: metadata.getOffsetSync(status, i),
			length: metadata.getLengthSync(status, i),
			scale: metadata.getScaleSync(status, i),
		});
	}

	return ret;
}

export async function readBlob(status: fb.Status, transaction: TransactionImpl, blobId: Uint8Array): Promise<Buffer> {
	//// TODO: transliterate sub_type text.
	let retBuffer: Buffer;
	let segLength: Uint32Array;
	let pos = 0;

	const blob = (await transaction.attachment.attachmentHandle!.openBlobAsync(
		status, transaction.transactionHandle, blobId, 0, undefined))!;

	try {
		const infoReq = new Uint8Array([blobInfo.totalLength]);
		const infoRet = new Uint8Array(20);
		await blob.getInfoAsync(status, infoReq.byteLength, infoReq, infoRet.byteLength, infoRet);

		if (infoRet[0] != blobInfo.totalLength || infoRet[1] != 4 || infoRet[2] != 0)
			throw new Error('Unrecognized response from Blob::getInfo.');

		const length = getPortableInteger(infoRet.subarray(3), 4);

		retBuffer = Buffer.alloc(length);
		segLength = new Uint32Array(1);

		let segRet: number;

		do {
			segRet = await blob.getSegmentAsync(status, retBuffer.length - pos, retBuffer.subarray(pos), segLength);
			pos += segLength[0];
		} while (segRet === fb.Status.RESULT_SEGMENT);

		if (pos !== length)
			throw new Error('Cannot retrieve full blob.');
	}
	finally {
		await blob.closeAsync(status);
	}

	return retBuffer;
}

export async function writeBlob(status: fb.Status, transaction: TransactionImpl, blobId: Uint8Array, buffer: Buffer): Promise<void> {
	//// TODO: transliterate sub_type text.
	const blob = (await transaction.attachment.attachmentHandle!.createBlobAsync(status,
		transaction.transactionHandle, blobId, 0, undefined))!;

	try {
		await blob.putSegmentAsync(status, buffer.length, buffer);
	}
	finally {
		await blob.closeAsync(status);
	}
}
