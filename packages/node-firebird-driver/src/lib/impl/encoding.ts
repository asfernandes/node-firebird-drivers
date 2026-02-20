interface IconvLiteModule {
  encodingExists(encoding: string): boolean;
  decode(buffer: Buffer, encoding: string): string;
  encode(value: string, encoding: string): Buffer;
}

let iconvLite: IconvLiteModule | undefined;
let iconvLiteLoadAttempted = false;

function getIconvLite(encoding: string): IconvLiteModule {
  if (!iconvLiteLoadAttempted) {
    iconvLiteLoadAttempted = true;

    try {
      // eslint-disable-next-line @typescript-eslint/no-require-imports
      iconvLite = require('iconv-lite') as IconvLiteModule;
    } catch {
      iconvLite = undefined;
    }
  }

  if (!iconvLite) {
    throw new Error(
      `Encoding '${encoding}' in charSetForNONE requires optional dependency 'iconv-lite'. ` +
        `Install it with: yarn add iconv-lite`,
    );
  }

  return iconvLite;
}

export function decodeString(bytes: Buffer, encoding: string): string {
  if (Buffer.isEncoding(encoding as BufferEncoding)) {
    return bytes.toString(encoding as BufferEncoding);
  }

  const iconvLiteModule = getIconvLite(encoding);

  if (iconvLiteModule.encodingExists(encoding)) {
    return iconvLiteModule.decode(bytes, encoding);
  }

  throw new Error(`Unknown encoding name '${encoding}' in charSetForNONE option.`);
}

export function encodeString(value: string, encoding: string): Buffer {
  if (Buffer.isEncoding(encoding as BufferEncoding)) {
    return Buffer.from(value, encoding as BufferEncoding);
  }

  const iconvLiteModule = getIconvLite(encoding);

  if (iconvLiteModule.encodingExists(encoding)) {
    return iconvLiteModule.encode(value, encoding);
  }

  throw new Error(`Unknown encoding name '${encoding}' in charSetForNONE option.`);
}
