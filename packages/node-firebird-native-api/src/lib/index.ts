import { Master } from './cloop-gen';

import * as os from 'os';

// @ts-ignore
import binary from 'node-pre-gyp';
// @ts-ignore
import path from 'path';

const bindingPath = binary.find(path.resolve(path.join(__dirname, '../../package.json')));

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

const native = require(bindingPath)('addon');

export const getMaster: (library: string) => Master = native.getMaster;
export const disposeMaster: (master: Master) => boolean = native.disposeMaster;

export * from './cloop-gen';
