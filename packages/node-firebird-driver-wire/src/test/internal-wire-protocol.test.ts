import { describe, expect, test } from 'vitest';

import { sqlTypes } from 'node-firebird-driver/dist/lib/impl';

import { CursorHandle, WireProtocol } from '../lib/wire-protocol';
import { XdrParser, XdrWriter } from '../lib/xdr';

class FakeChannel {
  readonly writes: Buffer[] = [];
  private offset = 0;

  constructor(private readonly input: Buffer) {}

  async readExactly(length: number): Promise<Buffer> {
    if (this.offset + length > this.input.length) {
      throw new Error(`Fake channel ran out of data while reading ${length} bytes.`);
    }

    const value = this.input.subarray(this.offset, this.offset + length);
    this.offset += length;
    return value;
  }

  async write(buffer: Buffer): Promise<void> {
    this.writes.push(Buffer.from(buffer));
  }
}

function createPackedRow(value: number): Buffer {
  const row = Buffer.alloc(12);
  row.writeDoubleBE(value, 4);
  return row;
}

function createFetchResponse(status: number, value?: number): Buffer {
  const writer = new XdrWriter();
  writer.writeInt32(66);
  writer.writeInt32(status);
  writer.writeInt32(value === undefined ? 0 : 1);
  if (value !== undefined) {
    writer.writeBytes(createPackedRow(value));
  }
  return writer.toBuffer();
}

function createFetchTest(): {
  protocol: WireProtocol;
  cursor: CursorHandle;
  channel: FakeChannel;
} {
  const column = {
    alias: 'N1',
    field: 'N1',
    relation: 'T1',
    type: sqlTypes.SQL_DOUBLE,
    originalType: sqlTypes.SQL_LONG,
    subType: 0,
    charSet: 0,
    scale: 0,
    length: 8,
    nullable: false,
    offset: 0,
    nullOffset: 8,
  } as const;
  const channel = new FakeChannel(
    Buffer.concat([
      createFetchResponse(0, 1),
      createFetchResponse(0, 2),
      createFetchResponse(0, 3),
      createFetchResponse(0),
      createFetchResponse(0, 4),
      createFetchResponse(100),
    ]),
  );
  const protocol = new WireProtocol({ host: 'test', username: 'test', password: 'test' });
  const metadata = {
    type: 1,
    flags: 1,
    inputColumns: [],
    outputColumns: [column],
    inputBlr: Buffer.alloc(0),
    inputMessageLength: 0,
    outputBlr: Buffer.alloc(0),
    outputMessageLength: 10,
  };
  const internals = protocol as unknown as {
    channel: FakeChannel;
    attachmentHandle: number;
    statementMetadata: Map<number, unknown>;
  };
  internals.channel = channel;
  internals.attachmentHandle = 1;
  internals.statementMetadata = new Map([[1, metadata]]);

  return {
    protocol,
    cursor: {
      statement: { handle: 1 },
      transaction: { handle: 2 },
      columns: [column],
      fetchBlr: Buffer.alloc(0),
      fetchMessageLength: 10,
    },
    channel,
  };
}

describe('wire protocol cursor fetching', () => {
  test('buffers a fetch batch before issuing the next fetch request', async () => {
    const { protocol, cursor, channel } = createFetchTest();

    const row1 = await protocol.fetchNext(cursor);
    const row2 = await protocol.fetchNext(cursor);
    const row3 = await protocol.fetchNext(cursor);
    const row4 = await protocol.fetchNext(cursor);

    expect(row1?.readDoubleLE(0)).toBe(1);
    expect(row2?.readDoubleLE(0)).toBe(2);
    expect(row3?.readDoubleLE(0)).toBe(3);
    expect(row4?.readDoubleLE(0)).toBe(4);
    await expect(protocol.fetchNext(cursor)).resolves.toBeUndefined();
    expect(channel.writes).toHaveLength(2);

    for (const request of channel.writes) {
      const parser = new XdrParser(request);
      expect(parser.readInt32()).toBe(65);
      expect(parser.readInt32()).toBe(1);
      expect(parser.readBuffer()).toHaveLength(0);
      expect(parser.readInt32()).toBe(0);
      expect(parser.readInt32()).toBe(400);
    }
  });
});
