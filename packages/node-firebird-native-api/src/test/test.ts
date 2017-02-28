import * as assert from 'power-assert';
import * as fs from 'fs-extra-promise';
import * as tmp from 'temp-fs';

import { disposeMaster, getMaster, Master, Provider, Util } from '../lib';


describe('node-firebird-native-api', function() {
	let master: Master;
	let dispatcher: Provider;
	let tmpDir: string;

	function getTempFile(name: string): string {
		return `${tmpDir}/${name}`;
	}

	this.timeout(5000);

	before(() => {
		master = getMaster('libfbclient.so');
		dispatcher = master.getDispatcherSync();
		tmpDir = tmp.mkdirSync().path.toString();
	});

	after(() => {
		const status = master.getStatusSync();
		const fb_shutrsn_app_stopped = -3;
		dispatcher.shutdownSync(status, 0, fb_shutrsn_app_stopped);
		status.disposeSync();

		dispatcher.releaseSync();
		fs.rmdirSync(tmpDir);
		assert.equal(disposeMaster(master), true);
		assert.equal(disposeMaster(master), false);
	});

	describe('Master', () => {
		it('#getStatus()', () => {
			const status = master.getStatusSync();
			assert.notEqual(status, null);
			status.disposeSync();
		});

		it('#getDispatcher()', () => {
			const dispatcher = master.getDispatcherSync();
			assert.notEqual(dispatcher, null);
			dispatcher.addRefSync();
			assert.equal(dispatcher.releaseSync(), 1);
			assert.equal(dispatcher.releaseSync(), 0);
		});

		it('#getUtilInterface()', () => {
			const util = master.getUtilInterfaceSync();
			assert.notEqual(util, null);
		});
	});

	describe('Util', () => {
		const DATE_2016_10_14 = 57675;
		let util: Util;

		before(() => {
			util = master.getUtilInterfaceSync();
		});

		it('#encodeDate()', () => {
			const n = util.encodeDateSync(2016, 10, 14);
			assert.equal(n, DATE_2016_10_14);
		});

		it('#decodeDate()', () => {
			const year = new Uint32Array(1);
			const month = new Uint32Array(1);
			const day = new Uint32Array(1);

			util.decodeDateSync(DATE_2016_10_14, year, month, day);

			assert.equal(year[0], 2016);
			assert.equal(month[0], 10);
			assert.equal(day[0], 14);
		});

		it('#getClientVersion()', () => {
			const rawVersion = util.getClientVersionSync();
			const majorVersion = rawVersion >> 8;
			assert.ok(majorVersion >= 3);
		});
	});

	describe('Provider', () => {
		it('#createDatabaseSync()', () => {
			const status = master.getStatusSync();
			try {
				const attachment = dispatcher.createDatabaseSync(status, getTempFile('Provider-createDatabaseSync.fdb'), 0, null);
				attachment.dropDatabaseSync(status);
			}
			finally {
				status.disposeSync();
			}
		});

		it('#createDatabaseAsync()', async () => {
			const status = master.getStatusSync();
			try {
				const attachment = await dispatcher.createDatabaseAsync(status, getTempFile('Attachment-createDatabase.fdb'), 0, null);
				await attachment.dropDatabaseAsync(status);
			}
			finally {
				status.disposeSync();
			}
		});
	});

	describe('Attachment', () => {
		it('#dropDatabaseSync()', () => {
			const status = master.getStatusSync();
			try {
				const attachment = dispatcher.createDatabaseSync(status, getTempFile('Attachment-dropDatabaseSync.fdb'), 0, null);
				attachment.dropDatabaseSync(status);
			}
			finally {
				status.disposeSync();
			}
		});

		it('#dropDatabaseAsync()', async () => {
			const status = master.getStatusSync();
			try {
				const attachment = await dispatcher.createDatabaseAsync(status, getTempFile('Attachment-dropDatabase.fdb'), 0, null);
				await attachment.dropDatabaseAsync(status);
			}
			finally {
				status.disposeSync();
			}
		});

		it('#detachSync()', () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-detachSync.fdb');
				const attachment = dispatcher.createDatabaseSync(status, filename, 0, null);
				attachment.detachSync(status);
				fs.removeSync(filename);
			}
			finally {
				status.disposeSync();
			}
		});

		it('#detachAsync()', async () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-detach.fdb');
				const attachment = await dispatcher.createDatabaseAsync(status, filename, 0, null);
				await attachment.detachAsync(status);
				await fs.removeAsync(filename);
			}
			finally {
				status.disposeSync();
			}
		});

		it('#startTransactionSync()', () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-startTransactionSync.fdb');

				const attachment = dispatcher.createDatabaseSync(status, filename, 0, null);
				try {
					const transaction = attachment.startTransactionSync(status, 0, null);
					transaction.commitSync(status);
				}
				finally {
					attachment.dropDatabaseSync(status);
				}
			}
			finally {
				status.disposeSync();
			}
		});

		it('#startTransactionAsync()', async () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-startTransaction.fdb');

				const attachment = await dispatcher.createDatabaseAsync(status, filename, 0, null);
				try {
					const transaction = await attachment.startTransactionAsync(status, 0, null);
					await transaction.commitAsync(status);
				}
				finally {
					await attachment.dropDatabaseAsync(status);
				}
			}
			finally {
				status.disposeSync();
			}
		});

		it('#executeSync()', () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-executeSync.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (1)';
				const stmt3 = 'select';	// error

				const attachment = dispatcher.createDatabaseSync(status, filename, 0, null);
				try {
					const transaction = attachment.startTransactionSync(status, 0, null);
					try {
						attachment.executeSync(status, transaction, 0, stmt1, 3, null, null, null, null);
						transaction.commitRetainingSync(status);
						attachment.executeSync(status, transaction, 0, stmt2, 3, null, null, null, null);

						let error: Error;
						try {
							attachment.executeSync(status, transaction, 0, stmt3, 3, null, null, null, null);
						}
						catch (e) {
							error = e;
							assert.equal(error.message,
								'Dynamic SQL Error\n' +
								'-SQL error code = -104\n' +
								'-Unexpected end of command - line 1, column 1');
						}

						assert.ok(error);
					}
					finally {
						transaction.commitSync(status);
					}
				}
				finally {
					attachment.dropDatabaseSync(status);
				}
			}
			finally {
				status.disposeSync();
			}
		});

		it('#executeAsync()', async () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-execute.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (1)';
				const stmt3 = 'select';	// error

				const attachment = await dispatcher.createDatabaseAsync(status, filename, 0, null);
				try {
					const transaction = await attachment.startTransactionAsync(status, 0, null);
					try {
						await attachment.executeAsync(status, transaction, 0, stmt1, 3, null, null, null, null);
						await transaction.commitRetainingAsync(status);
						await attachment.executeAsync(status, transaction, 0, stmt2, 3, null, null, null, null);

						let error: Error;
						try {
							await attachment.executeAsync(status, transaction, 0, stmt3, 3, null, null, null, null);
						}
						catch (e) {
							error = e;
							assert.equal(error.message,
								'Dynamic SQL Error\n' +
								'-SQL error code = -104\n' +
								'-Unexpected end of command - line 1, column 1');
						}

						assert.notEqual(error, null);
					}
					finally {
						await transaction.commitAsync(status);
					}
				}
				finally {
					await attachment.dropDatabaseAsync(status);
				}
			}
			finally {
				status.disposeSync();
			}
		});

		it('#prepareSync()', () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-prepareSync.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (?)';

				const attachment = dispatcher.createDatabaseSync(status, filename, 0, null);
				try {
					const transaction = attachment.startTransactionSync(status, 0, null);
					try {
						attachment.executeSync(status, transaction, 0, stmt1, 3, null, null, null, null);
						transaction.commitRetainingSync(status);

						const statement2 = attachment.prepareSync(status, transaction, 0, stmt2, 3, 0);
						try {
							const inputMetadata2 = statement2.getInputMetadataSync(status);
							try {
								assert.equal(inputMetadata2.getCountSync(status), 1);
								assert.equal(inputMetadata2.getMessageLengthSync(status), 2 + 4);
							}
							finally {
								inputMetadata2.releaseSync();
							}

							const outputMetadata2 = statement2.getOutputMetadataSync(status);
							try {
								assert.equal(outputMetadata2.getCountSync(status), 0);
								assert.equal(outputMetadata2.getMessageLengthSync(status), 0);
							}
							finally {
								outputMetadata2.releaseSync();
							}
						}
						finally {
							statement2.freeSync(status);
						}
					}
					finally {
						transaction.commitSync(status);
					}
				}
				finally {
					attachment.dropDatabaseSync(status);
				}
			}
			finally {
				status.disposeSync();
			}
		});

		it('#prepareAsync()', async () => {
			const status = master.getStatusSync();
			try {
				const filename = getTempFile('Attachment-prepare.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (?)';

				const attachment = await dispatcher.createDatabaseAsync(status, filename, 0, null);
				try {
					const transaction = await attachment.startTransactionAsync(status, 0, null);
					try {
						await attachment.executeAsync(status, transaction, 0, stmt1, 3, null, null, null, null);
						await transaction.commitRetainingAsync(status);

						const statement2 = await attachment.prepareAsync(status, transaction, 0, stmt2, 3, 0);
						try {
							const inputMetadata2 = await statement2.getInputMetadataAsync(status);
							try {
								assert.equal(inputMetadata2.getCountSync(status), 1);
								assert.equal(inputMetadata2.getMessageLengthSync(status), 2 + 4);
							}
							finally {
								inputMetadata2.releaseSync();
							}

							const outputMetadata2 = await statement2.getOutputMetadataSync(status);
							try {
								assert.equal(outputMetadata2.getCountSync(status), 0);
								assert.equal(outputMetadata2.getMessageLengthSync(status), 0);
							}
							finally {
								outputMetadata2.releaseSync();
							}
						}
						finally {
							await statement2.freeAsync(status);
						}
					}
					finally {
						await transaction.commitAsync(status);
					}
				}
				finally {
					await attachment.dropDatabaseAsync(status);
				}
			}
			finally {
				status.disposeSync();
			}
		});
	});
});
