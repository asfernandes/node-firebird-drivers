[![Build Status](https://travis-ci.com/asfernandes/node-firebird-drivers.svg?branch=master)](https://travis-ci.com/asfernandes/node-firebird-drivers)
[![npm version](https://badge.fury.io/js/node-firebird-driver.svg)](https://www.npmjs.com/package/node-firebird-driver)

# Firebird client interfaces for Node.js / TypeScript

This project currently has only TypeScript interfaces for a Firebird client. In the future it may have common code for any Firebird client,
like connection pools and utility functions.

## Native client

If you are looking to use Firebird from a Node.js application or library, look at:

https://github.com/asfernandes/node-firebird-drivers/tree/master/packages/node-firebird-driver-native / https://www.npmjs.com/package/node-firebird-driver-native

There is also plan to create a socket-based (pure Node.js) driver.

## Installation

yarn add node-firebird-driver

## Contributing
- Clone this repo
- yarn
- yarn bootstrap
- yarn test

## Testing
- `yarn run test`
(default user and password will be used during tests)

`user` and `password` can be specified through environment variables `ISC_USER` and `ISC_PASSWORD`

You can also use a configuration file if you prefer (test-cfg.json).

```
// node-firebird-drivers/test-cfg.json (Sample)
{
	"user": "sysdba",
	"pw": "masterkey",
	"role": "",
	"remoteDir": "",
	"host": "127.0.0.1/3050"
}
```

If user and pw are empty or omitted, environment values will be used. Otherwise, remote values will be used.

**Note:** If have to run your tests on remote server, make sure you specify `remoteDir` in your configuration file.

# Donation

If this project help you reduce time to develop, you can show your appreciation with a donation.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=X3JMTGW92LQEL)

BTC: 1Q1W3tLD1xbk81kTeFqobiyrEXcKN1GfHG
