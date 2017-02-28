// Auto-generated file. Do not edit!

export interface Pointer {
}

export interface Versioned {
}

export interface ReferenceCounted extends Versioned {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
}

export interface Disposable extends Versioned {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
}

export interface Status extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
	initSync(): void;
	initAsync(): Promise<void>;
	getStateSync(): number;
	getStateAsync(): Promise<number>;
	cloneSync(): Status;
	cloneAsync(): Promise<Status>;
}

export namespace Status {
	export const STATE_WARNINGS: number = 1;
	export const STATE_ERRORS: number = 2;
	export const RESULT_ERROR: number = (-1);
	export const RESULT_OK: number = 0;
	export const RESULT_NO_DATA: number = 1;
	export const RESULT_SEGMENT: number = 2;
}

export interface Master extends Versioned {
	getStatusSync(): Status;
	getStatusAsync(): Promise<Status>;
	getDispatcherSync(): Provider;
	getDispatcherAsync(): Promise<Provider>;
	getPluginManagerSync(): PluginManager;
	getPluginManagerAsync(): Promise<PluginManager>;
	getTimerControlSync(): TimerControl;
	getTimerControlAsync(): Promise<TimerControl>;
	getDtcSync(): Dtc;
	getDtcAsync(): Promise<Dtc>;
	registerAttachmentSync(provider: Provider, attachment: Attachment): Attachment;
	registerAttachmentAsync(provider: Provider, attachment: Attachment): Promise<Attachment>;
	registerTransactionSync(attachment: Attachment, transaction: Transaction): Transaction;
	registerTransactionAsync(attachment: Attachment, transaction: Transaction): Promise<Transaction>;
	getMetadataBuilderSync(status: Status, fieldCount: number): MetadataBuilder;
	getMetadataBuilderAsync(status: Status, fieldCount: number): Promise<MetadataBuilder>;
	serverModeSync(mode: number): number;
	serverModeAsync(mode: number): Promise<number>;
	getUtilInterfaceSync(): Util;
	getUtilInterfaceAsync(): Promise<Util>;
	getConfigManagerSync(): ConfigManager;
	getConfigManagerAsync(): Promise<ConfigManager>;
	getProcessExitingSync(): boolean;
	getProcessExitingAsync(): Promise<boolean>;
}

export interface PluginBase extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
}

export interface PluginSet extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getNameSync(): string;
	getNameAsync(): Promise<string>;
	getModuleNameSync(): string;
	getModuleNameAsync(): Promise<string>;
	getPluginSync(status: Status): PluginBase;
	getPluginAsync(status: Status): Promise<PluginBase>;
	nextSync(status: Status): void;
	nextAsync(status: Status): Promise<void>;
	setSync(status: Status, s: string): void;
	setAsync(status: Status, s: string): Promise<void>;
}

export interface ConfigEntry extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getNameSync(): string;
	getNameAsync(): Promise<string>;
	getValueSync(): string;
	getValueAsync(): Promise<string>;
	getIntValueSync(): number;
	getIntValueAsync(): Promise<number>;
	getBoolValueSync(): boolean;
	getBoolValueAsync(): Promise<boolean>;
	getSubConfigSync(status: Status): Config;
	getSubConfigAsync(status: Status): Promise<Config>;
}

export interface Config extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	findSync(status: Status, name: string): ConfigEntry;
	findAsync(status: Status, name: string): Promise<ConfigEntry>;
	findValueSync(status: Status, name: string, value: string): ConfigEntry;
	findValueAsync(status: Status, name: string, value: string): Promise<ConfigEntry>;
	findPosSync(status: Status, name: string, pos: number): ConfigEntry;
	findPosAsync(status: Status, name: string, pos: number): Promise<ConfigEntry>;
}

export interface FirebirdConf extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getKeySync(name: string): number;
	getKeyAsync(name: string): Promise<number>;
	asIntegerSync(key: number): number;
	asIntegerAsync(key: number): Promise<number>;
	asStringSync(key: number): string;
	asStringAsync(key: number): Promise<string>;
	asBooleanSync(key: number): boolean;
	asBooleanAsync(key: number): Promise<boolean>;
}

export interface PluginConfig extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getConfigFileNameSync(): string;
	getConfigFileNameAsync(): Promise<string>;
	getDefaultConfigSync(status: Status): Config;
	getDefaultConfigAsync(status: Status): Promise<Config>;
	getFirebirdConfSync(status: Status): FirebirdConf;
	getFirebirdConfAsync(status: Status): Promise<FirebirdConf>;
	setReleaseDelaySync(status: Status, microSeconds: number): void;
	setReleaseDelayAsync(status: Status, microSeconds: number): Promise<void>;
}

export interface PluginFactory extends Versioned {
	createPluginSync(status: Status, factoryParameter: PluginConfig): PluginBase;
	createPluginAsync(status: Status, factoryParameter: PluginConfig): Promise<PluginBase>;
}

export interface PluginModule extends Versioned {
	doCleanSync(): void;
	doCleanAsync(): Promise<void>;
}

export interface PluginManager extends Versioned {
	registerPluginFactorySync(pluginType: number, defaultName: string, factory: PluginFactory): void;
	registerPluginFactoryAsync(pluginType: number, defaultName: string, factory: PluginFactory): Promise<void>;
	registerModuleSync(cleanup: PluginModule): void;
	registerModuleAsync(cleanup: PluginModule): Promise<void>;
	unregisterModuleSync(cleanup: PluginModule): void;
	unregisterModuleAsync(cleanup: PluginModule): Promise<void>;
	getPluginsSync(status: Status, pluginType: number, namesList: string, firebirdConf: FirebirdConf): PluginSet;
	getPluginsAsync(status: Status, pluginType: number, namesList: string, firebirdConf: FirebirdConf): Promise<PluginSet>;
	getConfigSync(status: Status, filename: string): Config;
	getConfigAsync(status: Status, filename: string): Promise<Config>;
	releasePluginSync(plugin: PluginBase): void;
	releasePluginAsync(plugin: PluginBase): Promise<void>;
}

