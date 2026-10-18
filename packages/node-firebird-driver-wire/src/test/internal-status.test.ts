import { describe, expect, test } from 'vitest';

import { gdscodes } from 'node-firebird-driver';
import { statusArgument } from '../lib/constants';
import { FirebirdWireError, assertSuccessfulResponse, parseStatusVector } from '../lib/status';

const { isc_cancelled, isc_dsql_error, isc_sqlerr, isc_dsql_token_unk_err, isc_random, isc_io_error } = gdscodes;

function int32(value: number): Buffer {
  const buffer = Buffer.alloc(4);
  buffer.writeInt32BE(value);
  return buffer;
}

function statusVector(parts: readonly Buffer[]): Buffer {
  return Buffer.concat([...parts, int32(statusArgument.end)]);
}

function gds(code: number): Buffer[] {
  return [int32(statusArgument.gds), int32(code)];
}

function stringArgument(value: string): Buffer[] {
  const buffer = Buffer.from(value, 'utf8');
  return [int32(statusArgument.string), int32(buffer.length), buffer];
}

function cstringArgument(value: string): Buffer[] {
  const buffer = Buffer.from(value, 'utf8');
  return [int32(statusArgument.cstring), int32(buffer.length), buffer];
}

function interpretedArgument(value: string): Buffer[] {
  const buffer = Buffer.from(value, 'utf8');
  return [int32(statusArgument.interpreted), int32(buffer.length), buffer];
}

function numberArgument(value: number): Buffer[] {
  return [int32(statusArgument.number), int32(value)];
}

function expectFirebirdErrorMessage(buffer: Buffer, expectedMessage: string): void {
  const status = parseStatusVector(buffer);

  try {
    assertSuccessfulResponse(status, 'Firebird operation failed');
    throw new Error('Expected FirebirdWireError.');
  } catch (error) {
    expect(error).toBeInstanceOf(FirebirdWireError);
    expect((error as Error).message).toBe(expectedMessage);
  }
}

describe('Firebird status vectors', () => {
  test('formats cancelled operation from imported core metadata', () => {
    expectFirebirdErrorMessage(statusVector([...gds(isc_cancelled)]), 'operation was cancelled');
  });

  test('formats multi-line Dynamic SQL token errors from imported core metadata', () => {
    expectFirebirdErrorMessage(
      statusVector([
        ...gds(isc_dsql_error),
        ...gds(isc_sqlerr),
        ...numberArgument(-104),
        ...gds(isc_dsql_token_unk_err),
        ...numberArgument(1),
        ...numberArgument(8),
        ...gds(isc_random),
        ...stringArgument('select'),
      ]),
      'Dynamic SQL Error\n-SQL error code = -104\n-Token unknown - line 1, column 8\n-select',
    );
  });

  test('falls back to raw detail for unknown GDS codes', () => {
    expectFirebirdErrorMessage(
      statusVector([...gds(1), ...stringArgument('raw detail'), ...numberArgument(12)]),
      'Firebird operation failed: gds=1 | raw detail | 12',
    );
  });

  test('substitutes mixed string and number template arguments', () => {
    expectFirebirdErrorMessage(
      statusVector([...gds(isc_io_error), ...cstringArgument('open'), ...numberArgument(7)]),
      'I/O error during "open" operation for file "7"',
    );
  });

  test('uses interpreted status text as a literal decoded message', () => {
    expectFirebirdErrorMessage(
      statusVector([...gds(isc_dsql_error), ...interpretedArgument('already formatted')]),
      'Dynamic SQL Error\n-already formatted',
    );
  });
});
