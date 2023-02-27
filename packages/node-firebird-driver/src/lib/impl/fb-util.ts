import * as os from 'os';
const littleEndian = os.endianness() === 'LE';

import * as stringDecoder from 'string_decoder';

import { AbstractAttachment } from './attachment';
import { AbstractTransaction } from './transaction';
import { decodeDate, decodeTime, encodeDate, encodeTime } from './date-time';
import { tzIdToString, tzStringToId } from './time-zones';

import {
	Attachment,
	Blob,
	BlobStream,
	ConnectOptions,
	CreateBlobOptions,
	CreateDatabaseOptions,
	Transaction,
	TransactionIsolation,
	TransactionOptions,
	ZonedDate,
	ZonedDateEx
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
	export const SQL_TIMESTAMP_TZ_EX = 32748;
	export const SQL_TIME_TZ_EX = 32750;
	export const SQL_TIMESTAMP_TZ = 32754;
	export const SQL_TIME_TZ = 32756;
	export const SQL_INT128 = 32752;
	export const SQL_DEC16 = 32760;
	export const SQL_DEC34 = 32762;
	export const SQL_BOOLEAN = 32764;
	export const SQL_NULL = 32766;
}

/** DPB constants. */
export namespace dpb {
	/* tslint:disable */
	export const version1 = 1;
	export const lc_ctype = 48;
	export const force_write = 24;
	export const user_name = 28;
	export const password = 29;
	export const sql_role_name = 60;
	/* tslint:enable */
}

/** TPB constants. */
export namespace tpb {
	/* tslint:disable */
	export const version1 = 1;
	export const consistency = 1;
	export const concurrency = 2;
	export const wait = 6;
	export const nowait = 7;
	export const read = 8;
	export const write = 9;
	export const ignore_limbo = 14;
	export const read_committed = 15;
	export const autocommit = 16;
	export const rec_version = 17;
	export const no_rec_version = 18;
	export const restart_requests = 19;
	export const no_auto_undo = 20;
	/* tslint:enable */
}

/** BPB constants. */
export namespace bpb {
	/* tslint:disable */
	export const version1 = 1;
	export const source_type = 1;
	export const target_type = 2;
	export const type = 3;
	export const source_interp = 4;
	export const target_interp = 5;
	export const filter_parameter = 6;
	export const storage = 7;

	export const type_segmented = 0x0;
	export const type_stream = 0x1;
	export const storage_main = 0x0;
	export const storage_temp = 0x2;
	/* tslint:enable */
}

/** EPB constants. */
export namespace epb {
	/* tslint:disable */
	export const version1 = 1;
	/* tslint:enable */
}

/** Blob info. */
export namespace blobInfo {
	export const totalLength = 6;
}

/** Statement info. */
export namespace statementInfo {
	export const sqlExecPathBlrText = 32;
}

/** Common info. */
export namespace commonInfo {
	export const end = 1;
	export const truncated = 2;
	export const error = 3;
	export const dataNotReady = 4;
	export const length = 126;
	export const flagEnd = 127;
}

export namespace cancelType {
	export const disable = 1;
	export const enable = 2;
	export const raise = 3;
	export const abort = 4;
}

export namespace charSets {
	export const ascii = 2;
}

export function createDpb(options?: ConnectOptions | CreateDatabaseOptions): Buffer {
	const code = (c: number) => String.fromCharCode(c);
	const charSet = 'utf8';
	let ret = `${code(dpb.version1)}${code(dpb.lc_ctype)}${code(charSet.length)}${charSet}`;

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

	if (options.role)
		ret += `${code(dpb.sql_role_name)}${code(options.role.length)}${options.role}`;

	const createOptions = options as CreateDatabaseOptions;

	if (createOptions.forcedWrite != undefined)
		ret += `${code(dpb.force_write)}${code(1)}${code(createOptions.forcedWrite ? 1 : 0)}`;

	return Buffer.from(ret);
}

export function createTpb(options?: TransactionOptions): Buffer {
	const code = (c: number) => String.fromCharCode(c);
	let ret = code(tpb.version1);

	if (!options)
		options = {};

	switch (options.accessMode) {
		case 'READ_ONLY':
			ret += code(tpb.read);
			break;

		case 'READ_WRITE':
			ret += code(tpb.write);
			break;
	}

	switch (options.waitMode) {
		case 'NO_WAIT':
			ret += code(tpb.nowait);
			break;

		case 'WAIT':
			ret += code(tpb.wait);
			break;
	}

	switch (options.isolation) {
		case TransactionIsolation.CONSISTENCY:
			ret += code(tpb.consistency);
			break;

		case TransactionIsolation.SNAPSHOT:
			ret += code(tpb.concurrency);
			break;

		case TransactionIsolation.READ_COMMITTED:
			ret += code(tpb.read_committed) +
				code(options.readCommittedMode == 'RECORD_VERSION' ? tpb.rec_version : tpb.no_rec_version);
			break;
	}

	if (options.noAutoUndo)
		ret += code(tpb.no_auto_undo);

	if (options.ignoreLimbo)
		ret += code(tpb.ignore_limbo);

	if (options.restartRequests)
		ret += code(tpb.restart_requests);

	if (options.autoCommit)
		ret += code(tpb.autocommit);

	return Buffer.from(ret);
}