export namespace PluginManager {
	export const TYPE_PROVIDER: number = 1;
	export const TYPE_FIRST_NON_LIB: number = 2;
	export const TYPE_AUTH_SERVER: number = 3;
	export const TYPE_AUTH_CLIENT: number = 4;
	export const TYPE_AUTH_USER_MANAGEMENT: number = 5;
	export const TYPE_EXTERNAL_ENGINE: number = 6;
	export const TYPE_TRACE: number = 7;
	export const TYPE_WIRE_CRYPT: number = 8;
	export const TYPE_DB_CRYPT: number = 9;
	export const TYPE_KEY_HOLDER: number = 10;
	export const TYPE_COUNT: number = 11;
}

export interface CryptKey extends Versioned {
}

export interface ConfigManager extends Versioned {
	getDirectorySync(code: number): string;
	getDirectoryAsync(code: number): Promise<string>;
	getFirebirdConfSync(): FirebirdConf;
	getFirebirdConfAsync(): Promise<FirebirdConf>;
	getDatabaseConfSync(dbName: string): FirebirdConf;
	getDatabaseConfAsync(dbName: string): Promise<FirebirdConf>;
	getPluginConfigSync(configuredPlugin: string): Config;
	getPluginConfigAsync(configuredPlugin: string): Promise<Config>;
	getInstallDirectorySync(): string;
	getInstallDirectoryAsync(): Promise<string>;
	getRootDirectorySync(): string;
	getRootDirectoryAsync(): Promise<string>;
}

export namespace ConfigManager {
	export const DIR_BIN: number = 0;
	export const DIR_SBIN: number = 1;
	export const DIR_CONF: number = 2;
	export const DIR_LIB: number = 3;
	export const DIR_INC: number = 4;
	export const DIR_DOC: number = 5;
	export const DIR_UDF: number = 6;
	export const DIR_SAMPLE: number = 7;
	export const DIR_SAMPLEDB: number = 8;
	export const DIR_HELP: number = 9;
	export const DIR_INTL: number = 10;
	export const DIR_MISC: number = 11;
	export const DIR_SECDB: number = 12;
	export const DIR_MSG: number = 13;
	export const DIR_LOG: number = 14;
	export const DIR_GUARD: number = 15;
	export const DIR_PLUGINS: number = 16;
	export const DIR_COUNT: number = 17;
}

export interface EventCallback extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	eventCallbackFunctionSync(length: number, events: Uint8Array | Pointer): void;
	eventCallbackFunctionAsync(length: number, events: Uint8Array | Pointer): Promise<void>;
}

export interface Blob extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getInfoSync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): void;
	getInfoAsync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): Promise<void>;
	getSegmentSync(status: Status, bufferLength: number, buffer: Uint8Array | Pointer, segmentLength: Uint32Array): number;
	getSegmentAsync(status: Status, bufferLength: number, buffer: Uint8Array | Pointer, segmentLength: Uint32Array): Promise<number>;
	putSegmentSync(status: Status, length: number, buffer: Uint8Array | Pointer): void;
	putSegmentAsync(status: Status, length: number, buffer: Uint8Array | Pointer): Promise<void>;
	cancelSync(status: Status): void;
	cancelAsync(status: Status): Promise<void>;
	closeSync(status: Status): void;
	closeAsync(status: Status): Promise<void>;
	seekSync(status: Status, mode: number, offset: number): number;
	seekAsync(status: Status, mode: number, offset: number): Promise<number>;
}

export interface Transaction extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getInfoSync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): void;
	getInfoAsync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): Promise<void>;
	prepareSync(status: Status, msgLength: number, message: Uint8Array | Pointer): void;
	prepareAsync(status: Status, msgLength: number, message: Uint8Array | Pointer): Promise<void>;
	commitSync(status: Status): void;
	commitAsync(status: Status): Promise<void>;
	commitRetainingSync(status: Status): void;
	commitRetainingAsync(status: Status): Promise<void>;
	rollbackSync(status: Status): void;
	rollbackAsync(status: Status): Promise<void>;
	rollbackRetainingSync(status: Status): void;
	rollbackRetainingAsync(status: Status): Promise<void>;
	disconnectSync(status: Status): void;
	disconnectAsync(status: Status): Promise<void>;
	joinSync(status: Status, transaction: Transaction): Transaction;
	joinAsync(status: Status, transaction: Transaction): Promise<Transaction>;
	validateSync(status: Status, attachment: Attachment): Transaction;
	validateAsync(status: Status, attachment: Attachment): Promise<Transaction>;
	enterDtcSync(status: Status): Transaction;
	enterDtcAsync(status: Status): Promise<Transaction>;
}

export interface MessageMetadata extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getCountSync(status: Status): number;
	getCountAsync(status: Status): Promise<number>;
	getFieldSync(status: Status, index: number): string;
	getFieldAsync(status: Status, index: number): Promise<string>;
	getRelationSync(status: Status, index: number): string;
	getRelationAsync(status: Status, index: number): Promise<string>;
	getOwnerSync(status: Status, index: number): string;
	getOwnerAsync(status: Status, index: number): Promise<string>;
	getAliasSync(status: Status, index: number): string;
	getAliasAsync(status: Status, index: number): Promise<string>;
	getTypeSync(status: Status, index: number): number;
	getTypeAsync(status: Status, index: number): Promise<number>;
	isNullableSync(status: Status, index: number): boolean;
	isNullableAsync(status: Status, index: number): Promise<boolean>;
	getSubTypeSync(status: Status, index: number): number;
	getSubTypeAsync(status: Status, index: number): Promise<number>;
	getLengthSync(status: Status, index: number): number;
	getLengthAsync(status: Status, index: number): Promise<number>;
	getScaleSync(status: Status, index: number): number;
	getScaleAsync(status: Status, index: number): Promise<number>;
	getCharSetSync(status: Status, index: number): number;
	getCharSetAsync(status: Status, index: number): Promise<number>;
	getOffsetSync(status: Status, index: number): number;
	getOffsetAsync(status: Status, index: number): Promise<number>;
	getNullOffsetSync(status: Status, index: number): number;
	getNullOffsetAsync(status: Status, index: number): Promise<number>;
	getBuilderSync(status: Status): MetadataBuilder;
	getBuilderAsync(status: Status): Promise<MetadataBuilder>;
	getMessageLengthSync(status: Status): number;
	getMessageLengthAsync(status: Status): Promise<number>;
}

