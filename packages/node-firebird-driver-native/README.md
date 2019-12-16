[![Build Status](https://travis-ci.com/asfernandes/node-firebird-drivers.svg?branch=master)](https://travis-ci.com/asfernandes/node-firebird-drivers)
[![npm version](https://badge.fury.io/js/node-firebird-driver-native.svg)](https://www.npmjs.com/package/node-firebird-driver-native)

# Firebird high-level native client for Node.js / TypeScript

node-firebird-driver-native is a modern (Firebird 3+ client, Node.js 8+, TypeScript 2+) native client for Firebird based in the
node-firebird-driver API.

## Installation

yarn add node-firebird-driver-native

## Usage example

```ts
import { createNativeClient, getDefaultLibraryFilename } from 'node-firebird-driver-native';


async function test() {
	const client = createNativeClient(getDefaultLibraryFilename());

	const attachment = await client.createDatabase('/tmp/new-db.fdb');
	const transaction = await attachment.startTransaction();

	await attachment.execute(transaction, 'create table t1 (n integer, d date)');
	await transaction.commitRetaining();

	const statement1 = await attachment.prepare(transaction, 'insert into t1 values (?, ?)');
	await statement1.execute(transaction, [1, new Date()]);
	await statement1.execute(transaction, [2, new Date()]);
	await statement1.execute(transaction, [3, new Date()]);
	await statement1.dispose();

	const resultSet = await attachment.executeQuery(transaction, 'select n, d from t1 where n <= ?', [2]);
	const rows = await resultSet.fetch();

	for (const columns of rows)
		console.log(`n: ${columns[0]}, d: ${columns[1]}`);

	await resultSet.close();

	await transaction.commit();
	await attachment.dropDatabase();

	await client.dispose();
}

test().then(() => console.log('Finish...'));
```

See more examples in `src/test` directory.

# Donation

If this project help you reduce time to develop, you can show your appreciation with a donation.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=X3JMTGW92LQEL)

BTC: 1Q1W3tLD1xbk81kTeFqobiyrEXcKN1GfHG