export function createBpb(options?: CreateBlobOptions): Buffer {
	const code = (c: number) => String.fromCharCode(c);
	let ret = code(bpb.version1);

	if (!options)
		options = {};

	switch (options.type) {
		case 'SEGMENTED':
			ret += `${code(bpb.type)}${code(1)}${code(bpb.type_segmented)}`;
			break;

		case 'STREAM':
			ret += `${code(bpb.type)}${code(1)}${code(bpb.type_stream)}`;
			break;
	}

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

				case sqlTypes.SQL_TIME_TZ_EX: {
					const now = new Date();
					const decodedTime = decodeTime(dataView.getUint32(descriptor.offset, littleEndian));
					const date = new Date(Date.UTC(now.getUTCFullYear(), now.getUTCMonth(), now.getUTCDate(),
						decodedTime.hours, decodedTime.minutes, decodedTime.seconds, decodedTime.fractions / 10));
					const timeZone = tzIdToString(dataView.getUint16(descriptor.offset + 4, littleEndian));
					const offset = dataView.getInt16(descriptor.offset + 6, littleEndian);

					return {
						date,
						timeZone,
						offset
					} as ZonedDateEx;
				}

				case sqlTypes.SQL_TYPE_DATE: {
					const decodedDate = decodeDate(dataView.getInt32(descriptor.offset, littleEndian));

					if (decodedDate.year >= 100)
						return new Date(decodedDate.year, decodedDate.month - 1, decodedDate.day);
					else {
						const date = new Date(2000, decodedDate.month - 1, decodedDate.day);
						date.setFullYear(decodedDate.year);
						return date;
					}
				}

				case sqlTypes.SQL_TIMESTAMP: {
					const decodedDate = decodeDate(dataView.getInt32(descriptor.offset, littleEndian));
					const decodedTime = decodeTime(dataView.getUint32(descriptor.offset + 4, littleEndian));

					if (decodedDate.year >= 100) {
						return new Date(decodedDate.year, decodedDate.month - 1, decodedDate.day,
							decodedTime.hours, decodedTime.minutes, decodedTime.seconds, decodedTime.fractions / 10);
					}
					else {
						const date = new Date(2000, decodedDate.month - 1, decodedDate.day,
							decodedTime.hours, decodedTime.minutes, decodedTime.seconds, decodedTime.fractions / 10);
						date.setFullYear(decodedDate.year);
						return date;
					}
				}

				case sqlTypes.SQL_TIMESTAMP_TZ_EX: {
					const decodedDate = decodeDate(dataView.getInt32(descriptor.offset, littleEndian));
					const decodedTime = decodeTime(dataView.getUint32(descriptor.offset + 4, littleEndian));
					const timeZone = tzIdToString(dataView.getUint16(descriptor.offset + 8, littleEndian));
					const offset = dataView.getInt16(descriptor.offset + 10, littleEndian);
					let date: Date;

					if (decodedDate.year >= 100) {
						date = new Date(Date.UTC(decodedDate.year, decodedDate.month - 1, decodedDate.day,
							decodedTime.hours, decodedTime.minutes, decodedTime.seconds, decodedTime.fractions / 10));
					}
					else {
						date = new Date(Date.UTC(2000, decodedDate.month - 1, decodedDate.day,
							decodedTime.hours, decodedTime.minutes, decodedTime.seconds, decodedTime.fractions / 10));
						date.setUTCFullYear(decodedDate.year);
					}

					return {
						date,
						timeZone,
						offset
					} as ZonedDateEx;
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
		};
	}

	return async (attachment: Attachment, transaction: Transaction, buffer: Uint8Array): Promise<any[]> => {
		return await Promise.all(mappers.map(mapper => mapper(attachment, transaction, buffer)));
	};
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

			dataView.setInt16(descriptor.nullOffset, 0, littleEndian);

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

					for (let j = 0; j < bytesArray.length; ++j)
						buffer[descriptor.offset + 2 + j] = bytesArray[j];

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

				case sqlTypes.SQL_TIME_TZ:
				case sqlTypes.SQL_TIME_TZ_EX: {
					const zonedDate = value as ZonedDate;
					dataView.setUint32(descriptor.offset,
						encodeTime(zonedDate.date.getUTCHours(), zonedDate.date.getUTCMinutes(), zonedDate.date.getUTCSeconds(),
							zonedDate.date.getUTCMilliseconds() * 10),
						littleEndian);
					dataView.setUint16(descriptor.offset + 4, tzStringToId(zonedDate.timeZone), littleEndian);
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

				case sqlTypes.SQL_TIMESTAMP_TZ:
				case sqlTypes.SQL_TIMESTAMP_TZ_EX: {
					const zonedDate = value as ZonedDate;
					dataView.setInt32(descriptor.offset,
						encodeDate(zonedDate.date.getUTCFullYear(), zonedDate.date.getUTCMonth() + 1, zonedDate.date.getUTCDate()),
						littleEndian);
					dataView.setUint32(descriptor.offset + 4,
						encodeTime(zonedDate.date.getUTCHours(), zonedDate.date.getUTCMinutes(), zonedDate.date.getUTCSeconds(),
							zonedDate.date.getUTCMilliseconds() * 10),
						littleEndian);
					dataView.setUint16(descriptor.offset + 8, tzStringToId(zonedDate.timeZone), littleEndian);
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
						const blobStream = await attachment.createBlob(transaction);
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
		};
	}

	return async (attachment: Attachment, transaction: Transaction, buffer: Uint8Array, values: Array<any>): Promise<void> => {
		if ((values || []).length !== descriptors.length)
			throw new Error(`Incorrect number of parameters: expected ${descriptors.length}, received ${(values || []).length}.`);

		await Promise.all(mappers.map((mapper, index) => mapper(attachment, transaction, buffer, values[index])));
	};
}