export interface MetadataBuilder extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setTypeSync(status: Status, index: number, type: number): void;
	setTypeAsync(status: Status, index: number, type: number): Promise<void>;
	setSubTypeSync(status: Status, index: number, subType: number): void;
	setSubTypeAsync(status: Status, index: number, subType: number): Promise<void>;
	setLengthSync(status: Status, index: number, length: number): void;
	setLengthAsync(status: Status, index: number, length: number): Promise<void>;
	setCharSetSync(status: Status, index: number, charSet: number): void;
	setCharSetAsync(status: Status, index: number, charSet: number): Promise<void>;
	setScaleSync(status: Status, index: number, scale: number): void;
	setScaleAsync(status: Status, index: number, scale: number): Promise<void>;
	truncateSync(status: Status, count: number): void;
	truncateAsync(status: Status, count: number): Promise<void>;
	moveNameToIndexSync(status: Status, name: string, index: number): void;
	moveNameToIndexAsync(status: Status, name: string, index: number): Promise<void>;
	removeSync(status: Status, index: number): void;
	removeAsync(status: Status, index: number): Promise<void>;
	addFieldSync(status: Status): number;
	addFieldAsync(status: Status): Promise<number>;
	getMetadataSync(status: Status): MessageMetadata;
	getMetadataAsync(status: Status): Promise<MessageMetadata>;
}

export interface ResultSet extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	fetchNextSync(status: Status, message: Uint8Array | Pointer): number;
	fetchNextAsync(status: Status, message: Uint8Array | Pointer): Promise<number>;
	fetchPriorSync(status: Status, message: Uint8Array | Pointer): number;
	fetchPriorAsync(status: Status, message: Uint8Array | Pointer): Promise<number>;
	fetchFirstSync(status: Status, message: Uint8Array | Pointer): number;
	fetchFirstAsync(status: Status, message: Uint8Array | Pointer): Promise<number>;
	fetchLastSync(status: Status, message: Uint8Array | Pointer): number;
	fetchLastAsync(status: Status, message: Uint8Array | Pointer): Promise<number>;
	fetchAbsoluteSync(status: Status, position: number, message: Uint8Array | Pointer): number;
	fetchAbsoluteAsync(status: Status, position: number, message: Uint8Array | Pointer): Promise<number>;
	fetchRelativeSync(status: Status, offset: number, message: Uint8Array | Pointer): number;
	fetchRelativeAsync(status: Status, offset: number, message: Uint8Array | Pointer): Promise<number>;
	isEofSync(status: Status): boolean;
	isEofAsync(status: Status): Promise<boolean>;
	isBofSync(status: Status): boolean;
	isBofAsync(status: Status): Promise<boolean>;
	getMetadataSync(status: Status): MessageMetadata;
	getMetadataAsync(status: Status): Promise<MessageMetadata>;
	closeSync(status: Status): void;
	closeAsync(status: Status): Promise<void>;
	setDelayedOutputFormatSync(status: Status, format: MessageMetadata): void;
	setDelayedOutputFormatAsync(status: Status, format: MessageMetadata): Promise<void>;
}

export interface Statement extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getInfoSync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): void;
	getInfoAsync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): Promise<void>;
	getTypeSync(status: Status): number;
	getTypeAsync(status: Status): Promise<number>;
	getPlanSync(status: Status, detailed: boolean): string;
	getPlanAsync(status: Status, detailed: boolean): Promise<string>;
	getAffectedRecordsSync(status: Status): number;
	getAffectedRecordsAsync(status: Status): Promise<number>;
	getInputMetadataSync(status: Status): MessageMetadata;
	getInputMetadataAsync(status: Status): Promise<MessageMetadata>;
	getOutputMetadataSync(status: Status): MessageMetadata;
	getOutputMetadataAsync(status: Status): Promise<MessageMetadata>;
	executeSync(status: Status, transaction: Transaction, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, outBuffer: Uint8Array | Pointer): Transaction;
	executeAsync(status: Status, transaction: Transaction, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, outBuffer: Uint8Array | Pointer): Promise<Transaction>;
	openCursorSync(status: Status, transaction: Transaction, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, flags: number): ResultSet;
	openCursorAsync(status: Status, transaction: Transaction, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, flags: number): Promise<ResultSet>;
	setCursorNameSync(status: Status, name: string): void;
	setCursorNameAsync(status: Status, name: string): Promise<void>;
	freeSync(status: Status): void;
	freeAsync(status: Status): Promise<void>;
	getFlagsSync(status: Status): number;
	getFlagsAsync(status: Status): Promise<number>;
}

export namespace Statement {
	export const PREPARE_PREFETCH_NONE: number = 0;
	export const PREPARE_PREFETCH_TYPE: number = 1;
	export const PREPARE_PREFETCH_INPUT_PARAMETERS: number = 2;
	export const PREPARE_PREFETCH_OUTPUT_PARAMETERS: number = 4;
	export const PREPARE_PREFETCH_LEGACY_PLAN: number = 8;
	export const PREPARE_PREFETCH_DETAILED_PLAN: number = 16;
	export const PREPARE_PREFETCH_AFFECTED_RECORDS: number = 32;
	export const PREPARE_PREFETCH_FLAGS: number = 64;
	export const PREPARE_PREFETCH_METADATA: number = (Statement.PREPARE_PREFETCH_TYPE) | ((Statement.PREPARE_PREFETCH_FLAGS) | ((Statement.PREPARE_PREFETCH_INPUT_PARAMETERS) | (Statement.PREPARE_PREFETCH_OUTPUT_PARAMETERS)));
	export const PREPARE_PREFETCH_ALL: number = (Statement.PREPARE_PREFETCH_METADATA) | ((Statement.PREPARE_PREFETCH_LEGACY_PLAN) | ((Statement.PREPARE_PREFETCH_DETAILED_PLAN) | (Statement.PREPARE_PREFETCH_AFFECTED_RECORDS)));
	export const FLAG_HAS_CURSOR: number = 1;
	export const FLAG_REPEAT_EXECUTE: number = 2;
	export const CURSOR_TYPE_SCROLLABLE: number = 1;
}

