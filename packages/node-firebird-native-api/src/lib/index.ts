import { Master } from './cloop-gen';


const native = require('bindings')('addon');

export const getMaster: (library: string) => Master = native.getMaster;
export const disposeMaster: (master: Master) => boolean = native.disposeMaster;

export * from './cloop-gen';
