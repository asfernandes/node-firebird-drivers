[![CI](https://github.com/asfernandes/node-firebird-drivers/workflows/CI/badge.svg)](https://github.com/asfernandes/node-firebird-drivers/actions?query=workflow%3ACI)

# Firebird drivers for Node.js / TypeScript

This project is the root project of a monorepo with Firebird drivers for Node.js / TypeScript (or JavaScript).

The sub projects are there:

- [node-firebird-driver-native - High-level Firebird client using native fbclient library](packages/node-firebird-driver-native/README.md)
- [node-firebird-native-api - Low-level Firebird client directly mapped from fbclient interfaces](packages/node-firebird-native-api/README.md)
- [node-firebird-driver - Interface files for the high-level driver(s)](packages/node-firebird-driver/README.md)

## Contributing

Clone this repo then run:
- yarn
- yarn bootstrap
- yarn test

## Testing
- `yarn run test`
(default user and password will be used during tests)

As of now tests require **Firebird 4** server and will fail when executed using **Firebird 3**.

You can put test configuration in `.env` file in the project root directory, like the following example:

```
ISC_USER=sysdba
ISC_PASSWORD=masterkey
NODE_FB_TEST_HOST=localhost
NODE_FB_TEST_PORT=3050
NODE_FB_TEST_TMP_DIR=/tmp/node-fb-tmp
```

You can also set environment variables externally. For `node-firebird-native-api`, `ISC_USER` and `ISC_PASSWORD` could not be set in the `.env` file currently. It should be set externally.

If `NODE_FB_TEST_HOST` is ommited, embedded server will be used.

`NODE_FB_TEST_PORT` defaults to 3050.

For remote server make sure to specify `NODE_FB_TEST_TMP_DIR`.

For local server or embedded, if `NODE_FB_TEST_TMP_DIR` is ommited a temporary directory will be created.

# Donation

If this project help you reduce time to develop, you can show your appreciation with a donation.

- GitHub Sponsor: https://github.com/sponsors/asfernandes
- Pix (Brazil): 278dd4e5-8226-494d-93a9-f3fb8a027a99
- BTC: 1Q1W3tLD1xbk81kTeFqobiyrEXcKN1GfHG
- [![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=X3JMTGW92LQEL)
