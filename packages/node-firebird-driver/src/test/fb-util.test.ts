import { describe, expect, it, test } from 'vitest';

import {
  charSets,
  createDataReader,
  createDataWriter,
  createDpb,
  dpb,
  sqlTypes,
  type Descriptor,
} from '../lib/impl/fb-util';

describe('createDpb', () => {
  test('handles searchPath string and array options', () => {
    const bufString = createDpb({ username: 'sysdba', searchPath: 'SCHEMA1,SCHEMA2' });
    expect(bufString.includes(Buffer.from('SCHEMA1,SCHEMA2'))).toBeTruthy();
    expect(bufString.includes(Buffer.from([dpb.search_path, 'SCHEMA1,SCHEMA2'.length]))).toBeTruthy();

    const bufArray = createDpb({ username: 'sysdba', searchPath: [' SCHEMA1 ', 'SCHEMA2 ', ''] });
    expect(bufArray.includes(Buffer.from('SCHEMA1,SCHEMA2'))).toBeTruthy();
    expect(bufArray.includes(Buffer.from([dpb.search_path, 'SCHEMA1,SCHEMA2'.length]))).toBeTruthy();
  });

  test('throws error if searchPath length exceeds 255', () => {
    const longSearchPath = 'a'.repeat(256);
    expect(() => createDpb({ searchPath: longSearchPath })).toThrowError(
      'ConnectOptions.searchPath length cannot exceed 255.',
    );

    const longSearchPathArray = ['a'.repeat(130), 'b'.repeat(130)];
    expect(() => createDpb({ searchPath: longSearchPathArray })).toThrowError(
      'ConnectOptions.searchPath length cannot exceed 255.',
    );
  });
});

describe('fb-util', () => {
  it('preserves raw bytes for SQL_VARYING fields with OCTETS charset', async () => {
    const descriptor: Descriptor = {
      type: sqlTypes.SQL_VARYING,
      subType: 0,
      charSet: charSets.octets,
      length: 4,
      scale: 0,
      offset: 2,
      nullOffset: 0,
    };

    const buffer = new Uint8Array(16);
    const writer = createDataWriter([descriptor]);
    const reader = createDataReader([descriptor]);

    const expected = Buffer.from([0x00, 0x01, 0x02, 0x03]);

    await writer({} as any, {} as any, buffer, [expected]);

    const result = await reader({ charSetForNONE: 'utf8' } as any, {} as any, buffer);

    expect(Buffer.isBuffer(result[0])).toBe(true);
    expect(result[0]).toEqual(expected);
  });
});
