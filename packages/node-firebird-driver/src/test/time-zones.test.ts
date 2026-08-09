import { describe, expect, test } from 'vitest';
import { tzIdToString, tzStringToId } from '../lib/impl/time-zones';

describe('time zones', () => {
  test('converts numeric timezone offsets to and from Firebird IDs', () => {
    expect(tzStringToId('-03:00')).toBe(1259);
    expect(tzStringToId('+05:30')).toBe(1769);
    expect(tzStringToId('+14:00')).toBe(2279);
    expect(tzStringToId('-14:00')).toBe(599);

    expect(tzIdToString(1259)).toBe('-03:00');
    expect(tzIdToString(1769)).toBe('+05:30');
    expect(tzIdToString(2279)).toBe('+14:00');
    expect(tzIdToString(599)).toBe('-14:00');
  });

  test('rejects numeric timezone offsets outside Firebird limits', () => {
    expect(() => tzStringToId('+14:01')).toThrowError('Invalid time zone.');
    expect(() => tzStringToId('-15:00')).toThrowError('Invalid time zone.');
    expect(() => tzIdToString(598)).toThrowError('Invalid time zone ID.');
    expect(() => tzIdToString(2280)).toThrowError('Invalid time zone ID.');
  });
});
