[![Build Status](https://travis-ci.com/asfernandes/node-firebird-drivers.svg?branch=master)](https://travis-ci.com/asfernandes/node-firebird-drivers) [![Build Status](https://ci.appveyor.com/api/projects/status/github/asfernandes/node-firebird-drivers?branch=master&svg=true)](https://ci.appveyor.com/project/asfernandes/node-firebird-drivers)

# Firebird drivers for Node.js / TypeScript

This project is the root project of a monorepo with Firebird drivers for Node.js / TypeScript (or JavaScript).

The sub projects are there:

- [node-firebird-driver-native - High-level Firebird client using native fbclient library](packages/node-firebird-driver-native/README.md)
- [node-firebird-native-api - Low-level Firebird client directly mapped from fbclient interfaces](packages/node-firebird-native-api/README.md)
- [node-firebird-driver - Interface files for the high-level driver(s)](packages/node-firebird-driver/README.md)

# MacOS

If the error `Cannot load Firebird client library: 'libfbclient.dylib'` appears in MacOS, you may fix it creating a symlink with `sudo ln -s /Library/Frameworks/Firebird.framework/Versions/A/Firebird /usr/local/lib/libfbclient.dylib`.

# Donation

If this project help you reduce time to develop, you can show your appreciation with a donation.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=X3JMTGW92LQEL)

BTC: 1Q1W3tLD1xbk81kTeFqobiyrEXcKN1GfHG