export interface Request extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	receiveSync(status: Status, level: number, msgType: number, length: number, message: Uint8Array | Pointer): void;
	receiveAsync(status: Status, level: number, msgType: number, length: number, message: Uint8Array | Pointer): Promise<void>;
	sendSync(status: Status, level: number, msgType: number, length: number, message: Uint8Array | Pointer): void;
	sendAsync(status: Status, level: number, msgType: number, length: number, message: Uint8Array | Pointer): Promise<void>;
	getInfoSync(status: Status, level: number, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): void;
	getInfoAsync(status: Status, level: number, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): Promise<void>;
	startSync(status: Status, tra: Transaction, level: number): void;
	startAsync(status: Status, tra: Transaction, level: number): Promise<void>;
	startAndSendSync(status: Status, tra: Transaction, level: number, msgType: number, length: number, message: Uint8Array | Pointer): void;
	startAndSendAsync(status: Status, tra: Transaction, level: number, msgType: number, length: number, message: Uint8Array | Pointer): Promise<void>;
	unwindSync(status: Status, level: number): void;
	unwindAsync(status: Status, level: number): Promise<void>;
	freeSync(status: Status): void;
	freeAsync(status: Status): Promise<void>;
}

export interface Events extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	cancelSync(status: Status): void;
	cancelAsync(status: Status): Promise<void>;
}

export interface Attachment extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getInfoSync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): void;
	getInfoAsync(status: Status, itemsLength: number, items: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): Promise<void>;
	startTransactionSync(status: Status, tpbLength: number, tpb: Uint8Array | Pointer): Transaction;
	startTransactionAsync(status: Status, tpbLength: number, tpb: Uint8Array | Pointer): Promise<Transaction>;
	reconnectTransactionSync(status: Status, length: number, id: Uint8Array | Pointer): Transaction;
	reconnectTransactionAsync(status: Status, length: number, id: Uint8Array | Pointer): Promise<Transaction>;
	compileRequestSync(status: Status, blrLength: number, blr: Uint8Array | Pointer): Request;
	compileRequestAsync(status: Status, blrLength: number, blr: Uint8Array | Pointer): Promise<Request>;
	transactRequestSync(status: Status, transaction: Transaction, blrLength: number, blr: Uint8Array | Pointer, inMsgLength: number, inMsg: Uint8Array | Pointer, outMsgLength: number, outMsg: Uint8Array | Pointer): void;
	transactRequestAsync(status: Status, transaction: Transaction, blrLength: number, blr: Uint8Array | Pointer, inMsgLength: number, inMsg: Uint8Array | Pointer, outMsgLength: number, outMsg: Uint8Array | Pointer): Promise<void>;
	executeDynSync(status: Status, transaction: Transaction, length: number, dyn: Uint8Array | Pointer): void;
	executeDynAsync(status: Status, transaction: Transaction, length: number, dyn: Uint8Array | Pointer): Promise<void>;
	prepareSync(status: Status, tra: Transaction, stmtLength: number, sqlStmt: string, dialect: number, flags: number): Statement;
	prepareAsync(status: Status, tra: Transaction, stmtLength: number, sqlStmt: string, dialect: number, flags: number): Promise<Statement>;
	executeSync(status: Status, transaction: Transaction, stmtLength: number, sqlStmt: string, dialect: number, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, outBuffer: Uint8Array | Pointer): Transaction;
	executeAsync(status: Status, transaction: Transaction, stmtLength: number, sqlStmt: string, dialect: number, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, outBuffer: Uint8Array | Pointer): Promise<Transaction>;
	openCursorSync(status: Status, transaction: Transaction, stmtLength: number, sqlStmt: string, dialect: number, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, cursorName: string, cursorFlags: number): ResultSet;
	openCursorAsync(status: Status, transaction: Transaction, stmtLength: number, sqlStmt: string, dialect: number, inMetadata: MessageMetadata, inBuffer: Uint8Array | Pointer, outMetadata: MessageMetadata, cursorName: string, cursorFlags: number): Promise<ResultSet>;
	queEventsSync(status: Status, callback: EventCallback, length: number, events: Uint8Array | Pointer): Events;
	queEventsAsync(status: Status, callback: EventCallback, length: number, events: Uint8Array | Pointer): Promise<Events>;
	cancelOperationSync(status: Status, option: number): void;
	cancelOperationAsync(status: Status, option: number): Promise<void>;
	pingSync(status: Status): void;
	pingAsync(status: Status): Promise<void>;
	detachSync(status: Status): void;
	detachAsync(status: Status): Promise<void>;
	dropDatabaseSync(status: Status): void;
	dropDatabaseAsync(status: Status): Promise<void>;
}

export interface Service extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	detachSync(status: Status): void;
	detachAsync(status: Status): Promise<void>;
	querySync(status: Status, sendLength: number, sendItems: Uint8Array | Pointer, receiveLength: number, receiveItems: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): void;
	queryAsync(status: Status, sendLength: number, sendItems: Uint8Array | Pointer, receiveLength: number, receiveItems: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): Promise<void>;
	startSync(status: Status, spbLength: number, spb: Uint8Array | Pointer): void;
	startAsync(status: Status, spbLength: number, spb: Uint8Array | Pointer): Promise<void>;
}

export interface Provider extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
	attachDatabaseSync(status: Status, fileName: string, dpbLength: number, dpb: Uint8Array | Pointer): Attachment;
	attachDatabaseAsync(status: Status, fileName: string, dpbLength: number, dpb: Uint8Array | Pointer): Promise<Attachment>;
	createDatabaseSync(status: Status, fileName: string, dpbLength: number, dpb: Uint8Array | Pointer): Attachment;
	createDatabaseAsync(status: Status, fileName: string, dpbLength: number, dpb: Uint8Array | Pointer): Promise<Attachment>;
	attachServiceManagerSync(status: Status, service: string, spbLength: number, spb: Uint8Array | Pointer): Service;
	attachServiceManagerAsync(status: Status, service: string, spbLength: number, spb: Uint8Array | Pointer): Promise<Service>;
	shutdownSync(status: Status, timeout: number, reason: number): void;
	shutdownAsync(status: Status, timeout: number, reason: number): Promise<void>;
	setDbCryptCallbackSync(status: Status, cryptCallback: CryptKeyCallback): void;
	setDbCryptCallbackAsync(status: Status, cryptCallback: CryptKeyCallback): Promise<void>;
}

