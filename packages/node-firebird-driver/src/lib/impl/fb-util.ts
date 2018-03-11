import * as os from 'os';
const littleEndian = os.endianness() === 'LE';

import * as stringDecoder from 'string_decoder';

import { AbstractAttachment } from './attachment';
import { AbstractTransaction } from './transaction';
import { decodeDate, decodeTime, encodeDate, encodeTime }  from './date-time';

import {
	Attachment,
	Blob,
	BlobStream,
	ConnectOptions,
	CreateDatabaseOptions,
	Transaction,
	TransactionIsolation,
	TransactionOptions
} from '..';


/** SQL_* type constants */
export namespace sqlTypes {
	export const SQL_TEXT = 452;
	export const SQL_VARYING = 448;
	export const SQL_SHORT = 500;
	export const SQL_LONG = 496;
	export const SQL_FLOAT = 482;
	export const SQL_DOUBLE = 480;
	//export const SQL_D_FLOAT = 530;
	export const SQL_TIMESTAMP = 510;
	export const SQL_BLOB = 520;
	//export const SQL_ARRAY = 540;
	//export const SQL_QUAD = 550;
	export const SQL_TYPE_TIME = 560;
	export const SQL_TYPE_DATE = 570;
	export const SQL_INT64 = 580;
	export const SQL_BOOLEAN = 32764;
	export const SQL_NULL = 32766;
}

/** DPB constants. */
export namespace dpb {
	export const isc_dpb_version1 = 1;
	export const lc_ctype = 48;
	export const user_name = 28;
	export const password = 29;
}

/** TPB constants. */
export namespace tpb {
	export const isc_tpb_version1 = 1;
	export const isc_tpb_consistency = 1;
	export const isc_tpb_concurrency = 2;
	export const isc_tpb_wait = 6;
	export const isc_tpb_nowait = 7;
	export const isc_tpb_read = 8;
	export const isc_tpb_write = 9;
	export const isc_tpb_ignore_limbo = 14;
	export const isc_tpb_read_committed = 15;
	export const isc_tpb_autocommit = 16;
	export const isc_tpb_rec_version = 17;
	export const isc_tpb_no_rec_version = 18;
	export const isc_tpb_restart_requests = 19;
	export const isc_tpb_no_auto_undo = 20;
}

/** Blob info. */
export namespace blobInfo {
	export const totalLength = 6;
}

export function createDpb(options?: ConnectOptions | CreateDatabaseOptions): Buffer {
	const code = (c: number) => String.fromCharCode(c);
	const charSet = 'utf8';
	let ret = `${code(dpb.isc_dpb_version1)}${code(dpb.lc_ctype)}${code(charSet.length)}${charSet}`;

	if (!options)
		options = {};

	if (!options.username)
		options.username = process.env.ISC_USER;

	if (!options.password)
		options.password = process.env.ISC_PASSWORD;

	if (options.username)
		ret += `${code(dpb.user_name)}${code(options.username.length)}${options.username}`;

	if (options.password)
		ret += `${code(dpb.password)}${code(options.password.length)}${options.password}`;

	return Buffer.from(ret);
}

export function createTpb(options?: TransactionOptions): Buffer {
	const code = (c: number) => String.fromCharCode(c);
	let ret = code(tpb.isc_tpb_version1);

	if (!options)
		options = {};

	switch (options.accessMode) {
		case 'READ_ONLY':
			ret += code(tpb.isc_tpb_read);
			break;

		case 'READ_WRITE':
			ret += code(tpb.isc_tpb_write);
			break;
	}

	switch (options.waitMode) {
		case 'NO_WAIT':
			ret += code(tpb.isc_tpb_nowait);
			break;

		case 'WAIT':
			ret += code(tpb.isc_tpb_wait);
			break;
	}

	switch (options.isolation) {
		case TransactionIsolation.CONSISTENCY:
			ret += code(tpb.isc_tpb_consistency);
			break;

		case TransactionIsolation.SNAPSHOT:
			ret += code(tpb.isc_tpb_concurrency);
			break;

		case TransactionIsolation.READ_COMMITTED:
			ret += code(tpb.isc_tpb_read_committed) +
				code(options.readCommittedMode == 'RECORD_VERSION' ? tpb.isc_tpb_rec_version : tpb.isc_tpb_no_rec_version);
			break;
	}

	if (options.noAutoUndo)
		ret += code(tpb.isc_tpb_no_auto_undo);

	if (options.ignoreLimbo)
		ret += code(tpb.isc_tpb_ignore_limbo);

	if (options.restartRequests)
		ret += code(tpb.isc_tpb_restart_requests);

	if (options.autoCommit)
		ret += code(tpb.isc_tpb_autocommit);

	return Buffer.from(ret);
}

