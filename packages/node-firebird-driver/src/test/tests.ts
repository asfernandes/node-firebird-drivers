import { Client } from '../lib';

import * as assert from 'power-assert';
import * as fs from 'fs-extra-promise';
import * as tmp from 'temp-fs';


export function runCommonTests(client: Client) {
	function dateToString(d: Date) {
		return d && `${d.getFullYear()}-${d.getMonth() + 1}-${d.getDate()}`;
	}

	function timeToString(d: Date) {
		return d && `${d.getHours()}:${d.getMinutes()}:${d.getSeconds()}.${d.getMilliseconds()}`;
	}

	function dateTimeToString(d: Date) {
		return d && `${dateToString(d)} ${timeToString(d)}`;
	}


	describe('node-firebird-driver', function() {
		let tmpDir: string;

		function getTempFile(name: string): string {
			return `${tmpDir}/${name}`;
		}

		this.timeout(5000);

		before(() => {
			tmpDir = tmp.mkdirSync().path.toString();
		});

		after(async () => {
			await client.dispose();
			fs.rmdirSync(tmpDir);
		});

		describe('Client', () => {
			it('#createDatabase()', async () => {
				const attachment = await client.createDatabase(getTempFile('Client-createDatabase.fdb'));
				await attachment.dropDatabase();
			});

			it('#connect()', async () => {
				const filename = getTempFile('Client-connect.fdb');
				const attachment1 = await client.createDatabase(filename);
				const attachment2 = await client.connect(filename);

				await attachment2.disconnect();
				await attachment1.dropDatabase();
			});
		});

		describe('Attachment', () => {
			it('#startTransaction()', async () => {
				const attachment = await client.createDatabase(getTempFile('Attachment-startTransaction.fdb'));
				const transaction = await attachment.startTransaction();
				await transaction.commit();
				await attachment.dropDatabase();
			});

			it('#prepare()', async () => {
				const attachment = await client.createDatabase(getTempFile('Attachment-prepare.fdb'));
				const transaction = await attachment.startTransaction();

				const statement = await attachment.prepare(transaction, 'create table t1 (n1 integer)');
				await statement.dispose();

				let error: Error | undefined;
				try {
					await attachment.prepare(transaction, 'create select t1 (n1 integer)');
				}
				catch (e) {
					error = e as Error;
					assert.equal(error.message,
						'Dynamic SQL Error\n' +
						'-SQL error code = -104\n' +
						'-Token unknown - line 1, column 8\n' +
						'-select');
				}

				assert.ok(error);

				await transaction.commit();
				await attachment.dropDatabase();
			});

			//// TODO: #executeTransaction

			it('#execute()', async () => {
				const attachment = await client.createDatabase(getTempFile('Attachment-execute.fdb'));
				const transaction = await attachment.startTransaction();

				await attachment.execute(transaction, 'create table t1 (n1 integer)');
				await transaction.commitRetaining();

				await attachment.execute(transaction, 'insert into t1 (n1) values (1)');

				await transaction.commit();
				await attachment.dropDatabase();
			});

			it('#executeQuery()', async () => {
				const attachment = await client.createDatabase(getTempFile('Attachment-executeQuery.fdb'));
				const transaction = await attachment.startTransaction();

				await attachment.execute(transaction, 'create table t1 (n1 integer)');
				await transaction.commitRetaining();

				const resultSet = await attachment.executeQuery(transaction, 'select n1 from t1');
				await resultSet.close();

				await transaction.commit();
				await attachment.dropDatabase();
			});
		});

		describe('Transaction', () => {
			it('#commit()', async () => {
				const attachment = await client.createDatabase(getTempFile('Transaction-commit.fdb'));
				const transaction = await attachment.startTransaction();
				await transaction.commit();
				await attachment.dropDatabase();
			});

			it('#commitRetaining()', async () => {
				const attachment = await client.createDatabase(getTempFile('Transaction-commitRetaining.fdb'));
				const transaction = await attachment.startTransaction();
				await transaction.commitRetaining();
				await transaction.commit();
				await attachment.dropDatabase();
			});

			it('#rollback()', async () => {
				const attachment = await client.createDatabase(getTempFile('Transaction-rollback.fdb'));
				const transaction = await attachment.startTransaction();
				await transaction.rollback();
				await attachment.dropDatabase();
			});

			it('#rollbackRetaining()', async () => {
				const attachment = await client.createDatabase(getTempFile('Transaction-rollbackRetaining.fdb'));
				const transaction = await attachment.startTransaction();
				await transaction.rollbackRetaining();
				await transaction.rollback();
				await attachment.dropDatabase();
			});
		});

		describe('Statement', () => {
			it('#execute()', async () => {
				const attachment = await client.createDatabase(getTempFile('Statement-execute.fdb'));
				const transaction = await attachment.startTransaction();

				const statement1 = await attachment.prepare(transaction, 'create table t1 (n1 integer)');
				await statement1.execute(transaction);
				await statement1.dispose();
				await transaction.commitRetaining();

				const statement2 = await attachment.prepare(transaction, 'insert into t1 (n1) values (1)');
				await statement2.execute(transaction);
				await statement2.dispose();

				await transaction.commit();
				await attachment.dropDatabase();
			});

			it('#executeQuery()', async () => {
				const attachment = await client.createDatabase(getTempFile('Statement-executeQuery.fdb'));
				const transaction = await attachment.startTransaction();

				const statement1 = await attachment.prepare(transaction, 'create table t1 (n1 integer)');
				await statement1.execute(transaction);
				await statement1.dispose();
				await transaction.commitRetaining();

				const statement2 = await attachment.prepare(transaction, 'select n1 from t1');
				const resultSet2 = await statement2.executeQuery(transaction);
				await resultSet2.close();
				await statement2.dispose();

				await transaction.commit();
				await attachment.dropDatabase();
			});
		});

		describe('ResultSet', () => {
			it('#fetch()', async () => {
				const attachment = await client.createDatabase(getTempFile('ResultSet-fetch.fdb'));
				const transaction = await attachment.startTransaction();

				const fields = [
					{ name: 'x_short', type: 'numeric(2)', valToStr: (v: any) => v },
					{ name: 'x_int', type: 'integer', valToStr: (v: any) => v },
					{ name: 'x_int_scale', type: 'numeric(5, 2)', valToStr: (v: any) => v },
					{ name: 'x_bigint', type: 'bigint', valToStr: (v: any) => v },
					{ name: 'x_bigint_scale', type: 'numeric(15, 2)', valToStr: (v: any) => v },
					{ name: 'x_double', type: 'double precision', valToStr: (v: any) => v },
					{ name: 'x_date', type: 'date', valToStr: (v: any) => `date '${dateToString(v)}'` },
					{ name: 'x_time', type: 'time', valToStr: (v: any) => `time '${timeToString(v)}'` },
					{ name: 'x_timestamp', type: 'timestamp', valToStr: (v: any) => `timestamp '${dateTimeToString(v)}'` },
					{ name: 'x_boolean', type: 'boolean', valToStr: (v: any) => v },
					{ name: 'x_varchar', type: 'varchar(10) character set utf8', valToStr: (v: any) => `'${v}'` },
					{ name: 'x_char', type: 'char(10) character set utf8', valToStr: (v: any) => `'${v}'` },
					{ name: 'x_blob', type: 'blob', valToStr: (v: Buffer) => `'${v.toString()}'` }
				];

				const statement1 = await attachment.prepare(transaction,
					`create table t1 (${fields.map(f => `${f.name} ${f.type}`).join(', ')})`);
				await statement1.execute(transaction);
				await statement1.dispose();
				await transaction.commitRetaining();

				const recordCount = 5;
				const now = new Date();
				const parameters = [
					-1,
					-2,
					-3.45,
					-2,
					-3.45,
					-4.567,
					new Date(2017, 3 - 1, 26),
					new Date(now.getFullYear(), now.getMonth(), now.getDate(), 11, 56, 32, 123),
					new Date(2017, 3 - 1, 26, 11, 56, 32, 123),
					true,
					'123áé4567',
					'123áé4567',
					Buffer.alloc(11, '12345678á9')
				];

				{	// scope
					const statement2a = await attachment.prepare(transaction,
						`insert into t1 (${fields.map(f => f.name).join(', ')}) values (${fields.map(() => '?').join(', ')})`);

					for (let i = 0; i < recordCount; ++i)
						await statement2a.execute(transaction, parameters);
					await statement2a.dispose();
				}

				{	// scope
					const statement2b = await attachment.prepare(transaction,
						`insert into t1 (${fields.map(f => f.name).join(', ')}) ` +
						`values (${parameters.map((val, index) => fields[index].valToStr(val)).join(', ')})`);

					for (let i = 0; i < recordCount; ++i)
						await statement2b.execute(transaction);
					await statement2b.dispose();
				}

				await transaction.commitRetaining();

				const statement3 = await attachment.prepare(transaction,
					`select x_short,
							x_int,
							x_int_scale,
							x_bigint,
							x_bigint_scale,
							x_double,
							x_date,
							x_time,
							x_timestamp,
							x_boolean,
							x_varchar,
							char_length(x_varchar),
							octet_length(x_varchar),
							x_char,
							char_length(x_char),
							octet_length(x_char),
							null,
							x_char || null,
							x_blob
					from t1`);
				const resultSet3 = await statement3.executeQuery(transaction);

				const data = await resultSet3.fetch();
				assert.equal(data.length, recordCount * 2);

				for (const columns of data) {
					let n = 0;
					assert.equal(columns[n++], -1);
					assert.equal(columns[n++], -2);
					assert.equal(columns[n++], -3.45);
					assert.equal(columns[n++], -2);
					assert.equal(columns[n++], -3.45);
					assert.equal(columns[n++], -4.567);
					assert.equal(dateTimeToString(columns[n++]), '2017-3-26 0:0:0.0');
					assert.equal(timeToString(columns[n++]), '11:56:32.123');
					assert.equal(dateTimeToString(columns[n++]), '2017-3-26 11:56:32.123');
					assert.equal(columns[n++], true);
					assert.equal(columns[n++], '123áé4567');
					assert.equal(columns[n++], 9);
					assert.equal(columns[n++], 11);
					assert.equal(columns[n++], '123áé4567 ');
					assert.equal(columns[n++], 10);
					assert.equal(columns[n++], 12);
					assert.equal(columns[n++], null);
					assert.equal(columns[n++], null);
					assert.equal((columns[n++] as Buffer).toString(), '12345678á9');

					assert.equal(columns.length, n);
				}

				assert.equal((await resultSet3.fetch()).length, 0);
				assert.equal((await resultSet3.fetch()).length, 0);

				await resultSet3.close();
				await statement3.dispose();

				await transaction.commit();
				await attachment.dropDatabase();
			});
		});
	});
}
