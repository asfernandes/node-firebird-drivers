## December, 15, 2022

### driver, driver-native, native-api - 3.0.0

* Feature [#130](https://github.com/asfernandes/node-firebird-drivers/issues/130) - Add options to Attachment.createBlob for stream blob creation.
* Feature [#131](https://github.com/asfernandes/node-firebird-drivers/issues/131) - Add method BlobStream.seek.
* Feature [#133](https://github.com/asfernandes/node-firebird-drivers/issues/133) - Update target code to ES2020 (node.js 14 compatible).

## January, 26, 2022

### driver, driver-native - 2.4.0

* Feature [#115](https://github.com/asfernandes/node-firebird-drivers/issues/115) - Add method Statement.getExecPathText.
* Feature [#119](https://github.com/asfernandes/node-firebird-drivers/pull/119) - Implementation of isValid property.
* Feature [#121](https://github.com/asfernandes/node-firebird-drivers/issues/121) - Deprecate methods executeReturning* replacing by executeSingleton*.

### native-api - 2.1.4

* Feature [#114](https://github.com/asfernandes/node-firebird-drivers/issues/114) - Add support for Visual Studio 2022 build.

## July, 20, 2021

### driver, driver-native - 2.3.0

* Feature [#101](https://github.com/asfernandes/node-firebird-drivers/issues/101) - Add property Statement.hasResultSet.
* Feature [#102](https://github.com/asfernandes/node-firebird-drivers/issues/102) - Add method Statement.setCursorName.

## June, 07, 2021

### driver-native - 2.2.0

* Feature [#87](https://github.com/asfernandes/node-firebird-drivers/issues/87) - Support Firebird 4 INT128 data type.
* Feature [#88](https://github.com/asfernandes/node-firebird-drivers/issues/88) - Support Firebird 4 DECFLOAT(16) and DECFLOAT(34) data types.
* Feature [#89](https://github.com/asfernandes/node-firebird-drivers/issues/89) - Support Firebird 4 TIME WITH TIME ZONE and TIMESTAMP WITH TIME ZONE data types.
* Fix [#94](https://github.com/asfernandes/node-firebird-drivers/issues/94) - Wrong year in date/timestamp when year < 100.

## May, 07, 2021

### native-api - 2.1.2

* Fix [#86](https://github.com/asfernandes/node-firebird-drivers/issues/86) - Race condition in events processing.

## November, 22, 2020

### driver-native - 2.1.1

* Feature [#62](https://github.com/asfernandes/node-firebird-drivers/issues/62) - Change value of getDefaultLibraryFilename in MacOS.
* Feature [#63](https://github.com/asfernandes/node-firebird-drivers/issues/63) - Make getMaster return OS error when failing to load the client library.

### driver - 2.1.1

* Fix [#69](https://github.com/asfernandes/node-firebird-drivers/issues/69) - Subsequent use of Statement::execute* methods may send incorrect value of input parameters.

## December, 29, 2019

### driver - 2.1.0

* Feature [#30](https://github.com/asfernandes/node-firebird-drivers/issues/30) - Add methods executeReturningAsObject and fetchAsObject to return records as objects instead of arrays.
* Feature [#43](https://github.com/asfernandes/node-firebird-drivers/issues/43) - Add Statement.columnLabels property.

## December, 06, 2019

### driver - 2.0.0

* Feature [#34](https://github.com/asfernandes/node-firebird-drivers/issues/34) - Support for Firebird events.
* Feature [#42](https://github.com/asfernandes/node-firebird-drivers/pull/42) - SQL role name in connection options.

### native-api - 2.0.0

* Minimal node version is 10.6.0.
* Fix [#41](https://github.com/asfernandes/node-firebird-drivers/issues/41) - Error: pointer argument must be an instance of Pointer class or null with node v13.

### all projects

* Upgrade TypeScript to v3.7.

## September, 19, 2019

### native-api - 1.0.1

* Fix [#29](https://github.com/asfernandes/node-firebird-drivers/issues/29) - Document problem in MacOS and possible solution.
* Fix [#31](https://github.com/asfernandes/node-firebird-drivers/issues/31) - Command failed with exit code 3221225477.

## August 4, 2019

### all projects - 1.0.0