/** Changes a number from a scale to another. */
/***
export function changeScale(value: number, inputScale: number, outputScale: number): number {
	outputScale -= inputScale;

	Math.pow(10, outputScale);

	if (outputScale === 0)
		return value;
	else if (outputScale > 0)
		return value / Math.pow(10, outputScale);
	else	// outputScale < 0
		return value * Math.pow(10, -outputScale);
}
***/

/** Emulate Firebird isc_portable_integer. */
export function getPortableInteger(buffer: Uint8Array, length: number) {
	if (!buffer || length <= 0 || length > 8)
		return 0;

	let value = 0;
	let pos = 0;

	for (let shift = 0; --length >= 0; shift += 8)
		value += buffer[pos++] << shift;

	return value;
}


/** Descriptor for a field or parameter. */
export interface Descriptor {
	type: number;
	subType: number;
	length: number;
	scale: number;
	offset: number;
	nullOffset: number;
}


export type DataReader = (attachment: Attachment, transaction: Transaction, buffer: Uint8Array) => Promise<any[]>;
export type ItemReader = (attachment: Attachment, transaction: Transaction, buffer: Uint8Array) => Promise<any>;

/** Creates a data reader. */
export function createDataReader(descriptors: Descriptor[]): DataReader {
	const mappers = new Array<ItemReader>(descriptors.length);

	for (let i = 0; i < descriptors.length; ++i) {
		const descriptor = descriptors[i];

		mappers[i] = async (attachment: AbstractAttachment, transaction: AbstractTransaction, buffer: Uint8Array): Promise<any> => {
			const dataView = new DataView(buffer.buffer);

			if (dataView.getInt16(descriptor.nullOffset, littleEndian) == -1)
				return null;

			switch (descriptor.type) {
				// SQL_TEXT is handled changing its descriptor to SQL_VARYING with IMetadataBuilder.
				case sqlTypes.SQL_VARYING: {
					//// TODO: none, octets
					const varLength = dataView.getUint16(descriptor.offset, littleEndian);
					const decoder = new stringDecoder.StringDecoder('utf8');
					const buf = Buffer.from(buffer.buffer, descriptor.offset + 2, varLength);
					return decoder.end(buf);
				}

				/***
				case sqlTypes.SQL_SHORT:
					return changeScale(dataView.getInt16(descriptor.offset, littleEndian), descriptor.scale, 0);

				case sqlTypes.SQL_LONG:
					return changeScale(dataView.getInt32(descriptor.offset, littleEndian), descriptor.scale, 0);

				//// TODO: sqlTypes.SQL_INT64

				case sqlTypes.SQL_FLOAT:
					return dataView.getFloat32(descriptor.offset, littleEndian);
				***/

				case sqlTypes.SQL_DOUBLE:
					return dataView.getFloat64(descriptor.offset, littleEndian);

				case sqlTypes.SQL_TYPE_TIME: {
					const now = new Date();
					const decodedTime = decodeTime(dataView.getUint32(descriptor.offset, littleEndian));
					return new Date(now.getFullYear(), now.getMonth(), now.getDate(),
						decodedTime.hours, decodedTime.minutes, decodedTime.seconds, decodedTime.fractions / 10);
				}

				case sqlTypes.SQL_TYPE_DATE: {
					const decodedDate = decodeDate(dataView.getInt32(descriptor.offset, littleEndian));
					return new Date(decodedDate.year, decodedDate.month - 1, decodedDate.day);
				}

				case sqlTypes.SQL_TIMESTAMP: {
					const decodedDate = decodeDate(dataView.getInt32(descriptor.offset, littleEndian));
					const decodedTime = decodeTime(dataView.getUint32(descriptor.offset + 4, littleEndian));
					return new Date(decodedDate.year, decodedDate.month - 1, decodedDate.day,
						decodedTime.hours, decodedTime.minutes, decodedTime.seconds, decodedTime.fractions / 10);
				}

				case sqlTypes.SQL_BOOLEAN:
					return dataView.getInt8(descriptor.offset) != 0;

				case sqlTypes.SQL_BLOB:
					return new Blob(attachment, buffer.slice(descriptor.offset, descriptor.offset + 8));

				case sqlTypes.SQL_NULL:
					return null;

				default:
					throw new Error(`Unrecognized Firebird type number ${descriptor.type}`);
			}
		}
	}

	return async (attachment: Attachment, transaction: Transaction, buffer: Uint8Array): Promise<any[]> => {
		return await Promise.all(mappers.map(mapper => mapper(attachment, transaction, buffer)));
	}
}


export type DataWriter = (attachment: Attachment, transaction: Transaction,
	buffer: Uint8Array, values: Array<any> | undefined) => Promise<void>;
