import { Master } from './cloop-gen';

import * as os from 'os';


/** Gets the default platform Firebird client library filename. */
export function getDefaultLibraryFilename(): string {
	return os.platform() == 'win32' ? 'fbclient.dll' : 'libfbclient.so';
}

const native = require('bindings')('addon');

export const getMaster: (library: string) => Master = native.getMaster;
export const disposeMaster: (master: Master) => boolean = native.disposeMaster;

export * from './cloop-gen';
