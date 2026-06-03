import { dpb } from 'node-firebird-driver/dist/lib/impl';
import { describe, expect, test } from 'vitest';

import {
  buildAttachmentDpb,
  buildRemainingPluginList,
  normalizeLogin,
  readDpbClumplets,
  writeMultiPartConnectParameter,
} from '../lib/auth-helpers';
import { writeTraditionalClumplet } from '../lib/xdr';

describe('auth helpers', () => {
  test('normalizes quoted and unquoted logins', () => {
    expect(normalizeLogin('sysdba')).toBe('SYSDBA');
    expect(normalizeLogin('"CaseSensitive""User"')).toBe('CaseSensitive"User');
  });

  test('builds the remaining authentication plugin list', () => {
    expect(buildRemainingPluginList('Srp')).toBe('Srp,Legacy_Auth');
    expect(buildRemainingPluginList('Legacy_Auth')).toBe('Legacy_Auth');
  });

  test('reads traditional DPB clumplets and appends auth data when needed', () => {
    const baseDpb = Buffer.concat([
      Buffer.from([dpb.version1]),
      writeTraditionalClumplet(dpb.user_name, Buffer.from('sysdba', 'ascii')),
    ]);

    expect(readDpbClumplets(baseDpb)).toEqual([
      {
        tag: dpb.user_name,
        value: Buffer.from('sysdba', 'ascii'),
      },
    ]);

    const attachmentDpb = buildAttachmentDpb(baseDpb, Buffer.from([1, 2, 3]), 'Srp');
    expect(attachmentDpb[0]).toBe(dpb.version2);

    const clumplets = readDpbClumplets(attachmentDpb);
    expect(clumplets.some(({ tag }) => tag === dpb.utf8_filename)).toBe(true);
    expect(clumplets.find(({ tag }) => tag === dpb.auth_plugin_name)?.value.toString('utf8')).toBe('Srp');
    expect(clumplets.find(({ tag }) => tag === dpb.auth_plugin_list)?.value.toString('utf8')).toBe('Srp,Legacy_Auth');
    expect(clumplets.find(({ tag }) => tag === dpb.specific_auth_data)?.value).toEqual(Buffer.from([1, 2, 3]));
  });

  test('splits multi-part connect parameters into numbered clumplets', () => {
    const payload = Buffer.alloc(300, 7);
    const multipart = writeMultiPartConnectParameter(11, payload);

    expect(multipart[0]).toBe(11);
    expect(multipart[2]).toBe(0);

    const secondHeaderOffset = 3 + 254;
    expect(multipart[secondHeaderOffset]).toBe(11);
    expect(multipart[secondHeaderOffset + 2]).toBe(1);
  });
});
