import { createBpb, dpb, tpb } from '../../../node-firebird-driver/src/lib/impl/fb-util';
import { beforeAll, describe, expect, test } from 'vitest';
import {
  ensureDriverTestTmpDir,
  getDriverTestDatabasePath,
  loadDriverTestConfig,
} from '../../../node-firebird-driver/src/test/test-config';
import { legacyHash } from '../lib/auth/legacy-hash';
import { WireProtocol } from '../lib/wire-protocol';
import { writeTraditionalClumplet } from '../lib/xdr';

describe('node-firebird-driver-wire', () => {
  const testConfig = loadDriverTestConfig();
  const username = testConfig.username!;
  const validPassword = testConfig.password!;
  const host = testConfig.host!;
  const port = testConfig.port!;

  function createAttachDpb(): Buffer {
    return Buffer.concat([
      Buffer.from([dpb.version1]),
      writeTraditionalClumplet(dpb.user_name, Buffer.from(username, 'utf8')),
      writeTraditionalClumplet(dpb.lc_ctype, Buffer.from('UTF8', 'ascii')),
      writeTraditionalClumplet(dpb.utf8_filename, Buffer.alloc(0)),
    ]);
  }

  function createDatabaseDpb(overwrite = false): Buffer {
    const pageSize = Buffer.alloc(4);
    pageSize.writeUInt32LE(4096, 0);

    return Buffer.concat([
      Buffer.from([dpb.version1]),
      writeTraditionalClumplet(dpb.user_name, Buffer.from(username, 'utf8')),
      writeTraditionalClumplet(dpb.lc_ctype, Buffer.from('UTF8', 'ascii')),
      writeTraditionalClumplet(dpb.sql_dialect, Buffer.from([3])),
      writeTraditionalClumplet(dpb.page_size, pageSize),
      writeTraditionalClumplet(dpb.overwrite, Buffer.from([overwrite ? 1 : 0])),
      writeTraditionalClumplet(dpb.utf8_filename, Buffer.alloc(0)),
    ]);
  }

  function createTpb(): Buffer {
    return Buffer.from([tpb.version1, tpb.concurrency, tpb.wait, tpb.write]);
  }

  function decodePackedBlobSegments(buffer: Buffer): Buffer[] {
    const segments: Buffer[] = [];
    let offset = 0;

    while (offset + 2 <= buffer.length) {
      const length = buffer.readUInt16LE(offset);
      offset += 2;

      if (offset + length > buffer.length) {
        throw new Error('Invalid packed blob segment buffer.');
      }

      segments.push(Buffer.from(buffer.subarray(offset, offset + length)));
      offset += length;
    }

    if (offset !== buffer.length) {
      throw new Error('Packed blob segment buffer has trailing bytes.');
    }

    return segments;
  }

  function createProtocol(password = validPassword): WireProtocol {
    return new WireProtocol({
      host,
      port,
      username,
      password,
    });
  }

  beforeAll(() => {
    ensureDriverTestTmpDir(testConfig);
  });

  async function withCreatedDatabase<T>(name: string, callback: (database: string) => Promise<T>): Promise<T> {
    const uniqueName = `${name.replace(/\.fdb$/i, '')}-${process.pid}-${Date.now()}-${Math.random()
      .toString(16)
      .slice(2)}.fdb`;
    const database = getDriverTestDatabasePath(testConfig, uniqueName);
    const createProtocolInstance = createProtocol(validPassword);
    const createdAttachment = await createProtocolInstance.createDatabase(database, createDatabaseDpb(true));

    try {
      await createProtocolInstance.detach(createdAttachment);
    } finally {
      await createProtocolInstance.close();
    }

    try {
      return await callback(database);
    } finally {
      const dropProtocol = createProtocol(validPassword);
      try {
        const attachment = await dropProtocol.attach(database, createAttachDpb());
        await dropProtocol.dropDatabase(attachment);
      } finally {
        await dropProtocol.close();
      }
    }
  }

  test('creates, attaches and detaches to a real Firebird database', async () => {
    await withCreatedDatabase('wire-create-attach-detach.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const wireAttachment = await wireProtocol.attach(database, createAttachDpb());
        expect(wireAttachment.handle).toBeGreaterThanOrEqual(0);
        await wireProtocol.detach(wireAttachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('pings a real Firebird database connection', async () => {
    await withCreatedDatabase('wire-ping.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const wireAttachment = await wireProtocol.attach(database, createAttachDpb());
        await expect(wireProtocol.ping()).resolves.toBeUndefined();
        await wireProtocol.detach(wireAttachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('starts a transaction with a TPB', async () => {
    await withCreatedDatabase('wire-start-transaction.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());
        expect(transaction.handle).toBeGreaterThanOrEqual(0);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('commits and rolls back transactions', async () => {
    await withCreatedDatabase('wire-commit-rollback-transaction.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction1 = await wireProtocol.startTransaction(createTpb());
        expect(transaction1.handle).toBeGreaterThanOrEqual(0);
        await wireProtocol.commit(transaction1);

        const transaction2 = await wireProtocol.startTransaction(createTpb());
        expect(transaction2.handle).toBeGreaterThanOrEqual(0);
        await wireProtocol.rollback(transaction2);

        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('commits and rolls back retaining transactions', async () => {
    await withCreatedDatabase('wire-retaining-transaction.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());

        const transaction1 = await wireProtocol.startTransaction(createTpb());
        expect(transaction1.handle).toBeGreaterThanOrEqual(0);
        await wireProtocol.commitRetaining(transaction1);
        await wireProtocol.rollback(transaction1);

        const transaction2 = await wireProtocol.startTransaction(createTpb());
        expect(transaction2.handle).toBeGreaterThanOrEqual(0);
        await wireProtocol.rollbackRetaining(transaction2);
        await wireProtocol.commit(transaction2);

        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('allocates, prepares and frees a statement', async () => {
    await withCreatedDatabase('wire-prepare-statement.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());
        const statement = await wireProtocol.allocateStatement();

        await wireProtocol.prepareStatement(transaction, statement, 'create table t1 (n1 integer)');
        await wireProtocol.freeStatement(statement);
        await wireProtocol.rollback(transaction);
        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('executes a prepared statement without a result set', async () => {
    await withCreatedDatabase('wire-execute-statement.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());
        const statement1 = await wireProtocol.allocateStatement();
        const statement2 = await wireProtocol.allocateStatement();

        try {
          await wireProtocol.prepareStatement(transaction, statement1, 'create table t1 (n1 integer)');
          await wireProtocol.executeStatement(transaction, statement1);

          await wireProtocol.prepareStatement(transaction, statement2, 'create table t1 (n1 integer)');
          await expect(wireProtocol.executeStatement(transaction, statement2)).rejects.toThrow(/Firebird|exist/);
        } finally {
          await wireProtocol.freeStatement(statement2);
          await wireProtocol.freeStatement(statement1);
        }

        await wireProtocol.rollback(transaction);
        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('queues and receives asynchronous events', async () => {
    await withCreatedDatabase('wire-events.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());
        const statement = await wireProtocol.allocateStatement();
        let resolveCounters: (value: [string, number][]) => void = undefined!;
        let rejectCounters: (reason?: unknown) => void = undefined!;
        const countersPromise = new Promise<[string, number][]>((resolve, reject) => {
          resolveCounters = resolve;
          rejectCounters = reject;
        });
        const timeout = setTimeout(() => {
          rejectCounters(new Error('Timed out waiting for Firebird events.'));
        }, 5000);

        const eventHandle = await wireProtocol.queueEvents(['EVENT1', 'EVENT2'], (counters) => {
          if (counters.some(([, count]) => count > 0)) {
            clearTimeout(timeout);
            resolveCounters(counters);
          }
        });

        try {
          await wireProtocol.prepareStatement(
            transaction,
            statement,
            `
              execute block as
              begin
                post_event 'EVENT1';
                post_event 'EVENT1';
                post_event 'EVENT2';
              end
            `,
          );
          await wireProtocol.executeStatement(transaction, statement);
          await wireProtocol.commit(transaction);
          await expect(countersPromise).resolves.toStrictEqual([
            ['EVENT1', 2],
            ['EVENT2', 1],
          ]);
        } finally {
          clearTimeout(timeout);
          await wireProtocol.freeStatement(statement);
          await wireProtocol.cancelEvents(eventHandle);
          await wireProtocol.detach(attachment);
        }
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('opens a cursor for a prepared select and fetches raw messages', async () => {
    await withCreatedDatabase('wire-select-cursor.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());
        const ddlStatement = await wireProtocol.allocateStatement();
        const insertStatement = await wireProtocol.allocateStatement();
        const selectStatement = await wireProtocol.allocateStatement();

        try {
          await wireProtocol.prepareStatement(transaction, ddlStatement, 'create table t1 (n1 integer)');
          await wireProtocol.executeStatement(transaction, ddlStatement);
          await wireProtocol.commitRetaining(transaction);

          await wireProtocol.prepareStatement(
            transaction,
            insertStatement,
            'execute block as begin insert into t1 (n1) values (1); insert into t1 (n1) values (2); end',
          );
          await wireProtocol.executeStatement(transaction, insertStatement);

          await wireProtocol.prepareStatement(transaction, selectStatement, 'select n1 from t1 order by n1');

          const cursor = await wireProtocol.openCursor(transaction, selectStatement);
          expect(cursor.columns.map((column) => column.alias)).toStrictEqual(['N1']);
          expect(cursor.fetchBlr.length).toBeGreaterThan(0);
          expect(cursor.fetchMessageLength).toBe(10);

          const row1 = await wireProtocol.fetchNext(cursor);
          expect(row1?.length).toBe(cursor.fetchMessageLength);
          expect(row1?.readDoubleLE(0)).toBe(1); // integer converted to double
          expect(row1?.readInt16LE(8)).toBe(0);

          const row2 = await wireProtocol.fetchNext(cursor);
          expect(row2?.length).toBe(cursor.fetchMessageLength);
          expect(row2?.readDoubleLE(0)).toBe(2); // integer converted to double
          expect(row2?.readInt16LE(8)).toBe(0);

          await expect(wireProtocol.fetchNext(cursor)).resolves.toBeUndefined();
        } finally {
          await wireProtocol.freeStatement(selectStatement);
          await wireProtocol.freeStatement(insertStatement);
          await wireProtocol.freeStatement(ddlStatement);
        }

        await wireProtocol.rollback(transaction);
        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('creates, writes, opens and reads blob segments', async () => {
    await withCreatedDatabase('wire-blob-segments.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());

        const createdBlob = await wireProtocol.createBlob(transaction, createBpb({ type: 'SEGMENTED' }));
        expect(createdBlob.handle).toBeGreaterThanOrEqual(0);
        expect(createdBlob.id).toHaveLength(8);

        await wireProtocol.putSegment(createdBlob, Buffer.from('abc', 'ascii'));
        await wireProtocol.putSegment(createdBlob, Buffer.from('de', 'ascii'));
        await wireProtocol.closeBlob(createdBlob);

        const openedBlob = await wireProtocol.openBlob(transaction, createdBlob.id, createBpb({ type: 'SEGMENTED' }));
        expect(openedBlob.handle).toBeGreaterThanOrEqual(0);

        const response = await wireProtocol.getSegment(openedBlob, 64);
        expect(response.state).toBe(2);
        expect(decodePackedBlobSegments(response.data).map((segment) => segment.toString('ascii'))).toStrictEqual([
          'abc',
          'de',
        ]);

        await wireProtocol.closeBlob(openedBlob);
        await wireProtocol.rollback(transaction);
        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('seeks a stream blob and can cancel an open blob handle', async () => {
    await withCreatedDatabase('wire-blob-seek.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());

        const createdBlob = await wireProtocol.createBlob(transaction, createBpb({ type: 'STREAM' }));
        await wireProtocol.putSegment(createdBlob, Buffer.from('1234567890', 'ascii'));
        await wireProtocol.closeBlob(createdBlob);

        const openedBlob = await wireProtocol.openBlob(transaction, createdBlob.id, createBpb({ type: 'STREAM' }));
        expect(await wireProtocol.seekBlob(openedBlob, 0, 2)).toBe(2);

        const response = await wireProtocol.getSegment(openedBlob, 32);
        expect(decodePackedBlobSegments(response.data).map((segment) => segment.toString('ascii'))).toStrictEqual([
          '34567890',
        ]);

        await wireProtocol.cancelBlob(openedBlob);
        await wireProtocol.rollback(transaction);
        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('returns a structured Firebird error for invalid SQL preparation', async () => {
    await withCreatedDatabase('wire-invalid-prepare.fdb', async (database) => {
      const wireProtocol = createProtocol();

      try {
        const attachment = await wireProtocol.attach(database, createAttachDpb());
        const transaction = await wireProtocol.startTransaction(createTpb());
        const statement = await wireProtocol.allocateStatement();

        try {
          await expect(
            wireProtocol.prepareStatement(transaction, statement, 'create select t1 (n1 integer)'),
          ).rejects.toThrow(/Dynamic SQL Error\n-SQL error code = -104\n-Token unknown/);
        } finally {
          await wireProtocol.freeStatement(statement);
        }

        await wireProtocol.rollback(transaction);
        await wireProtocol.detach(attachment);
      } finally {
        await wireProtocol.close();
      }
    });
  });

  test('returns a structured Firebird error for a bad password', async () => {
    await withCreatedDatabase('wire-bad-password.fdb', async (database) => {
      const wireProtocol = createProtocol('wrong-password');

      await expect(wireProtocol.attach(database, createAttachDpb())).rejects.toThrow(/Firebird|gds=/);
      await wireProtocol.close();
    });
  });

  test('legacy hash matches Firebird-compatible vectors', () => {
    expect(legacyHash('masterkey').toString('ascii')).toBe('QP3LMZ/MJh.');
    expect(legacyHash('password').toString('ascii')).toBe('3RNBnBoB0d6');
    expect(legacyHash('12345678').toString('ascii')).toBe('kR2aQutwZAE');
    expect(legacyHash('toolongpassword').toString('ascii')).toBe('Dviq39oEkuI');
  });
});
