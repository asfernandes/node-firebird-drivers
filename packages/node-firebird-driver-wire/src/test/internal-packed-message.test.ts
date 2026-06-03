import { connect, createServer } from 'node:net';
import { once } from 'node:events';
import { describe, expect, test } from 'vitest';

import { sqlTypes } from 'node-firebird-driver/dist/lib/impl';

import { buildPackedMessage, readPackedMessageBuffer } from '../lib/packed-message';
import { StatementColumn } from '../lib/wire-protocol';
import { SocketChannel } from '../lib/socket-channel';

describe('packed message helpers', () => {
  test('round-trips a varying column through packed wire format', async () => {
    const column: StatementColumn = {
      alias: 'NAME',
      field: 'NAME',
      relation: 'T1',
      type: sqlTypes.SQL_VARYING,
      originalType: sqlTypes.SQL_VARYING,
      subType: 0,
      charSet: 4,
      scale: 0,
      length: 8,
      nullable: false,
      offset: 0,
      nullOffset: 10,
    };

    const message = Buffer.alloc(12);
    const view = new DataView(message.buffer, message.byteOffset, message.byteLength);
    const value = Buffer.from('abc', 'utf8');
    view.setUint16(column.offset, value.length, true);
    value.copy(message, column.offset + 2);
    view.setInt16(column.nullOffset, 0, true);

    const packed = buildPackedMessage([column], message.length, message);

    const server = createServer((socket) => {
      socket.end(packed);
    });

    server.listen(0, '127.0.0.1');
    await once(server, 'listening');

    const address = server.address();
    if (!address || typeof address === 'string') {
      throw new Error('Could not determine test server address.');
    }

    const socket = connect(address.port, '127.0.0.1');
    await once(socket, 'connect');

    try {
      const decoded = await readPackedMessageBuffer(new SocketChannel(socket), [column], message.length);
      expect(decoded).toEqual(message);
    } finally {
      socket.destroy();
      server.close();
      await once(server, 'close');
    }
  });
});