export type ItemWriter = (attachment: Attachment, transaction: Transaction, buffer: Uint8Array, values: any) => Promise<void>;

/** Creates a data writer. */
export function createDataWriter(descriptors: Descriptor[]): DataWriter {
	const mappers = new Array<ItemWriter>(descriptors.length);

	for (let i = 0; i < descriptors.length; ++i) {
		const descriptor = descriptors[i];

		mappers[i] = async (attachment: Attachment, transaction: Transaction, buffer: Uint8Array, value: any): Promise<void> => {
			const dataView = new DataView(buffer.buffer);

			if (value == null) {
				dataView.setInt16(descriptor.nullOffset, -1, littleEndian);
				return;
			}

			switch (descriptor.type) {
				// SQL_TEXT is handled changing its descriptor to SQL_VARYING with IMetadataBuilder.
				case sqlTypes.SQL_VARYING: {
					//// TODO: none, octets
					const str = value as string;
					const strBuffer = Buffer.from(str);

					const bytesArray = Uint8Array.from(strBuffer);

					if (bytesArray.length > descriptor.length) {
						throw new Error(`Length in bytes of string '${str}' (${bytesArray.length}) is ` +
							`greater than maximum expect length ${descriptor.length}.`);
					}

					dataView.setUint16(descriptor.offset, bytesArray.length, littleEndian);

					for (let i = 0; i < bytesArray.length; ++i)
						buffer[descriptor.offset + 2 + i] = bytesArray[i];

					break;
				}

				/***
				case sqlTypes.SQL_SHORT:
					dataView.setInt16(descriptor.offset, changeScale(value, 0, descriptor.scale), littleEndian);
					break;

				case sqlTypes.SQL_LONG:
					dataView.setInt32(descriptor.offset, changeScale(value, 0, descriptor.scale), littleEndian);
					break;

				//// TODO: sqlTypes.SQL_INT64

				case sqlTypes.SQL_FLOAT:
					dataView.setFloat32(descriptor.offset, value, littleEndian);
					break;
				***/

				case sqlTypes.SQL_DOUBLE:
					dataView.setFloat64(descriptor.offset, value, littleEndian);
					break;

				case sqlTypes.SQL_TYPE_TIME: {
					const date = value as Date;
					dataView.setUint32(descriptor.offset,
						encodeTime(date.getHours(), date.getMinutes(), date.getSeconds(), date.getMilliseconds() * 10),
						littleEndian);
					break;
				}

				case sqlTypes.SQL_TYPE_DATE: {
					const date = value as Date;
					dataView.setInt32(descriptor.offset,
						encodeDate(date.getFullYear(), date.getMonth() + 1, date.getDate()),
						littleEndian);
					break;
				}

				case sqlTypes.SQL_TIMESTAMP: {
					const date = value as Date;
					dataView.setInt32(descriptor.offset,
						encodeDate(date.getFullYear(), date.getMonth() + 1, date.getDate()),
						littleEndian);
					dataView.setUint32(descriptor.offset + 4,
						encodeTime(date.getHours(), date.getMinutes(), date.getSeconds(), date.getMilliseconds() * 10),
						littleEndian);
					break;
				}

				case sqlTypes.SQL_BOOLEAN:
					dataView.setInt8(descriptor.offset, value ? 1 : 0);
					break;

				case sqlTypes.SQL_BLOB:
				{
					const targetBlobId = buffer.subarray(descriptor.offset, descriptor.offset + 8);

					if (value instanceof BlobStream)
						value = value.blob;

					if (value instanceof Buffer) {
						let blobStream = await attachment.createBlob(transaction);
						try {
							await blobStream.write(value);
						}
						catch (e) {
							await blobStream.cancel();
							throw e;
						}

						await blobStream.close();

						targetBlobId.set(blobStream.blob.id);
					}
					else if (value instanceof Blob) {
						if (value.attachment == attachment)
							targetBlobId.set(value.id);
						else
							throw new Error('Cannot pass a BLOB from another attachment as parameter.');	//// TODO: add support for it
					}
					else
						throw new Error('Unrecognized type used as BLOB. Must be: Buffer or Blob.');

					break;
				}

				case sqlTypes.SQL_NULL:
					break;

				default:
					throw new Error(`Unrecognized Firebird type number ${descriptor.type}`);
			}
		}
	}

	return async (attachment: Attachment, transaction: Transaction, buffer: Uint8Array, values: Array<any>): Promise<void> => {
		if ((values || []).length !== descriptors.length)
			throw new Error(`Incorrect number of parameters: expected ${descriptors.length}, received ${(values || []).length}.`);

		await Promise.all(mappers.map((mapper, index) => mapper(attachment, transaction, buffer, values[index])));
	}
}