export interface DtcStart extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
	addAttachmentSync(status: Status, att: Attachment): void;
	addAttachmentAsync(status: Status, att: Attachment): Promise<void>;
	addWithTpbSync(status: Status, att: Attachment, length: number, tpb: Uint8Array | Pointer): void;
	addWithTpbAsync(status: Status, att: Attachment, length: number, tpb: Uint8Array | Pointer): Promise<void>;
	startSync(status: Status): Transaction;
	startAsync(status: Status): Promise<Transaction>;
}

export interface Dtc extends Versioned {
	joinSync(status: Status, one: Transaction, two: Transaction): Transaction;
	joinAsync(status: Status, one: Transaction, two: Transaction): Promise<Transaction>;
	startBuilderSync(status: Status): DtcStart;
	startBuilderAsync(status: Status): Promise<DtcStart>;
}

export interface Auth extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
}

export namespace Auth {
	export const AUTH_FAILED: number = (-1);
	export const AUTH_SUCCESS: number = 0;
	export const AUTH_MORE_DATA: number = 1;
	export const AUTH_CONTINUE: number = 2;
}

export interface Writer extends Versioned {
	resetSync(): void;
	resetAsync(): Promise<void>;
	addSync(status: Status, name: string): void;
	addAsync(status: Status, name: string): Promise<void>;
	setTypeSync(status: Status, value: string): void;
	setTypeAsync(status: Status, value: string): Promise<void>;
	setDbSync(status: Status, value: string): void;
	setDbAsync(status: Status, value: string): Promise<void>;
}

export interface ServerBlock extends Versioned {
	getLoginSync(): string;
	getLoginAsync(): Promise<string>;
	getDataSync(length: Uint32Array): Pointer;
	getDataAsync(length: Uint32Array): Promise<Pointer>;
	putDataSync(status: Status, length: number, data: Uint8Array | Pointer): void;
	putDataAsync(status: Status, length: number, data: Uint8Array | Pointer): Promise<void>;
	newKeySync(status: Status): CryptKey;
	newKeyAsync(status: Status): Promise<CryptKey>;
}

export interface ClientBlock extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	getLoginSync(): string;
	getLoginAsync(): Promise<string>;
	getPasswordSync(): string;
	getPasswordAsync(): Promise<string>;
	getDataSync(length: Uint32Array): Pointer;
	getDataAsync(length: Uint32Array): Promise<Pointer>;
	putDataSync(status: Status, length: number, data: Uint8Array | Pointer): void;
	putDataAsync(status: Status, length: number, data: Uint8Array | Pointer): Promise<void>;
	newKeySync(status: Status): CryptKey;
	newKeyAsync(status: Status): Promise<CryptKey>;
}

export interface Server extends Auth {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
	authenticateSync(status: Status, sBlock: ServerBlock, writerInterface: Writer): number;
	authenticateAsync(status: Status, sBlock: ServerBlock, writerInterface: Writer): Promise<number>;
}

export interface Client extends Auth {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
	authenticateSync(status: Status, cBlock: ClientBlock): number;
	authenticateAsync(status: Status, cBlock: ClientBlock): Promise<number>;
}

export interface UserField extends Versioned {
	enteredSync(): number;
	enteredAsync(): Promise<number>;
	specifiedSync(): number;
	specifiedAsync(): Promise<number>;
	setEnteredSync(status: Status, newValue: number): void;
	setEnteredAsync(status: Status, newValue: number): Promise<void>;
}

export interface CharUserField extends UserField {
	enteredSync(): number;
	enteredAsync(): Promise<number>;
	specifiedSync(): number;
	specifiedAsync(): Promise<number>;
	setEnteredSync(status: Status, newValue: number): void;
	setEnteredAsync(status: Status, newValue: number): Promise<void>;
	getSync(): string;
	getAsync(): Promise<string>;
	setSync(status: Status, newValue: string): void;
	setAsync(status: Status, newValue: string): Promise<void>;
}

export interface IntUserField extends UserField {
	enteredSync(): number;
	enteredAsync(): Promise<number>;
	specifiedSync(): number;
	specifiedAsync(): Promise<number>;
	setEnteredSync(status: Status, newValue: number): void;
	setEnteredAsync(status: Status, newValue: number): Promise<void>;
	getSync(): number;
	getAsync(): Promise<number>;
	setSync(status: Status, newValue: number): void;
	setAsync(status: Status, newValue: number): Promise<void>;
}

export interface User extends Versioned {
	operationSync(): number;
	operationAsync(): Promise<number>;
	userNameSync(): CharUserField;
	userNameAsync(): Promise<CharUserField>;
	passwordSync(): CharUserField;
	passwordAsync(): Promise<CharUserField>;
	firstNameSync(): CharUserField;
	firstNameAsync(): Promise<CharUserField>;
	lastNameSync(): CharUserField;
	lastNameAsync(): Promise<CharUserField>;
	middleNameSync(): CharUserField;
	middleNameAsync(): Promise<CharUserField>;
	commentSync(): CharUserField;
	commentAsync(): Promise<CharUserField>;
	attributesSync(): CharUserField;
	attributesAsync(): Promise<CharUserField>;
	activeSync(): IntUserField;
	activeAsync(): Promise<IntUserField>;
	adminSync(): IntUserField;
	adminAsync(): Promise<IntUserField>;
	clearSync(status: Status): void;
	clearAsync(status: Status): Promise<void>;
}

export namespace User {
	export const OP_USER_ADD: number = 1;
	export const OP_USER_MODIFY: number = 2;
	export const OP_USER_DELETE: number = 3;
	export const OP_USER_DISPLAY: number = 4;
	export const OP_USER_SET_MAP: number = 5;
	export const OP_USER_DROP_MAP: number = 6;
}

export interface ListUsers extends Versioned {
	listSync(status: Status, user: User): void;
	listAsync(status: Status, user: User): Promise<void>;
}

export interface LogonInfo extends Versioned {
	nameSync(): string;
	nameAsync(): Promise<string>;
	roleSync(): string;
	roleAsync(): Promise<string>;
	networkProtocolSync(): string;
	networkProtocolAsync(): Promise<string>;
	remoteAddressSync(): string;
	remoteAddressAsync(): Promise<string>;
	authBlockSync(length: Uint32Array): Pointer;
	authBlockAsync(length: Uint32Array): Promise<Pointer>;
}

