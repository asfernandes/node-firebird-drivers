import { BlobSeekWhence } from 'node-firebird-driver';
import { blobInfo } from 'node-firebird-driver/dist/lib/impl';
import { describe, expect, test, vi } from 'vitest';

import { BlobStreamImpl } from '../lib/blob';

describe('BlobStreamImpl', () => {
  test('seeks relative to the current write position', async () => {
    const protocol = {
      createBlob: vi.fn().mockResolvedValue({
        handle: 1,
        id: Buffer.alloc(8),
      }),
      putSegment: vi.fn().mockResolvedValue(undefined),
      seekBlob: vi.fn().mockResolvedValue(4),
    };

    const attachment = {
      protocol,
      isValid: true,
    } as any;

    const transaction = {
      transactionHandle: {
        handle: 1,
      },
    } as any;

    const blobStream = await BlobStreamImpl.create(attachment, transaction);

    await blobStream.write(Buffer.from('12345'));
    expect(await blobStream.seek(-1, BlobSeekWhence.CURRENT)).toBe(4);

    expect(protocol.putSegment).toHaveBeenCalledTimes(1);
    expect(protocol.seekBlob).toHaveBeenCalledWith(blobStream.blobHandle, BlobSeekWhence.START, 4);
  });

  test('reads an inline blob from cache without opening it remotely', async () => {
    const protocol = {
      findInlineBlob: vi.fn().mockReturnValue({
        transactionHandle: 7,
        blobId: Buffer.alloc(8, 1),
        info: Buffer.from([blobInfo.totalLength, 2, 0, 5, 0, 0, 0]),
        data: Buffer.from([5, 0, 104, 101, 108, 108, 111]),
      }),
      openBlob: vi.fn(),
    };

    const attachment = {
      protocol,
      isValid: true,
    } as any;

    const transaction = {
      transactionHandle: {
        handle: 7,
      },
    } as any;

    const blob = {
      id: Buffer.alloc(8, 1),
    } as any;

    const blobStream = await BlobStreamImpl.open(attachment, transaction, blob);
    const buffer = Buffer.alloc(8);

    expect(await blobStream.length).toBe(5);
    expect(await blobStream.read(buffer)).toBe(5);
    expect(buffer.subarray(0, 5).toString('ascii')).toBe('hello');
    expect(await blobStream.read(buffer)).toBe(-1);
    expect(protocol.openBlob).not.toHaveBeenCalled();
  });
});
