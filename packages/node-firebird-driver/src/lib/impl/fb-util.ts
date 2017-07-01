import { ConnectOptions, CreateDatabaseOptions } from '..';


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

/** Blob info. */
export namespace blobInfo {
	export const totalLength = 6;
}

export function createDpb(options?: ConnectOptions | CreateDatabaseOptions): Buffer {
	const code = (c: number) => String.fromCharCode(c);
	const charSet = 'utf8';
	let ret = `${code(dpb.isc_dpb_version1)}${code(dpb.lc_ctype)}${code(charSet.length)}${charSet}`;

	if (options) {
		if (options.username)
			ret += `${code(dpb.user_name)}${code(options.username.length)}${options.username}`;

		if (options.password)
			ret += `${code(dpb.password)}${code(options.password.length)}${options.password}`;
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