export interface Management extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
	startSync(status: Status, logonInfo: LogonInfo): void;
	startAsync(status: Status, logonInfo: LogonInfo): Promise<void>;
	executeSync(status: Status, user: User, callback: ListUsers): number;
	executeAsync(status: Status, user: User, callback: ListUsers): Promise<number>;
	commitSync(status: Status): void;
	commitAsync(status: Status): Promise<void>;
	rollbackSync(status: Status): void;
	rollbackAsync(status: Status): Promise<void>;
}

export interface WireCryptPlugin extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
	getKnownTypesSync(status: Status): string;
	getKnownTypesAsync(status: Status): Promise<string>;
	setKeySync(status: Status, key: CryptKey): void;
	setKeyAsync(status: Status, key: CryptKey): Promise<void>;
	encryptSync(status: Status, length: number, from: Uint8Array | Pointer, to: Uint8Array | Pointer): void;
	encryptAsync(status: Status, length: number, from: Uint8Array | Pointer, to: Uint8Array | Pointer): Promise<void>;
	decryptSync(status: Status, length: number, from: Uint8Array | Pointer, to: Uint8Array | Pointer): void;
	decryptAsync(status: Status, length: number, from: Uint8Array | Pointer, to: Uint8Array | Pointer): Promise<void>;
}

export interface CryptKeyCallback extends Versioned {
	callbackSync(dataLength: number, data: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): number;
	callbackAsync(dataLength: number, data: Uint8Array | Pointer, bufferLength: number, buffer: Uint8Array | Pointer): Promise<number>;
}

export interface KeyHolderPlugin extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
	keyCallbackSync(status: Status, callback: CryptKeyCallback): number;
	keyCallbackAsync(status: Status, callback: CryptKeyCallback): Promise<number>;
	keyHandleSync(status: Status, keyName: string): CryptKeyCallback;
	keyHandleAsync(status: Status, keyName: string): Promise<CryptKeyCallback>;
}

export interface DbCryptPlugin extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
}

export interface ExternalContext extends Versioned {
}

export interface ExternalResultSet extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
	fetchSync(status: Status): boolean;
	fetchAsync(status: Status): Promise<boolean>;
}

export interface ExternalFunction extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
}

export interface ExternalProcedure extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
}

export interface ExternalTrigger extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
}

export namespace ExternalTrigger {
	export const TYPE_BEFORE: number = 1;
	export const TYPE_AFTER: number = 2;
	export const TYPE_DATABASE: number = 3;
	export const ACTION_INSERT: number = 1;
	export const ACTION_UPDATE: number = 2;
	export const ACTION_DELETE: number = 3;
	export const ACTION_CONNECT: number = 4;
	export const ACTION_DISCONNECT: number = 5;
	export const ACTION_TRANS_START: number = 6;
	export const ACTION_TRANS_COMMIT: number = 7;
	export const ACTION_TRANS_ROLLBACK: number = 8;
	export const ACTION_DDL: number = 9;
}

export interface RoutineMetadata extends Versioned {
	getPackageSync(status: Status): string;
	getPackageAsync(status: Status): Promise<string>;
	getNameSync(status: Status): string;
	getNameAsync(status: Status): Promise<string>;
	getEntryPointSync(status: Status): string;
	getEntryPointAsync(status: Status): Promise<string>;
	getBodySync(status: Status): string;
	getBodyAsync(status: Status): Promise<string>;
	getInputMetadataSync(status: Status): MessageMetadata;
	getInputMetadataAsync(status: Status): Promise<MessageMetadata>;
	getOutputMetadataSync(status: Status): MessageMetadata;
	getOutputMetadataAsync(status: Status): Promise<MessageMetadata>;
	getTriggerMetadataSync(status: Status): MessageMetadata;
	getTriggerMetadataAsync(status: Status): Promise<MessageMetadata>;
	getTriggerTableSync(status: Status): string;
	getTriggerTableAsync(status: Status): Promise<string>;
	getTriggerTypeSync(status: Status): number;
	getTriggerTypeAsync(status: Status): Promise<number>;
}

export interface ExternalEngine extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
}

export interface Timer extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	handlerSync(): void;
	handlerAsync(): Promise<void>;
}

export interface TimerControl extends Versioned {
	startSync(status: Status, timer: Timer, microSeconds: number): void;
	startAsync(status: Status, timer: Timer, microSeconds: number): Promise<void>;
	stopSync(status: Status, timer: Timer): void;
	stopAsync(status: Status, timer: Timer): Promise<void>;
}

export interface VersionCallback extends Versioned {
	callbackSync(status: Status, text: string): void;
	callbackAsync(status: Status, text: string): Promise<void>;
}

export interface Util extends Versioned {
	getFbVersionSync(status: Status, att: Attachment, callback: VersionCallback): void;
	getFbVersionAsync(status: Status, att: Attachment, callback: VersionCallback): Promise<void>;
	executeCreateDatabaseSync(status: Status, stmtLength: number, creatDBstatement: string, dialect: number, stmtIsCreateDb: Uint8Array | Pointer): Attachment;
	executeCreateDatabaseAsync(status: Status, stmtLength: number, creatDBstatement: string, dialect: number, stmtIsCreateDb: Uint8Array | Pointer): Promise<Attachment>;
	decodeDateSync(date: number, year: Uint32Array, month: Uint32Array, day: Uint32Array): void;
	decodeDateAsync(date: number, year: Uint32Array, month: Uint32Array, day: Uint32Array): Promise<void>;
	decodeTimeSync(time: number, hours: Uint32Array, minutes: Uint32Array, seconds: Uint32Array, fractions: Uint32Array): void;
	decodeTimeAsync(time: number, hours: Uint32Array, minutes: Uint32Array, seconds: Uint32Array, fractions: Uint32Array): Promise<void>;
	encodeDateSync(year: number, month: number, day: number): number;
	encodeDateAsync(year: number, month: number, day: number): Promise<number>;
	encodeTimeSync(hours: number, minutes: number, seconds: number, fractions: number): number;
	encodeTimeAsync(hours: number, minutes: number, seconds: number, fractions: number): Promise<number>;
	getClientVersionSync(): number;
	getClientVersionAsync(): Promise<number>;
	getXpbBuilderSync(status: Status, kind: number, buf: Uint8Array | Pointer, len: number): XpbBuilder;
	getXpbBuilderAsync(status: Status, kind: number, buf: Uint8Array | Pointer, len: number): Promise<XpbBuilder>;
	setOffsetsSync(status: Status, metadata: MessageMetadata, callback: OffsetsCallback): number;
	setOffsetsAsync(status: Status, metadata: MessageMetadata, callback: OffsetsCallback): Promise<number>;
}

