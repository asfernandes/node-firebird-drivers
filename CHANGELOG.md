## next

### driver

* Feature [#101](https://github.com/asfernandes/node-firebird-drivers/issues/101) - Add property Statement.hasResultSet.
* Feature [#102](https://github.com/asfernandes/node-firebird-drivers/issues/102) - Add method Statement.setCursorName.

## 2.2.0 (June, 07, 2021)

### driver-native

* Feature [#87](https://github.com/asfernandes/node-firebird-drivers/issues/87) - Support Firebird 4 INT128 data type.
* Feature [#88](https://github.com/asfernandes/node-firebird-drivers/issues/88) - Support Firebird 4 DECFLOAT(16) and DECFLOAT(34) data types.
* Feature [#89](https://github.com/asfernandes/node-firebird-drivers/issues/89) - Support Firebird 4 TIME WITH TIME ZONE and TIMESTAMP WITH TIME ZONE data types.
* Fix [#94](https://github.com/asfernandes/node-firebird-drivers/issues/94) - Wrong year in date/timestamp when year < 100.

## 2.1.2 (May, 07, 2021)

### native-api

* Fix [#86](https://github.com/asfernandes/node-firebird-drivers/issues/86) - Race condition in events processing.

## 2.1.1 (November, 22, 2020)

### driver-native

* Feature [#62](https://github.com/asfernandes/node-firebird-drivers/issues/62) - Change value of getDefaultLibraryFilename in MacOS.
* Feature [#63](https://github.com/asfernandes/node-firebird-drivers/issues/63) - Make getMaster return OS error when failing to load the client library.

### driver

* Fix [#69](https://github.com/asfernandes/node-firebird-drivers/issues/69) - Subsequent use of Statement::execute* methods may send incorrect value of input parameters.

## 2.1.0 (December, 29, 2019)

### driver

* Feature [#30](https://github.com/asfernandes/node-firebird-drivers/issues/30) - Add methods executeReturningAsObject and fetchAsObject to return records as objects instead of arrays.
* Feature [#43](https://github.com/asfernandes/node-firebird-drivers/issues/43) - Add Statement.columnLabels property.

## 2.0.0 (December, 06, 2019)

### driver

* Feature [#34](https://github.com/asfernandes/node-firebird-drivers/issues/34) - Support for Firebird events.
* Feature [#42](https://github.com/asfernandes/node-firebird-drivers/pull/42) - SQL role name in connection options.

### native-api

* Minimal node version is 10.6.0.
* Fix [#41](https://github.com/asfernandes/node-firebird-drivers/issues/41) - Error: pointer argument must be an instance of Pointer class or null with node v13.

### all projects

* Upgrade TypeScript to v3.7.

## 1.0.1 (September, 19, 2019)

### native-api

* Fix [#29](https://github.com/asfernandes/node-firebird-drivers/issues/29) - Document problem in MacOS and possible solution.
* Fix [#31](https://github.com/asfernandes/node-firebird-drivers/issues/31) - Command failed with exit code 3221225477.

## 1.0.0 (August 4, 2019)
