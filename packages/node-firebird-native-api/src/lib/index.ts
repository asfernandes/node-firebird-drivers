import { Master } from './cloop-gen';

import * as os from 'os';


/** Gets the default platform Firebird client library filename. */
export function getDefaultLibraryFilename(): string {
	switch (os.platform()) {
		case 'win32':
			return 'fbclient.dll';
		case 'darwin':
			return 'libfbclient.dylib';
		default:
			return 'libfbclient.so';
	}
}

const native = require('bindings')('addon');

export const getMaster: (library: string) => Master = native.getMaster;
export const disposeMaster: (master: Master) => boolean = native.disposeMaster;

export * from './cloop-gen';