export interface OffsetsCallback extends Versioned {
	setOffsetSync(status: Status, index: number, offset: number, nullOffset: number): void;
	setOffsetAsync(status: Status, index: number, offset: number, nullOffset: number): Promise<void>;
}

export interface XpbBuilder extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
	clearSync(status: Status): void;
	clearAsync(status: Status): Promise<void>;
	removeCurrentSync(status: Status): void;
	removeCurrentAsync(status: Status): Promise<void>;
	insertIntSync(status: Status, tag: number, value: number): void;
	insertIntAsync(status: Status, tag: number, value: number): Promise<void>;
	insertBigIntSync(status: Status, tag: number, value: number): void;
	insertBigIntAsync(status: Status, tag: number, value: number): Promise<void>;
	insertBytesSync(status: Status, tag: number, bytes: Uint8Array | Pointer, length: number): void;
	insertBytesAsync(status: Status, tag: number, bytes: Uint8Array | Pointer, length: number): Promise<void>;
	insertStringSync(status: Status, tag: number, str: string): void;
	insertStringAsync(status: Status, tag: number, str: string): Promise<void>;
	insertTagSync(status: Status, tag: number): void;
	insertTagAsync(status: Status, tag: number): Promise<void>;
	isEofSync(status: Status): boolean;
	isEofAsync(status: Status): Promise<boolean>;
	moveNextSync(status: Status): void;
	moveNextAsync(status: Status): Promise<void>;
	rewindSync(status: Status): void;
	rewindAsync(status: Status): Promise<void>;
	findFirstSync(status: Status, tag: number): boolean;
	findFirstAsync(status: Status, tag: number): Promise<boolean>;
	findNextSync(status: Status): boolean;
	findNextAsync(status: Status): Promise<boolean>;
	getTagSync(status: Status): number;
	getTagAsync(status: Status): Promise<number>;
	getLengthSync(status: Status): number;
	getLengthAsync(status: Status): Promise<number>;
	getIntSync(status: Status): number;
	getIntAsync(status: Status): Promise<number>;
	getBigIntSync(status: Status): number;
	getBigIntAsync(status: Status): Promise<number>;
	getStringSync(status: Status): string;
	getStringAsync(status: Status): Promise<string>;
	getBytesSync(status: Status): Pointer;
	getBytesAsync(status: Status): Promise<Pointer>;
	getBufferLengthSync(status: Status): number;
	getBufferLengthAsync(status: Status): Promise<number>;
	getBufferSync(status: Status): Pointer;
	getBufferAsync(status: Status): Promise<Pointer>;
}

export namespace XpbBuilder {
	export const DPB: number = 1;
	export const SPB_ATTACH: number = 2;
	export const SPB_START: number = 3;
	export const TPB: number = 4;
}

export interface TraceConnection extends Versioned {
	getKindSync(): number;
	getKindAsync(): Promise<number>;
	getProcessIDSync(): number;
	getProcessIDAsync(): Promise<number>;
	getUserNameSync(): string;
	getUserNameAsync(): Promise<string>;
	getRoleNameSync(): string;
	getRoleNameAsync(): Promise<string>;
	getCharSetSync(): string;
	getCharSetAsync(): Promise<string>;
	getRemoteProtocolSync(): string;
	getRemoteProtocolAsync(): Promise<string>;
	getRemoteAddressSync(): string;
	getRemoteAddressAsync(): Promise<string>;
	getRemoteProcessIDSync(): number;
	getRemoteProcessIDAsync(): Promise<number>;
	getRemoteProcessNameSync(): string;
	getRemoteProcessNameAsync(): Promise<string>;
}

export namespace TraceConnection {
	export const KIND_DATABASE: number = 1;
	export const KIND_SERVICE: number = 2;
}

export interface TraceDatabaseConnection extends TraceConnection {
	getKindSync(): number;
	getKindAsync(): Promise<number>;
	getProcessIDSync(): number;
	getProcessIDAsync(): Promise<number>;
	getUserNameSync(): string;
	getUserNameAsync(): Promise<string>;
	getRoleNameSync(): string;
	getRoleNameAsync(): Promise<string>;
	getCharSetSync(): string;
	getCharSetAsync(): Promise<string>;
	getRemoteProtocolSync(): string;
	getRemoteProtocolAsync(): Promise<string>;
	getRemoteAddressSync(): string;
	getRemoteAddressAsync(): Promise<string>;
	getRemoteProcessIDSync(): number;
	getRemoteProcessIDAsync(): Promise<number>;
	getRemoteProcessNameSync(): string;
	getRemoteProcessNameAsync(): Promise<string>;
	getConnectionIDSync(): number;
	getConnectionIDAsync(): Promise<number>;
	getDatabaseNameSync(): string;
	getDatabaseNameAsync(): Promise<string>;
}

export interface TraceTransaction extends Versioned {
}

export namespace TraceTransaction {
	export const ISOLATION_CONSISTENCY: number = 1;
	export const ISOLATION_CONCURRENCY: number = 2;
	export const ISOLATION_READ_COMMITTED_RECVER: number = 3;
	export const ISOLATION_READ_COMMITTED_NORECVER: number = 4;
}

export interface TraceParams extends Versioned {
}

export interface TraceStatement extends Versioned {
}

export interface TraceSQLStatement extends TraceStatement {
}

export interface TraceBLRStatement extends TraceStatement {
}

export interface TraceDYNRequest extends Versioned {
}

export interface TraceContextVariable extends Versioned {
}

export interface TraceProcedure extends Versioned {
}

export interface TraceFunction extends Versioned {
}

export interface TraceTrigger extends Versioned {
}

