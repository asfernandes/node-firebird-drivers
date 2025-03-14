import { Attachment, EventCallback, Master } from './cloop-gen';

import * as os from 'os';

/** Gets the default platform Firebird client library filename. */
export function getDefaultLibraryFilename(): string {
  switch (os.platform()) {
    case 'win32':
      return 'fbclient.dll';
    case 'darwin':
      return '/Library/Frameworks/Firebird.framework/Libraries/libfbclient.dylib';
    default:
      return 'libfbclient.so';
  }
}

// eslint-disable-next-line @typescript-eslint/no-require-imports
const native = require('bindings')('addon');

export const getMaster: (library: string) => Master = native.getMaster;
export const disposeMaster: (master: Master) => boolean = native.disposeMaster;

export const queueEvent: (
  client: Master,
  attachment: Attachment,
  names: string[],
  callBack: (counters: [string, number][]) => Promise<void>,
) => Promise<EventCallback> = native.queueEvent;

export const cancelEvent: (eventCallback: EventCallback) => Promise<void> = native.cancelEvent;

export * from './cloop-gen';
