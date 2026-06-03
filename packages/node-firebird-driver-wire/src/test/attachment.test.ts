import { describe, expect, test } from 'vitest';

import { parseDatabaseUri } from '../lib/attachment';

describe('parseDatabaseUri', () => {
  test('preserves a hostless Windows drive path', () => {
    expect(parseDatabaseUri('C:\\data\\db.fdb')).toEqual({
      host: 'localhost',
      port: 3050,
      database: 'C:\\data\\db.fdb',
    });
  });

  test('still parses an explicit host and port before a Windows drive path', () => {
    expect(parseDatabaseUri('dbhost/3051:C:\\data\\db.fdb')).toEqual({
      host: 'dbhost',
      port: 3051,
      database: 'C:\\data\\db.fdb',
    });
  });

  test('parses standard inet:// URL-like connection strings', () => {
    expect(parseDatabaseUri('inet://192.168.0.11//db/mydb.fdb')).toEqual({
      host: '192.168.0.11',
      port: 3050,
      database: '/db/mydb.fdb',
    });

    expect(parseDatabaseUri('inet://192.168.0.11/C:\\db\\mydb.fdb')).toEqual({
      host: '192.168.0.11',
      port: 3050,
      database: 'C:\\db\\mydb.fdb',
    });

    expect(parseDatabaseUri('inet://myserver/C:\\db\\mydb.fdb')).toEqual({
      host: 'myserver',
      port: 3050,
      database: 'C:\\db\\mydb.fdb',
    });

    expect(parseDatabaseUri('inet://localhost//db/mydb.fdb')).toEqual({
      host: 'localhost',
      port: 3050,
      database: '/db/mydb.fdb',
    });

    expect(parseDatabaseUri('inet://192.168.0.11/mydb')).toEqual({
      host: '192.168.0.11',
      port: 3050,
      database: 'mydb',
    });

    expect(parseDatabaseUri('inet://myserver/mydb')).toEqual({
      host: 'myserver',
      port: 3050,
      database: 'mydb',
    });

    expect(parseDatabaseUri('inet://localhost/mydb')).toEqual({
      host: 'localhost',
      port: 3050,
      database: 'mydb',
    });
  });

  test('parses inet:// URL-like connection strings with non-default ports', () => {
    expect(parseDatabaseUri('inet://192.168.0.11:3051/C:\\db\\mydb.fdb')).toEqual({
      host: '192.168.0.11',
      port: 3051,
      database: 'C:\\db\\mydb.fdb',
    });

    expect(parseDatabaseUri('inet://192.168.0.11:3051/mydb')).toEqual({
      host: '192.168.0.11',
      port: 3051,
      database: 'mydb',
    });

    expect(parseDatabaseUri('inet://myserver:3051//db/mydb.fdb')).toEqual({
      host: 'myserver',
      port: 3051,
      database: '/db/mydb.fdb',
    });

    expect(parseDatabaseUri('inet://localhost:3051//db/mydb.fdb')).toEqual({
      host: 'localhost',
      port: 3051,
      database: '/db/mydb.fdb',
    });
  });

  test('parses inet4:// and inet6:// URL-like connection strings', () => {
    expect(parseDatabaseUri('inet4://myserver/mydb')).toEqual({
      host: 'myserver',
      port: 3050,
      database: 'mydb',
    });

    expect(parseDatabaseUri('inet6://myserver/mydb')).toEqual({
      host: 'myserver',
      port: 3050,
      database: 'mydb',
    });
  });

  test('parses hostless inet:// URL-like connection strings', () => {
    expect(parseDatabaseUri('inet:///db/mydb.fdb')).toEqual({
      host: 'localhost',
      port: 3050,
      database: '/db/mydb.fdb',
    });

    expect(parseDatabaseUri('inet://C:\\db\\mydb.fdb')).toEqual({
      host: 'localhost',
      port: 3050,
      database: 'C:\\db\\mydb.fdb',
    });

    expect(parseDatabaseUri('inet://mydb')).toEqual({
      host: 'localhost',
      port: 3050,
      database: 'mydb',
    });
  });
});