export namespace TraceTrigger {
	export const TYPE_ALL: number = 0;
	export const TYPE_BEFORE: number = 1;
	export const TYPE_AFTER: number = 2;
}

export interface TraceServiceConnection extends TraceConnection {
	getKindSync(): number;
	getKindAsync(): Promise<number>;
	getProcessIDSync(): number;
	getProcessIDAsync(): Promise<number>;
	getUserNameSync(): string;
	getUserNameAsync(): Promise<string>;
	getRoleNameSync(): string;
	getRoleNameAsync(): Promise<string>;
	getCharSetSync(): string;
	getCharSetAsync(): Promise<string>;
	getRemoteProtocolSync(): string;
	getRemoteProtocolAsync(): Promise<string>;
	getRemoteAddressSync(): string;
	getRemoteAddressAsync(): Promise<string>;
	getRemoteProcessIDSync(): number;
	getRemoteProcessIDAsync(): Promise<number>;
	getRemoteProcessNameSync(): string;
	getRemoteProcessNameAsync(): Promise<string>;
}

export interface TraceStatusVector extends Versioned {
}

export interface TraceSweepInfo extends Versioned {
}

export interface TraceLogWriter extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
}

export interface TraceInitInfo extends Versioned {
}

export interface TracePlugin extends ReferenceCounted {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
}

export namespace TracePlugin {
	export const RESULT_SUCCESS: number = 0;
	export const RESULT_FAILED: number = 1;
	export const RESULT_UNAUTHORIZED: number = 2;
	export const SWEEP_STATE_STARTED: number = 1;
	export const SWEEP_STATE_FINISHED: number = 2;
	export const SWEEP_STATE_FAILED: number = 3;
	export const SWEEP_STATE_PROGRESS: number = 4;
}

export interface TraceFactory extends PluginBase {
	addRefSync(): void;
	addRefAsync(): Promise<void>;
	releaseSync(): number;
	releaseAsync(): Promise<number>;
	setOwnerSync(r: ReferenceCounted): void;
	setOwnerAsync(r: ReferenceCounted): Promise<void>;
	getOwnerSync(): ReferenceCounted;
	getOwnerAsync(): Promise<ReferenceCounted>;
}

export namespace TraceFactory {
	export const TRACE_EVENT_ATTACH: number = 0;
	export const TRACE_EVENT_DETACH: number = 1;
	export const TRACE_EVENT_TRANSACTION_START: number = 2;
	export const TRACE_EVENT_TRANSACTION_END: number = 3;
	export const TRACE_EVENT_SET_CONTEXT: number = 4;
	export const TRACE_EVENT_PROC_EXECUTE: number = 5;
	export const TRACE_EVENT_TRIGGER_EXECUTE: number = 6;
	export const TRACE_EVENT_DSQL_PREPARE: number = 7;
	export const TRACE_EVENT_DSQL_FREE: number = 8;
	export const TRACE_EVENT_DSQL_EXECUTE: number = 9;
	export const TRACE_EVENT_BLR_COMPILE: number = 10;
	export const TRACE_EVENT_BLR_EXECUTE: number = 11;
	export const TRACE_EVENT_DYN_EXECUTE: number = 12;
	export const TRACE_EVENT_SERVICE_ATTACH: number = 13;
	export const TRACE_EVENT_SERVICE_START: number = 14;
	export const TRACE_EVENT_SERVICE_QUERY: number = 15;
	export const TRACE_EVENT_SERVICE_DETACH: number = 16;
	export const TRACE_EVENT_ERROR: number = 17;
	export const TRACE_EVENT_SWEEP: number = 18;
	export const TRACE_EVENT_FUNC_EXECUTE: number = 19;
	export const TRACE_EVENT_MAX: number = 20;
}

export interface UdrFunctionFactory extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
	setupSync(status: Status, context: ExternalContext, metadata: RoutineMetadata, inBuilder: MetadataBuilder, outBuilder: MetadataBuilder): void;
	setupAsync(status: Status, context: ExternalContext, metadata: RoutineMetadata, inBuilder: MetadataBuilder, outBuilder: MetadataBuilder): Promise<void>;
	newItemSync(status: Status, context: ExternalContext, metadata: RoutineMetadata): ExternalFunction;
	newItemAsync(status: Status, context: ExternalContext, metadata: RoutineMetadata): Promise<ExternalFunction>;
}

export interface UdrProcedureFactory extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
	setupSync(status: Status, context: ExternalContext, metadata: RoutineMetadata, inBuilder: MetadataBuilder, outBuilder: MetadataBuilder): void;
	setupAsync(status: Status, context: ExternalContext, metadata: RoutineMetadata, inBuilder: MetadataBuilder, outBuilder: MetadataBuilder): Promise<void>;
	newItemSync(status: Status, context: ExternalContext, metadata: RoutineMetadata): ExternalProcedure;
	newItemAsync(status: Status, context: ExternalContext, metadata: RoutineMetadata): Promise<ExternalProcedure>;
}

export interface UdrTriggerFactory extends Disposable {
	disposeSync(): void;
	disposeAsync(): Promise<void>;
	setupSync(status: Status, context: ExternalContext, metadata: RoutineMetadata, fieldsBuilder: MetadataBuilder): void;
	setupAsync(status: Status, context: ExternalContext, metadata: RoutineMetadata, fieldsBuilder: MetadataBuilder): Promise<void>;
	newItemSync(status: Status, context: ExternalContext, metadata: RoutineMetadata): ExternalTrigger;
	newItemAsync(status: Status, context: ExternalContext, metadata: RoutineMetadata): Promise<ExternalTrigger>;
}

export interface UdrPlugin extends Versioned {
	getMasterSync(): Master;
	getMasterAsync(): Promise<Master>;
	registerFunctionSync(status: Status, name: string, factory: UdrFunctionFactory): void;
	registerFunctionAsync(status: Status, name: string, factory: UdrFunctionFactory): Promise<void>;
	registerProcedureSync(status: Status, name: string, factory: UdrProcedureFactory): void;
	registerProcedureAsync(status: Status, name: string, factory: UdrProcedureFactory): Promise<void>;
	registerTriggerSync(status: Status, name: string, factory: UdrTriggerFactory): void;
	registerTriggerAsync(status: Status, name: string, factory: UdrTriggerFactory): Promise<void>;
}
