import { describe, expect, test } from 'vitest';
import { createDpb, dpb } from '../lib/impl/fb-util';

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
