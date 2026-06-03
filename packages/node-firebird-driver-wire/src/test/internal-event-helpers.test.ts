import { describe, expect, test } from 'vitest';

import { buildEventBlock, calculateEventCounts, getEventHost, parseAuxiliaryPort } from '../lib/event-helpers';

describe('event helpers', () => {
  test('builds an event block with encoded names and initial counters', () => {
    const block = buildEventBlock(['EVENT1', 'EVENT2']);

    expect(block[0]).toBe(1);
    expect(block[1]).toBe(6);
    expect(block.subarray(2, 8).toString('utf8')).toBe('EVENT1');
    expect(block.readUInt32LE(8)).toBe(1);
  });

  test('calculates counter deltas from event buffers', () => {
    const previous = buildEventBlock(['EVENT1', 'EVENT2']);
    const current = Buffer.from(previous);

    current.writeUInt32LE(1 + 3, 8);
    current.writeUInt32LE(1 + 5, 19);

    expect(calculateEventCounts(previous, current, ['EVENT1', 'EVENT2'])).toEqual([
      ['EVENT1', 3],
      ['EVENT2', 5],
    ]);
  });

  test('parses the auxiliary event port and normalizes ipv4-mapped addresses', () => {
    const address = Buffer.from([127, 0, 0x0b, 0xec]);

    expect(parseAuxiliaryPort(address)).toBe(3052);
    expect(getEventHost('::ffff:192.168.1.20', 'dbhost')).toBe('192.168.1.20');
    expect(getEventHost(undefined, 'dbhost')).toBe('dbhost');
  });
});
