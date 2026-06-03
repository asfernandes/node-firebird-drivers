import { commonInfo, sqlTypes, statementInfo } from 'node-firebird-driver/dist/lib/impl';
import { describe, expect, test } from 'vitest';

import { parseStatementMetadata } from '../lib/statement-metadata';

function numericInfoItem(item: number, value: number): Buffer {
  const payload = Buffer.alloc(4);
  payload.writeInt32LE(value, 0);
  return Buffer.concat([Buffer.from([item, 4, 0]), payload]);
}

function describedColumnInfo(type: number, subType: number, length: number): Buffer {
  return Buffer.concat([
    numericInfoItem(statementInfo.sqlSqldaSeq, 1),
    numericInfoItem(statementInfo.sqlType, type),
    numericInfoItem(statementInfo.sqlSubType, subType),
    numericInfoItem(statementInfo.sqlLength, length),
    Buffer.from([statementInfo.sqlDescribeEnd]),
  ]);
}

describe('statement metadata', () => {
  test('parses statement type and flags without described columns', () => {
    const metadata = parseStatementMetadata(
      Buffer.concat([
        numericInfoItem(statementInfo.sqlStmtType, statementInfo.sqlStmtSelect),
        numericInfoItem(statementInfo.sqlStmtFlags, 1),
        Buffer.from([1]),
      ]),
    );

    expect(metadata.type).toBe(statementInfo.sqlStmtSelect);
    expect(metadata.flags).toBe(1);
    expect(metadata.inputColumns).toEqual([]);
    expect(metadata.outputColumns).toEqual([]);
    expect(metadata.inputMessageLength).toBe(0);
    expect(metadata.outputMessageLength).toBe(0);
  });

  test('builds charset-aware BLR for varying columns', () => {
    const metadata = parseStatementMetadata(
      Buffer.concat([
        Buffer.from([statementInfo.sqlSelect]),
        numericInfoItem(statementInfo.sqlDescribeVars, 1),
        describedColumnInfo(sqlTypes.SQL_VARYING, 4, 8),
        Buffer.from([commonInfo.end]),
      ]),
    );

    expect([...metadata.outputBlr]).toEqual([5, 2, 4, 0, 2, 0, 38, 4, 0, 8, 0, 7, 0, 255, 76]);
  });

  test('keeps NONE charset in generated BLR', () => {
    const metadata = parseStatementMetadata(
      Buffer.concat([
        Buffer.from([statementInfo.sqlBind]),
        numericInfoItem(statementInfo.sqlDescribeVars, 1),
        describedColumnInfo(sqlTypes.SQL_VARYING, 0, 10),
        Buffer.from([commonInfo.end]),
      ]),
    );

    expect([...metadata.inputBlr]).toEqual([5, 2, 4, 0, 2, 0, 38, 0, 0, 10, 0, 7, 0, 255, 76]);
  });
});
