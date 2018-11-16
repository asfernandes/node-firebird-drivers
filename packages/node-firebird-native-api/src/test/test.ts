import * as fs from 'fs-extra-promise';
import * as tmp from 'temp-fs';

import { disposeMaster, getDefaultLibraryFilename, getMaster, Master, Provider, Util } from '../lib';


describe('node-firebird-native-api', () => {
	let master: Master;
	let dispatcher: Provider;
	let tmpDir: string;

	function getTempFile(name: string): string {
		return `${tmpDir}/${name}`;
	}

	jest.setTimeout(5000);

	beforeAll(() => {
		const tempMaster = getMaster(getDefaultLibraryFilename());

		master = getMaster(getDefaultLibraryFilename());
		dispatcher = master.getDispatcherSync()!;
		tmpDir = tmp.mkdirSync().path.toString();

		// Test premature shutdown prevention. 'master' variable should still be usable.
		expect(disposeMaster(tempMaster)).toBe(true);
	});

	afterAll(() => {
		if (!master)
			return;

		const status = master.getStatusSync()!;
		// tslint:disable-next-line:variable-name
		const fb_shutrsn_app_stopped = -3;
		dispatcher.shutdownSync(status, 0, fb_shutrsn_app_stopped);
		status.disposeSync();

		dispatcher.releaseSync();
		fs.rmdirSync(tmpDir);
		expect(disposeMaster(master)).toBe(true);
		expect(disposeMaster(master)).toBe(false);
	});

	describe('getMaster', () => {
		test('with error', () => {
			expect(() => getMaster('not-a-firebird-client-library')).toThrow();
		});
	});

	describe('Master', () => {
		test('#getStatus()', () => {
			const status = master.getStatusSync()!;
			expect(status).toBeTruthy();
			status.disposeSync();
		});

		test('#getDispatcher()', () => {
			const thisDispatcher = master.getDispatcherSync()!;
			expect(thisDispatcher).toBeTruthy();
			thisDispatcher.addRefSync();
			expect(thisDispatcher.releaseSync()).toBe(1);
			expect(thisDispatcher.releaseSync()).toBe(0);
		});

		test('#getUtilInterface()', () => {
			const util = master.getUtilInterfaceSync();
			expect(util).toBeTruthy();
		});
	});

	describe('Util', () => {
		const DATE_2016_10_14 = 57675;
		let util: Util;

		beforeAll(() => {
			util = master.getUtilInterfaceSync()!;
		});

		test('#encodeDate()', () => {
			const n = util.encodeDateSync(2016, 10, 14);
			expect(n).toBe(DATE_2016_10_14);
		});

		test('#decodeDate()', () => {
			const year = new Uint32Array(1);
			const month = new Uint32Array(1);
			const day = new Uint32Array(1);

			util.decodeDateSync(DATE_2016_10_14, year, month, day);

			expect(year[0]).toBe(2016);
			expect(month[0]).toBe(10);
			expect(day[0]).toBe(14);
		});

		test('#getClientVersion()', () => {
			const rawVersion = util.getClientVersionSync();
			const majorVersion = rawVersion >> 8;
			expect(majorVersion).toBeGreaterThanOrEqual(3);
		});
	});

	describe('Provider', () => {
		test('#createDatabaseSync()', () => {
			const status = master.getStatusSync()!;
			try {
				const attachment = dispatcher.createDatabaseSync(status, getTempFile('Provider-createDatabaseSync.fdb'), 0, undefined)!;
				attachment.dropDatabaseSync(status);
			}
			finally {
				status.disposeSync();
			}
		});

		test('#createDatabaseAsync()', async () => {
			const status = master.getStatusSync()!;
			try {
				const attachment = (await dispatcher.createDatabaseAsync(status, getTempFile('Attachment-createDatabase.fdb'),
					0, undefined))!;
				await attachment.dropDatabaseAsync(status);
			}
			finally {
				status.disposeSync();
			}
		});
	});

	describe('Attachment', () => {
		test('#dropDatabaseSync()', () => {
			const status = master.getStatusSync()!;
			try {
				const attachment = dispatcher.createDatabaseSync(status, getTempFile('Attachment-dropDatabaseSync.fdb'), 0, undefined)!;
				attachment.dropDatabaseSync(status);
			}
			finally {
				status.disposeSync();
			}
		});

		test('#dropDatabaseAsync()', async () => {
			const status = master.getStatusSync()!;
			try {
				const attachment = (await dispatcher.createDatabaseAsync(status, getTempFile('Attachment-dropDatabase.fdb'),
					0, undefined))!;
				await attachment.dropDatabaseAsync(status);
			}
			finally {
				status.disposeSync();
			}
		});

		test('#detachSync()', () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-detachSync.fdb');
				const attachment = dispatcher.createDatabaseSync(status, filename, 0, undefined)!;
				attachment.detachSync(status);
				fs.removeSync(filename);
			}
			finally {
				status.disposeSync();
			}
		});

		test('#detachAsync()', async () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-detach.fdb');
				const attachment = (await dispatcher.createDatabaseAsync(status, filename, 0, undefined))!;
				await attachment.detachAsync(status);
				await fs.removeAsync(filename);
			}
			finally {
				status.disposeSync();
			}
		});

		test('#startTransactionSync()', () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-startTransactionSync.fdb');

				const attachment = dispatcher.createDatabaseSync(status, filename, 0, undefined)!;
				try {
					const transaction = attachment.startTransactionSync(status, 0, undefined)!;
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

		/***
		test('#startTransactionAsync()', async () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-startTransaction.fdb');

				const attachment = (await dispatcher.createDatabaseAsync(status, filename, 0, undefined))!;
				try {
					const transaction = (await attachment.startTransactionAsync(status, 0, undefined))!;
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

		test('#executeSync()', () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-executeSync.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (1)';
				const stmt3 = 'select';	// error

				const attachment = dispatcher.createDatabaseSync(status, filename, 0, undefined)!;
				try {
					const transaction = attachment.startTransactionSync(status, 0, undefined)!;
					try {
						attachment.executeSync(status, transaction, 0, stmt1, 3, undefined, undefined, undefined, undefined);
						transaction.commitRetainingSync(status);
						attachment.executeSync(status, transaction, 0, stmt2, 3, undefined, undefined, undefined, undefined);

						let error: Error | undefined;
						try {
							attachment.executeSync(status, transaction, 0, stmt3, 3, undefined, undefined, undefined, undefined);
						}
						catch (e) {
							error = e as Error;
							expect(error.message).toBe(
								'Dynamic SQL Error\n' +
								'-SQL error code = -104\n' +
								'-Unexpected end of command - line 1, column 1');
						}

						expect(error).toBeTruthy();
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

		test('#executeAsync()', async () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-execute.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (1)';
				const stmt3 = 'select';	// error

				const attachment = (await dispatcher.createDatabaseAsync(status, filename, 0, undefined))!;
				try {
					const transaction = (await attachment.startTransactionAsync(status, 0, undefined))!;
					try {
						await attachment.executeAsync(status, transaction, 0, stmt1, 3, undefined, undefined, undefined, undefined);
						await transaction.commitRetainingAsync(status);
						await attachment.executeAsync(status, transaction, 0, stmt2, 3, undefined, undefined, undefined, undefined);

						let error: Error | undefined;
						try {
							await attachment.executeAsync(status, transaction, 0, stmt3, 3, undefined, undefined, undefined, undefined);
						}
						catch (e) {
							error = e as Error;
							expect(error.message).toBe(
								'Dynamic SQL Error\n' +
								'-SQL error code = -104\n' +
								'-Unexpected end of command - line 1, column 1');
						}

						expect(error).toBeTruthy();
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

		test('#prepareSync()', () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-prepareSync.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (?)';

				const attachment = dispatcher.createDatabaseSync(status, filename, 0, undefined)!;
				try {
					const transaction = attachment.startTransactionSync(status, 0, undefined)!;
					try {
						attachment.executeSync(status, transaction, 0, stmt1, 3, undefined, undefined, undefined, undefined);
						transaction.commitRetainingSync(status);

						const statement2 = attachment.prepareSync(status, transaction, 0, stmt2, 3, 0)!;
						try {
							const inputMetadata2 = statement2.getInputMetadataSync(status)!;
							try {
								expect(inputMetadata2.getCountSync(status)).toBe(1);
								expect(inputMetadata2.getMessageLengthSync(status)).toBe(2 + 4);
							}
							finally {
								inputMetadata2.releaseSync();
							}

							const outputMetadata2 = statement2.getOutputMetadataSync(status)!;
							try {
								expect(outputMetadata2.getCountSync(status)).toBe(0);
								expect(outputMetadata2.getMessageLengthSync(status)).toBe(0);
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

		test('#prepareAsync()', async () => {
			const status = master.getStatusSync()!;
			try {
				const filename = getTempFile('Attachment-prepare.fdb');
				const stmt1 = 'create table t1 (n1 integer)';
				const stmt2 = 'insert into t1 values (?)';

				const attachment = (await dispatcher.createDatabaseAsync(status, filename, 0, undefined))!;
				try {
					const transaction = (await attachment.startTransactionAsync(status, 0, undefined))!;
					try {
						await attachment.executeAsync(status, transaction, 0, stmt1, 3, undefined, undefined, undefined, undefined);
						await transaction.commitRetainingAsync(status);

						const statement2 = (await attachment.prepareAsync(status, transaction, 0, stmt2, 3, 0))!;
						try {
							const inputMetadata2 = (await statement2.getInputMetadataAsync(status))!;
							try {
								expect(inputMetadata2.getCountSync(status)).toBe(1);
								expect(inputMetadata2.getMessageLengthSync(status)).toBe(2 + 4);
							}
							finally {
								inputMetadata2.releaseSync();
							}

							const outputMetadata2 = (await statement2.getOutputMetadataSync(status))!;
							try {
								expect(outputMetadata2.getCountSync(status)).toBe(0);
								expect(outputMetadata2.getMessageLengthSync(status)).toBe(0);
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
		***/
	});
});
