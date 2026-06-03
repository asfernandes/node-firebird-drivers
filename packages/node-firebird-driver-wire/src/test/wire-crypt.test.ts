import { Buffer } from 'node:buffer';
import { createHash } from 'node:crypto';
import { describe, expect, test } from 'vitest';

import {
  ChaChaStreamCipher,
  createWireCryptSession,
  parseWireCryptPluginData,
  Rc4StreamCipher,
} from '../lib/wire-crypt';
import { writeTraditionalClumplet } from '../lib/xdr';

describe('wire crypt', () => {
  test('parses server wire crypt plugins in advertised order', () => {
    const keys = Buffer.concat([
      writeTraditionalClumplet(0, Buffer.from('Symmetric', 'latin1')),
      writeTraditionalClumplet(1, Buffer.from('ChaCha,Arc4', 'latin1')),
    ]);

    expect(parseWireCryptPluginData([keys])).toEqual([
      { keyType: 'Symmetric', pluginName: 'ChaCha', specificData: undefined },
      { keyType: 'Symmetric', pluginName: 'Arc4', specificData: undefined },
    ]);
  });

  test('selects the first supported server-advertised plugin', () => {
    const chaChaIv = Buffer.from('000000000000004a0000000000000001', 'hex');
    const keys = Buffer.concat([
      writeTraditionalClumplet(0, Buffer.from('Symmetric', 'latin1')),
      writeTraditionalClumplet(1, Buffer.from('ChaCha64,ChaCha,Arc4', 'latin1')),
      writeTraditionalClumplet(
        3,
        Buffer.concat([Buffer.from('ChaCha64\0', 'latin1'), Buffer.from('0000004a00000000', 'hex')]),
      ),
      writeTraditionalClumplet(3, Buffer.concat([Buffer.from('ChaCha\0', 'latin1'), chaChaIv])),
    ]);

    const session = createWireCryptSession([keys], Buffer.from('secret-session-key', 'utf8'));

    expect(session).toBeDefined();
    expect(session).toMatchObject({
      keyType: 'Symmetric',
      pluginName: 'ChaCha64',
    });
  });

  test('rc4 stream cipher decrypts chunked data with a matching peer state', () => {
    const plaintext = Buffer.from('Firebird wire crypt test payload', 'utf8');
    const sender = new Rc4StreamCipher(Buffer.from('secret-session-key', 'utf8'));
    const receiver = new Rc4StreamCipher(Buffer.from('secret-session-key', 'utf8'));

    const encrypted = Buffer.concat([
      sender.transform(plaintext.subarray(0, 10)),
      sender.transform(plaintext.subarray(10)),
    ]);

    const decrypted = Buffer.concat([
      receiver.transform(encrypted.subarray(0, 7)),
      receiver.transform(encrypted.subarray(7)),
    ]);

    expect(decrypted).toEqual(plaintext);
  });

  test('chacha stream cipher matches the RFC 7539 test vector', () => {
    const key = Buffer.from('000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f', 'hex');
    const nonce = Buffer.from('000000000000004a00000000', 'hex');
    const plaintext = Buffer.from(
      "Ladies and Gentlemen of the class of '99: If I could offer you only one tip for the future, sunscreen would be it.",
      'utf8',
    );
    const expected = Buffer.from(
      '6e2e359a2568f98041ba0728dd0d6981e97e7aec1d4360c20a27afccfd9fae0b' +
        'f91b65c5524733ab8f593dabcd62b3571639d624e65152ab8f530c359f0861d8' +
        '07ca0dbf500d6a6156a38e088a22b65e52bc514d16ccf806818ce91ab7793736' +
        '5af90bbf74a35be6b40b8eedf2785e42874d',
      'hex',
    );

    const cipher = new ChaChaStreamCipher(key, nonce, 1n, 32);
    const encrypted = Buffer.concat([
      cipher.transform(plaintext.subarray(0, 35)),
      cipher.transform(plaintext.subarray(35, 70)),
      cipher.transform(plaintext.subarray(70, 75)),
      cipher.transform(plaintext.subarray(75, 80)),
      cipher.transform(plaintext.subarray(80)),
    ]);

    expect(encrypted).toEqual(expected);
  });

  test('chacha64 stream cipher matches the libtomcrypt test vector', () => {
    const key = Buffer.from('000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f', 'hex');
    const nonce = Buffer.from('0000004a00000000', 'hex');
    const plaintext = Buffer.from(
      "Ladies and Gentlemen of the class of '99: If I could offer you only one tip for the future, sunscreen would be it.",
      'utf8',
    );
    const expected = Buffer.from(
      '6e2e359a2568f98041ba0728dd0d6981e97e7aec1d4360c20a27afccfd9fae0b' +
        'f91b65c5524733ab8f593dabcd62b3571639d624e65152ab8f530c359f0861d8' +
        '07ca0dbf500d6a6156a38e088a22b65e52bc514d16ccf806818ce91ab7793736' +
        '5af90bbf74a35be6b40b8eedf2785e42874d',
      'hex',
    );

    const cipher = new ChaChaStreamCipher(key, nonce, 1n, 64);
    expect(cipher.transform(plaintext)).toEqual(expected);
  });

  test('wire crypt chaCha session uses the hashed session key and iv', () => {
    const sessionKey = Buffer.from('secret-session-key', 'utf8');
    const iv = Buffer.from('0102030405060708090a0b0c00000000', 'hex');
    const keys = Buffer.concat([
      writeTraditionalClumplet(0, Buffer.from('Symmetric', 'latin1')),
      writeTraditionalClumplet(1, Buffer.from('ChaCha', 'latin1')),
      writeTraditionalClumplet(3, Buffer.concat([Buffer.from('ChaCha\0', 'latin1'), iv])),
    ]);

    const session = createWireCryptSession([keys], sessionKey)!;
    const reference = new ChaChaStreamCipher(
      createHash('sha256').update(sessionKey).digest(),
      iv.subarray(0, 12),
      0n,
      32,
    );
    const payload = Buffer.from('wire crypt payload', 'utf8');

    expect(session.pluginName).toBe('ChaCha');
    expect(session.outgoing.transform(payload)).toEqual(reference.transform(payload));
  });
});
