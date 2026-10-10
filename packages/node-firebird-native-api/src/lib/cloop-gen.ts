// Auto-generated file. Do not edit!

/* eslint-disable @typescript-eslint/no-inferrable-types */

export interface Pointer {}

export interface Versioned {}

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
  cloneSync(): Status | undefined;
  cloneAsync(): Promise<Status | undefined>;
}

export namespace Status {
  export const STATE_WARNINGS: number = 1;
  export const STATE_ERRORS: number = 2;
  export const RESULT_ERROR: number = -1;
  export const RESULT_OK: number = 0;
  export const RESULT_NO_DATA: number = 1;
  export const RESULT_SEGMENT: number = 2;
}

export interface Master extends Versioned {
  getStatusSync(): Status | undefined;
  getStatusAsync(): Promise<Status | undefined>;
  getDispatcherSync(): Provider | undefined;
  getDispatcherAsync(): Promise<Provider | undefined>;
  getPluginManagerSync(): PluginManager | undefined;
  getPluginManagerAsync(): Promise<PluginManager | undefined>;
  getTimerControlSync(): TimerControl | undefined;
  getTimerControlAsync(): Promise<TimerControl | undefined>;
  getDtcSync(): Dtc | undefined;
  getDtcAsync(): Promise<Dtc | undefined>;
  registerAttachmentSync(provider: Provider | undefined, attachment: Attachment | undefined): Attachment | undefined;
  registerAttachmentAsync(
    provider: Provider | undefined,
    attachment: Attachment | undefined,
  ): Promise<Attachment | undefined>;
  registerTransactionSync(
    attachment: Attachment | undefined,
    transaction: Transaction | undefined,
  ): Transaction | undefined;
  registerTransactionAsync(
    attachment: Attachment | undefined,
    transaction: Transaction | undefined,
  ): Promise<Transaction | undefined>;
  getMetadataBuilderSync(status: Status | undefined, fieldCount: number): MetadataBuilder | undefined;
  getMetadataBuilderAsync(status: Status | undefined, fieldCount: number): Promise<MetadataBuilder | undefined>;
  serverModeSync(mode: number): number;
  serverModeAsync(mode: number): Promise<number>;
  getUtilInterfaceSync(): Util | undefined;
  getUtilInterfaceAsync(): Promise<Util | undefined>;
  getConfigManagerSync(): ConfigManager | undefined;
  getConfigManagerAsync(): Promise<ConfigManager | undefined>;
  getProcessExitingSync(): boolean;
  getProcessExitingAsync(): Promise<boolean>;
}

export interface PluginBase extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
}

export interface PluginSet extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getNameSync(): string | undefined;
  getNameAsync(): Promise<string | undefined>;
  getModuleNameSync(): string | undefined;
  getModuleNameAsync(): Promise<string | undefined>;
  getPluginSync(status: Status | undefined): PluginBase | undefined;
  getPluginAsync(status: Status | undefined): Promise<PluginBase | undefined>;
  nextSync(status: Status | undefined): void;
  nextAsync(status: Status | undefined): Promise<void>;
  setSync(status: Status | undefined, s: string | undefined): void;
  setAsync(status: Status | undefined, s: string | undefined): Promise<void>;
}

export interface ConfigEntry extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getNameSync(): string | undefined;
  getNameAsync(): Promise<string | undefined>;
  getValueSync(): string | undefined;
  getValueAsync(): Promise<string | undefined>;
  getIntValueSync(): number;
  getIntValueAsync(): Promise<number>;
  getBoolValueSync(): boolean;
  getBoolValueAsync(): Promise<boolean>;
  getSubConfigSync(status: Status | undefined): Config | undefined;
  getSubConfigAsync(status: Status | undefined): Promise<Config | undefined>;
}

export interface Config extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  findSync(status: Status | undefined, name: string | undefined): ConfigEntry | undefined;
  findAsync(status: Status | undefined, name: string | undefined): Promise<ConfigEntry | undefined>;
  findValueSync(
    status: Status | undefined,
    name: string | undefined,
    value: string | undefined,
  ): ConfigEntry | undefined;
  findValueAsync(
    status: Status | undefined,
    name: string | undefined,
    value: string | undefined,
  ): Promise<ConfigEntry | undefined>;
  findPosSync(status: Status | undefined, name: string | undefined, pos: number): ConfigEntry | undefined;
  findPosAsync(status: Status | undefined, name: string | undefined, pos: number): Promise<ConfigEntry | undefined>;
}

export interface FirebirdConf extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getKeySync(name: string | undefined): number;
  getKeyAsync(name: string | undefined): Promise<number>;
  asIntegerSync(key: number): number;
  asIntegerAsync(key: number): Promise<number>;
  asStringSync(key: number): string | undefined;
  asStringAsync(key: number): Promise<string | undefined>;
  asBooleanSync(key: number): boolean;
  asBooleanAsync(key: number): Promise<boolean>;
  getVersionSync(status: Status | undefined): number;
  getVersionAsync(status: Status | undefined): Promise<number>;
}

export interface PluginConfig extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getConfigFileNameSync(): string | undefined;
  getConfigFileNameAsync(): Promise<string | undefined>;
  getDefaultConfigSync(status: Status | undefined): Config | undefined;
  getDefaultConfigAsync(status: Status | undefined): Promise<Config | undefined>;
  getFirebirdConfSync(status: Status | undefined): FirebirdConf | undefined;
  getFirebirdConfAsync(status: Status | undefined): Promise<FirebirdConf | undefined>;
  setReleaseDelaySync(status: Status | undefined, microSeconds: number): void;
  setReleaseDelayAsync(status: Status | undefined, microSeconds: number): Promise<void>;
}

export interface PluginFactory extends Versioned {
  createPluginSync(status: Status | undefined, factoryParameter: PluginConfig | undefined): PluginBase | undefined;
  createPluginAsync(
    status: Status | undefined,
    factoryParameter: PluginConfig | undefined,
  ): Promise<PluginBase | undefined>;
}

export interface PluginModule extends Versioned {
  doCleanSync(): void;
  doCleanAsync(): Promise<void>;
  threadDetachSync(): void;
  threadDetachAsync(): Promise<void>;
}

export interface PluginManager extends Versioned {
  registerPluginFactorySync(
    pluginType: number,
    defaultName: string | undefined,
    factory: PluginFactory | undefined,
  ): void;
  registerPluginFactoryAsync(
    pluginType: number,
    defaultName: string | undefined,
    factory: PluginFactory | undefined,
  ): Promise<void>;
  registerModuleSync(cleanup: PluginModule | undefined): void;
  registerModuleAsync(cleanup: PluginModule | undefined): Promise<void>;
  unregisterModuleSync(cleanup: PluginModule | undefined): void;
  unregisterModuleAsync(cleanup: PluginModule | undefined): Promise<void>;
  getPluginsSync(
    status: Status | undefined,
    pluginType: number,
    namesList: string | undefined,
    firebirdConf: FirebirdConf | undefined,
  ): PluginSet | undefined;
  getPluginsAsync(
    status: Status | undefined,
    pluginType: number,
    namesList: string | undefined,
    firebirdConf: FirebirdConf | undefined,
  ): Promise<PluginSet | undefined>;
  getConfigSync(status: Status | undefined, filename: string | undefined): Config | undefined;
  getConfigAsync(status: Status | undefined, filename: string | undefined): Promise<Config | undefined>;
  releasePluginSync(plugin: PluginBase | undefined): void;
  releasePluginAsync(plugin: PluginBase | undefined): Promise<void>;
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
  export const TYPE_REPLICATOR: number = 11;
  export const TYPE_PROFILER: number = 12;
  export const TYPE_COUNT: number = 13;
}

export interface CryptKey extends Versioned {}

export interface ConfigManager extends Versioned {
  getDirectorySync(code: number): string | undefined;
  getDirectoryAsync(code: number): Promise<string | undefined>;
  getFirebirdConfSync(): FirebirdConf | undefined;
  getFirebirdConfAsync(): Promise<FirebirdConf | undefined>;
  getDatabaseConfSync(dbName: string | undefined): FirebirdConf | undefined;
  getDatabaseConfAsync(dbName: string | undefined): Promise<FirebirdConf | undefined>;
  getPluginConfigSync(configuredPlugin: string | undefined): Config | undefined;
  getPluginConfigAsync(configuredPlugin: string | undefined): Promise<Config | undefined>;
  getInstallDirectorySync(): string | undefined;
  getInstallDirectoryAsync(): Promise<string | undefined>;
  getRootDirectorySync(): string | undefined;
  getRootDirectoryAsync(): Promise<string | undefined>;
  getDefaultSecurityDbSync(): string | undefined;
  getDefaultSecurityDbAsync(): Promise<string | undefined>;
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
  export const DIR_TZDATA: number = 17;
  export const DIR_COUNT: number = 18;
}

export interface EventCallback extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  eventCallbackFunctionSync(length: number, events: Uint8Array | Pointer | undefined): void;
  eventCallbackFunctionAsync(length: number, events: Uint8Array | Pointer | undefined): Promise<void>;
}

export interface Blob extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getInfoSync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  getInfoAsync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  getSegmentSync(
    status: Status | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
    segmentLength: Uint32Array | undefined,
  ): number;
  getSegmentAsync(
    status: Status | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
    segmentLength: Uint32Array | undefined,
  ): Promise<number>;
  putSegmentSync(status: Status | undefined, length: number, buffer: Uint8Array | Pointer | undefined): void;
  putSegmentAsync(status: Status | undefined, length: number, buffer: Uint8Array | Pointer | undefined): Promise<void>;
  deprecatedCancelSync(status: Status | undefined): void;
  deprecatedCancelAsync(status: Status | undefined): Promise<void>;
  deprecatedCloseSync(status: Status | undefined): void;
  deprecatedCloseAsync(status: Status | undefined): Promise<void>;
  seekSync(status: Status | undefined, mode: number, offset: number): number;
  seekAsync(status: Status | undefined, mode: number, offset: number): Promise<number>;
  cancelSync(status: Status | undefined): void;
  cancelAsync(status: Status | undefined): Promise<void>;
  closeSync(status: Status | undefined): void;
  closeAsync(status: Status | undefined): Promise<void>;
}

export interface Transaction extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getInfoSync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  getInfoAsync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  prepareSync(status: Status | undefined, msgLength: number, message: Uint8Array | Pointer | undefined): void;
  prepareAsync(status: Status | undefined, msgLength: number, message: Uint8Array | Pointer | undefined): Promise<void>;
  deprecatedCommitSync(status: Status | undefined): void;
  deprecatedCommitAsync(status: Status | undefined): Promise<void>;
  commitRetainingSync(status: Status | undefined): void;
  commitRetainingAsync(status: Status | undefined): Promise<void>;
  deprecatedRollbackSync(status: Status | undefined): void;
  deprecatedRollbackAsync(status: Status | undefined): Promise<void>;
  rollbackRetainingSync(status: Status | undefined): void;
  rollbackRetainingAsync(status: Status | undefined): Promise<void>;
  deprecatedDisconnectSync(status: Status | undefined): void;
  deprecatedDisconnectAsync(status: Status | undefined): Promise<void>;
  joinSync(status: Status | undefined, transaction: Transaction | undefined): Transaction | undefined;
  joinAsync(status: Status | undefined, transaction: Transaction | undefined): Promise<Transaction | undefined>;
  validateSync(status: Status | undefined, attachment: Attachment | undefined): Transaction | undefined;
  validateAsync(status: Status | undefined, attachment: Attachment | undefined): Promise<Transaction | undefined>;
  enterDtcSync(status: Status | undefined): Transaction | undefined;
  enterDtcAsync(status: Status | undefined): Promise<Transaction | undefined>;
  commitSync(status: Status | undefined): void;
  commitAsync(status: Status | undefined): Promise<void>;
  rollbackSync(status: Status | undefined): void;
  rollbackAsync(status: Status | undefined): Promise<void>;
  disconnectSync(status: Status | undefined): void;
  disconnectAsync(status: Status | undefined): Promise<void>;
}

export interface MessageMetadata extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getCountSync(status: Status | undefined): number;
  getCountAsync(status: Status | undefined): Promise<number>;
  getFieldSync(status: Status | undefined, index: number): string | undefined;
  getFieldAsync(status: Status | undefined, index: number): Promise<string | undefined>;
  getRelationSync(status: Status | undefined, index: number): string | undefined;
  getRelationAsync(status: Status | undefined, index: number): Promise<string | undefined>;
  getOwnerSync(status: Status | undefined, index: number): string | undefined;
  getOwnerAsync(status: Status | undefined, index: number): Promise<string | undefined>;
  getAliasSync(status: Status | undefined, index: number): string | undefined;
  getAliasAsync(status: Status | undefined, index: number): Promise<string | undefined>;
  getTypeSync(status: Status | undefined, index: number): number;
  getTypeAsync(status: Status | undefined, index: number): Promise<number>;
  isNullableSync(status: Status | undefined, index: number): boolean;
  isNullableAsync(status: Status | undefined, index: number): Promise<boolean>;
  getSubTypeSync(status: Status | undefined, index: number): number;
  getSubTypeAsync(status: Status | undefined, index: number): Promise<number>;
  getLengthSync(status: Status | undefined, index: number): number;
  getLengthAsync(status: Status | undefined, index: number): Promise<number>;
  getScaleSync(status: Status | undefined, index: number): number;
  getScaleAsync(status: Status | undefined, index: number): Promise<number>;
  getCharSetSync(status: Status | undefined, index: number): number;
  getCharSetAsync(status: Status | undefined, index: number): Promise<number>;
  getOffsetSync(status: Status | undefined, index: number): number;
  getOffsetAsync(status: Status | undefined, index: number): Promise<number>;
  getNullOffsetSync(status: Status | undefined, index: number): number;
  getNullOffsetAsync(status: Status | undefined, index: number): Promise<number>;
  getBuilderSync(status: Status | undefined): MetadataBuilder | undefined;
  getBuilderAsync(status: Status | undefined): Promise<MetadataBuilder | undefined>;
  getMessageLengthSync(status: Status | undefined): number;
  getMessageLengthAsync(status: Status | undefined): Promise<number>;
  getAlignmentSync(status: Status | undefined): number;
  getAlignmentAsync(status: Status | undefined): Promise<number>;
  getAlignedLengthSync(status: Status | undefined): number;
  getAlignedLengthAsync(status: Status | undefined): Promise<number>;
}

export interface MetadataBuilder extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setTypeSync(status: Status | undefined, index: number, type: number): void;
  setTypeAsync(status: Status | undefined, index: number, type: number): Promise<void>;
  setSubTypeSync(status: Status | undefined, index: number, subType: number): void;
  setSubTypeAsync(status: Status | undefined, index: number, subType: number): Promise<void>;
  setLengthSync(status: Status | undefined, index: number, length: number): void;
  setLengthAsync(status: Status | undefined, index: number, length: number): Promise<void>;
  setCharSetSync(status: Status | undefined, index: number, charSet: number): void;
  setCharSetAsync(status: Status | undefined, index: number, charSet: number): Promise<void>;
  setScaleSync(status: Status | undefined, index: number, scale: number): void;
  setScaleAsync(status: Status | undefined, index: number, scale: number): Promise<void>;
  truncateSync(status: Status | undefined, count: number): void;
  truncateAsync(status: Status | undefined, count: number): Promise<void>;
  moveNameToIndexSync(status: Status | undefined, name: string | undefined, index: number): void;
  moveNameToIndexAsync(status: Status | undefined, name: string | undefined, index: number): Promise<void>;
  removeSync(status: Status | undefined, index: number): void;
  removeAsync(status: Status | undefined, index: number): Promise<void>;
  addFieldSync(status: Status | undefined): number;
  addFieldAsync(status: Status | undefined): Promise<number>;
  getMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  setFieldSync(status: Status | undefined, index: number, field: string | undefined): void;
  setFieldAsync(status: Status | undefined, index: number, field: string | undefined): Promise<void>;
  setRelationSync(status: Status | undefined, index: number, relation: string | undefined): void;
  setRelationAsync(status: Status | undefined, index: number, relation: string | undefined): Promise<void>;
  setOwnerSync(status: Status | undefined, index: number, owner: string | undefined): void;
  setOwnerAsync(status: Status | undefined, index: number, owner: string | undefined): Promise<void>;
  setAliasSync(status: Status | undefined, index: number, alias: string | undefined): void;
  setAliasAsync(status: Status | undefined, index: number, alias: string | undefined): Promise<void>;
}

export interface ResultSet extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  fetchNextSync(status: Status | undefined, message: Uint8Array | Pointer | undefined): number;
  fetchNextAsync(status: Status | undefined, message: Uint8Array | Pointer | undefined): Promise<number>;
  fetchPriorSync(status: Status | undefined, message: Uint8Array | Pointer | undefined): number;
  fetchPriorAsync(status: Status | undefined, message: Uint8Array | Pointer | undefined): Promise<number>;
  fetchFirstSync(status: Status | undefined, message: Uint8Array | Pointer | undefined): number;
  fetchFirstAsync(status: Status | undefined, message: Uint8Array | Pointer | undefined): Promise<number>;
  fetchLastSync(status: Status | undefined, message: Uint8Array | Pointer | undefined): number;
  fetchLastAsync(status: Status | undefined, message: Uint8Array | Pointer | undefined): Promise<number>;
  fetchAbsoluteSync(status: Status | undefined, position: number, message: Uint8Array | Pointer | undefined): number;
  fetchAbsoluteAsync(
    status: Status | undefined,
    position: number,
    message: Uint8Array | Pointer | undefined,
  ): Promise<number>;
  fetchRelativeSync(status: Status | undefined, offset: number, message: Uint8Array | Pointer | undefined): number;
  fetchRelativeAsync(
    status: Status | undefined,
    offset: number,
    message: Uint8Array | Pointer | undefined,
  ): Promise<number>;
  isEofSync(status: Status | undefined): boolean;
  isEofAsync(status: Status | undefined): Promise<boolean>;
  isBofSync(status: Status | undefined): boolean;
  isBofAsync(status: Status | undefined): Promise<boolean>;
  getMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  deprecatedCloseSync(status: Status | undefined): void;
  deprecatedCloseAsync(status: Status | undefined): Promise<void>;
  setDelayedOutputFormatSync(status: Status | undefined, format: MessageMetadata | undefined): void;
  setDelayedOutputFormatAsync(status: Status | undefined, format: MessageMetadata | undefined): Promise<void>;
  closeSync(status: Status | undefined): void;
  closeAsync(status: Status | undefined): Promise<void>;
  getInfoSync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  getInfoAsync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
}

export namespace ResultSet {
  export const INF_RECORD_COUNT: number = 10;
}

export interface Statement extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getInfoSync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  getInfoAsync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  getTypeSync(status: Status | undefined): number;
  getTypeAsync(status: Status | undefined): Promise<number>;
  getPlanSync(status: Status | undefined, detailed: boolean): string | undefined;
  getPlanAsync(status: Status | undefined, detailed: boolean): Promise<string | undefined>;
  getAffectedRecordsSync(status: Status | undefined): number;
  getAffectedRecordsAsync(status: Status | undefined): Promise<number>;
  getInputMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getInputMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  getOutputMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getOutputMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  executeSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    outBuffer: Uint8Array | Pointer | undefined,
  ): Transaction | undefined;
  executeAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    outBuffer: Uint8Array | Pointer | undefined,
  ): Promise<Transaction | undefined>;
  openCursorSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    flags: number,
  ): ResultSet | undefined;
  openCursorAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    flags: number,
  ): Promise<ResultSet | undefined>;
  setCursorNameSync(status: Status | undefined, name: string | undefined): void;
  setCursorNameAsync(status: Status | undefined, name: string | undefined): Promise<void>;
  deprecatedFreeSync(status: Status | undefined): void;
  deprecatedFreeAsync(status: Status | undefined): Promise<void>;
  getFlagsSync(status: Status | undefined): number;
  getFlagsAsync(status: Status | undefined): Promise<number>;
  getTimeoutSync(status: Status | undefined): number;
  getTimeoutAsync(status: Status | undefined): Promise<number>;
  setTimeoutSync(status: Status | undefined, timeOut: number): void;
  setTimeoutAsync(status: Status | undefined, timeOut: number): Promise<void>;
  createBatchSync(
    status: Status | undefined,
    inMetadata: MessageMetadata | undefined,
    parLength: number,
    par: Uint8Array | Pointer | undefined,
  ): Batch | undefined;
  createBatchAsync(
    status: Status | undefined,
    inMetadata: MessageMetadata | undefined,
    parLength: number,
    par: Uint8Array | Pointer | undefined,
  ): Promise<Batch | undefined>;
  freeSync(status: Status | undefined): void;
  freeAsync(status: Status | undefined): Promise<void>;
  getMaxInlineBlobSizeSync(status: Status | undefined): number;
  getMaxInlineBlobSizeAsync(status: Status | undefined): Promise<number>;
  setMaxInlineBlobSizeSync(status: Status | undefined, size: number): void;
  setMaxInlineBlobSizeAsync(status: Status | undefined, size: number): Promise<void>;
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
  export const PREPARE_PREFETCH_METADATA: number =
    Statement.PREPARE_PREFETCH_TYPE |
    (Statement.PREPARE_PREFETCH_FLAGS |
      (Statement.PREPARE_PREFETCH_INPUT_PARAMETERS | Statement.PREPARE_PREFETCH_OUTPUT_PARAMETERS));
  export const PREPARE_PREFETCH_ALL: number =
    Statement.PREPARE_PREFETCH_METADATA |
    (Statement.PREPARE_PREFETCH_LEGACY_PLAN |
      (Statement.PREPARE_PREFETCH_DETAILED_PLAN | Statement.PREPARE_PREFETCH_AFFECTED_RECORDS));
  export const FLAG_HAS_CURSOR: number = 1;
  export const FLAG_REPEAT_EXECUTE: number = 2;
  export const CURSOR_TYPE_SCROLLABLE: number = 1;
}

export interface Batch extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  addSync(status: Status | undefined, count: number, inBuffer: Uint8Array | Pointer | undefined): void;
  addAsync(status: Status | undefined, count: number, inBuffer: Uint8Array | Pointer | undefined): Promise<void>;
  addBlobSync(
    status: Status | undefined,
    length: number,
    inBuffer: Uint8Array | Pointer | undefined,
    blobId: Uint8Array | Pointer | undefined,
    parLength: number,
    par: Uint8Array | Pointer | undefined,
  ): void;
  addBlobAsync(
    status: Status | undefined,
    length: number,
    inBuffer: Uint8Array | Pointer | undefined,
    blobId: Uint8Array | Pointer | undefined,
    parLength: number,
    par: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  appendBlobDataSync(status: Status | undefined, length: number, inBuffer: Uint8Array | Pointer | undefined): void;
  appendBlobDataAsync(
    status: Status | undefined,
    length: number,
    inBuffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  addBlobStreamSync(status: Status | undefined, length: number, inBuffer: Uint8Array | Pointer | undefined): void;
  addBlobStreamAsync(
    status: Status | undefined,
    length: number,
    inBuffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  registerBlobSync(
    status: Status | undefined,
    existingBlob: Uint8Array | Pointer | undefined,
    blobId: Uint8Array | Pointer | undefined,
  ): void;
  registerBlobAsync(
    status: Status | undefined,
    existingBlob: Uint8Array | Pointer | undefined,
    blobId: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  executeSync(status: Status | undefined, transaction: Transaction | undefined): BatchCompletionState | undefined;
  executeAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
  ): Promise<BatchCompletionState | undefined>;
  cancelSync(status: Status | undefined): void;
  cancelAsync(status: Status | undefined): Promise<void>;
  getBlobAlignmentSync(status: Status | undefined): number;
  getBlobAlignmentAsync(status: Status | undefined): Promise<number>;
  getMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  setDefaultBpbSync(status: Status | undefined, parLength: number, par: Uint8Array | Pointer | undefined): void;
  setDefaultBpbAsync(
    status: Status | undefined,
    parLength: number,
    par: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  deprecatedCloseSync(status: Status | undefined): void;
  deprecatedCloseAsync(status: Status | undefined): Promise<void>;
  closeSync(status: Status | undefined): void;
  closeAsync(status: Status | undefined): Promise<void>;
  getInfoSync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  getInfoAsync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
}

export namespace Batch {
  export const VERSION1: number = 1;
  export const CURRENT_VERSION: number = Batch.VERSION1;
  export const TAG_MULTIERROR: number = 1;
  export const TAG_RECORD_COUNTS: number = 2;
  export const TAG_BUFFER_BYTES_SIZE: number = 3;
  export const TAG_BLOB_POLICY: number = 4;
  export const TAG_DETAILED_ERRORS: number = 5;
  export const INF_BUFFER_BYTES_SIZE: number = 10;
  export const INF_DATA_BYTES_SIZE: number = 11;
  export const INF_BLOBS_BYTES_SIZE: number = 12;
  export const INF_BLOB_ALIGNMENT: number = 13;
  export const INF_BLOB_HEADER: number = 14;
  export const BLOB_NONE: number = 0;
  export const BLOB_ID_ENGINE: number = 1;
  export const BLOB_ID_USER: number = 2;
  export const BLOB_STREAM: number = 3;
  export const BLOB_SEGHDR_ALIGN: number = 2;
}

export interface BatchCompletionState extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  getSizeSync(status: Status | undefined): number;
  getSizeAsync(status: Status | undefined): Promise<number>;
  getStateSync(status: Status | undefined, pos: number): number;
  getStateAsync(status: Status | undefined, pos: number): Promise<number>;
  findErrorSync(status: Status | undefined, pos: number): number;
  findErrorAsync(status: Status | undefined, pos: number): Promise<number>;
  getStatusSync(status: Status | undefined, to: Status | undefined, pos: number): void;
  getStatusAsync(status: Status | undefined, to: Status | undefined, pos: number): Promise<void>;
}

export namespace BatchCompletionState {
  export const EXECUTE_FAILED: number = -1;
  export const SUCCESS_NO_INFO: number = -2;
  export const NO_MORE_ERRORS: number = 4294967295;
}

export interface Replicator extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  processSync(status: Status | undefined, length: number, data: Uint8Array | Pointer | undefined): void;
  processAsync(status: Status | undefined, length: number, data: Uint8Array | Pointer | undefined): Promise<void>;
  deprecatedCloseSync(status: Status | undefined): void;
  deprecatedCloseAsync(status: Status | undefined): Promise<void>;
  closeSync(status: Status | undefined): void;
  closeAsync(status: Status | undefined): Promise<void>;
}

export interface Request extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  receiveSync(
    status: Status | undefined,
    level: number,
    msgType: number,
    length: number,
    message: Uint8Array | Pointer | undefined,
  ): void;
  receiveAsync(
    status: Status | undefined,
    level: number,
    msgType: number,
    length: number,
    message: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  sendSync(
    status: Status | undefined,
    level: number,
    msgType: number,
    length: number,
    message: Uint8Array | Pointer | undefined,
  ): void;
  sendAsync(
    status: Status | undefined,
    level: number,
    msgType: number,
    length: number,
    message: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  getInfoSync(
    status: Status | undefined,
    level: number,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  getInfoAsync(
    status: Status | undefined,
    level: number,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  startSync(status: Status | undefined, tra: Transaction | undefined, level: number): void;
  startAsync(status: Status | undefined, tra: Transaction | undefined, level: number): Promise<void>;
  startAndSendSync(
    status: Status | undefined,
    tra: Transaction | undefined,
    level: number,
    msgType: number,
    length: number,
    message: Uint8Array | Pointer | undefined,
  ): void;
  startAndSendAsync(
    status: Status | undefined,
    tra: Transaction | undefined,
    level: number,
    msgType: number,
    length: number,
    message: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  unwindSync(status: Status | undefined, level: number): void;
  unwindAsync(status: Status | undefined, level: number): Promise<void>;
  deprecatedFreeSync(status: Status | undefined): void;
  deprecatedFreeAsync(status: Status | undefined): Promise<void>;
  freeSync(status: Status | undefined): void;
  freeAsync(status: Status | undefined): Promise<void>;
}

export interface Events extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  deprecatedCancelSync(status: Status | undefined): void;
  deprecatedCancelAsync(status: Status | undefined): Promise<void>;
  cancelSync(status: Status | undefined): void;
  cancelAsync(status: Status | undefined): Promise<void>;
}

export interface Attachment extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getInfoSync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  getInfoAsync(
    status: Status | undefined,
    itemsLength: number,
    items: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  startTransactionSync(
    status: Status | undefined,
    tpbLength: number,
    tpb: Uint8Array | Pointer | undefined,
  ): Transaction | undefined;
  startTransactionAsync(
    status: Status | undefined,
    tpbLength: number,
    tpb: Uint8Array | Pointer | undefined,
  ): Promise<Transaction | undefined>;
  reconnectTransactionSync(
    status: Status | undefined,
    length: number,
    id: Uint8Array | Pointer | undefined,
  ): Transaction | undefined;
  reconnectTransactionAsync(
    status: Status | undefined,
    length: number,
    id: Uint8Array | Pointer | undefined,
  ): Promise<Transaction | undefined>;
  compileRequestSync(
    status: Status | undefined,
    blrLength: number,
    blr: Uint8Array | Pointer | undefined,
  ): Request | undefined;
  compileRequestAsync(
    status: Status | undefined,
    blrLength: number,
    blr: Uint8Array | Pointer | undefined,
  ): Promise<Request | undefined>;
  transactRequestSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    blrLength: number,
    blr: Uint8Array | Pointer | undefined,
    inMsgLength: number,
    inMsg: Uint8Array | Pointer | undefined,
    outMsgLength: number,
    outMsg: Uint8Array | Pointer | undefined,
  ): void;
  transactRequestAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    blrLength: number,
    blr: Uint8Array | Pointer | undefined,
    inMsgLength: number,
    inMsg: Uint8Array | Pointer | undefined,
    outMsgLength: number,
    outMsg: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  createBlobSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    id: Uint8Array | Pointer | undefined,
    bpbLength: number,
    bpb: Uint8Array | Pointer | undefined,
  ): Blob | undefined;
  createBlobAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    id: Uint8Array | Pointer | undefined,
    bpbLength: number,
    bpb: Uint8Array | Pointer | undefined,
  ): Promise<Blob | undefined>;
  openBlobSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    id: Uint8Array | Pointer | undefined,
    bpbLength: number,
    bpb: Uint8Array | Pointer | undefined,
  ): Blob | undefined;
  openBlobAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    id: Uint8Array | Pointer | undefined,
    bpbLength: number,
    bpb: Uint8Array | Pointer | undefined,
  ): Promise<Blob | undefined>;
  executeDynSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    length: number,
    dyn: Uint8Array | Pointer | undefined,
  ): void;
  executeDynAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    length: number,
    dyn: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  prepareSync(
    status: Status | undefined,
    tra: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    flags: number,
  ): Statement | undefined;
  prepareAsync(
    status: Status | undefined,
    tra: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    flags: number,
  ): Promise<Statement | undefined>;
  executeSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    outBuffer: Uint8Array | Pointer | undefined,
  ): Transaction | undefined;
  executeAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    outBuffer: Uint8Array | Pointer | undefined,
  ): Promise<Transaction | undefined>;
  openCursorSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    cursorName: string | undefined,
    cursorFlags: number,
  ): ResultSet | undefined;
  openCursorAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    inMetadata: MessageMetadata | undefined,
    inBuffer: Uint8Array | Pointer | undefined,
    outMetadata: MessageMetadata | undefined,
    cursorName: string | undefined,
    cursorFlags: number,
  ): Promise<ResultSet | undefined>;
  queEventsSync(
    status: Status | undefined,
    callback: EventCallback | undefined,
    length: number,
    events: Uint8Array | Pointer | undefined,
  ): Events | undefined;
  queEventsAsync(
    status: Status | undefined,
    callback: EventCallback | undefined,
    length: number,
    events: Uint8Array | Pointer | undefined,
  ): Promise<Events | undefined>;
  cancelOperationSync(status: Status | undefined, option: number): void;
  cancelOperationAsync(status: Status | undefined, option: number): Promise<void>;
  pingSync(status: Status | undefined): void;
  pingAsync(status: Status | undefined): Promise<void>;
  deprecatedDetachSync(status: Status | undefined): void;
  deprecatedDetachAsync(status: Status | undefined): Promise<void>;
  deprecatedDropDatabaseSync(status: Status | undefined): void;
  deprecatedDropDatabaseAsync(status: Status | undefined): Promise<void>;
  getIdleTimeoutSync(status: Status | undefined): number;
  getIdleTimeoutAsync(status: Status | undefined): Promise<number>;
  setIdleTimeoutSync(status: Status | undefined, timeOut: number): void;
  setIdleTimeoutAsync(status: Status | undefined, timeOut: number): Promise<void>;
  getStatementTimeoutSync(status: Status | undefined): number;
  getStatementTimeoutAsync(status: Status | undefined): Promise<number>;
  setStatementTimeoutSync(status: Status | undefined, timeOut: number): void;
  setStatementTimeoutAsync(status: Status | undefined, timeOut: number): Promise<void>;
  createBatchSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    inMetadata: MessageMetadata | undefined,
    parLength: number,
    par: Uint8Array | Pointer | undefined,
  ): Batch | undefined;
  createBatchAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    stmtLength: number,
    sqlStmt: string | undefined,
    dialect: number,
    inMetadata: MessageMetadata | undefined,
    parLength: number,
    par: Uint8Array | Pointer | undefined,
  ): Promise<Batch | undefined>;
  createReplicatorSync(status: Status | undefined): Replicator | undefined;
  createReplicatorAsync(status: Status | undefined): Promise<Replicator | undefined>;
  detachSync(status: Status | undefined): void;
  detachAsync(status: Status | undefined): Promise<void>;
  dropDatabaseSync(status: Status | undefined): void;
  dropDatabaseAsync(status: Status | undefined): Promise<void>;
  getMaxBlobCacheSizeSync(status: Status | undefined): number;
  getMaxBlobCacheSizeAsync(status: Status | undefined): Promise<number>;
  setMaxBlobCacheSizeSync(status: Status | undefined, size: number): void;
  setMaxBlobCacheSizeAsync(status: Status | undefined, size: number): Promise<void>;
  getMaxInlineBlobSizeSync(status: Status | undefined): number;
  getMaxInlineBlobSizeAsync(status: Status | undefined): Promise<number>;
  setMaxInlineBlobSizeSync(status: Status | undefined, size: number): void;
  setMaxInlineBlobSizeAsync(status: Status | undefined, size: number): Promise<void>;
}

export interface Service extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  deprecatedDetachSync(status: Status | undefined): void;
  deprecatedDetachAsync(status: Status | undefined): Promise<void>;
  querySync(
    status: Status | undefined,
    sendLength: number,
    sendItems: Uint8Array | Pointer | undefined,
    receiveLength: number,
    receiveItems: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): void;
  queryAsync(
    status: Status | undefined,
    sendLength: number,
    sendItems: Uint8Array | Pointer | undefined,
    receiveLength: number,
    receiveItems: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  startSync(status: Status | undefined, spbLength: number, spb: Uint8Array | Pointer | undefined): void;
  startAsync(status: Status | undefined, spbLength: number, spb: Uint8Array | Pointer | undefined): Promise<void>;
  detachSync(status: Status | undefined): void;
  detachAsync(status: Status | undefined): Promise<void>;
  cancelSync(status: Status | undefined): void;
  cancelAsync(status: Status | undefined): Promise<void>;
}

export interface Provider extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
  attachDatabaseSync(
    status: Status | undefined,
    fileName: string | undefined,
    dpbLength: number,
    dpb: Uint8Array | Pointer | undefined,
  ): Attachment | undefined;
  attachDatabaseAsync(
    status: Status | undefined,
    fileName: string | undefined,
    dpbLength: number,
    dpb: Uint8Array | Pointer | undefined,
  ): Promise<Attachment | undefined>;
  createDatabaseSync(
    status: Status | undefined,
    fileName: string | undefined,
    dpbLength: number,
    dpb: Uint8Array | Pointer | undefined,
  ): Attachment | undefined;
  createDatabaseAsync(
    status: Status | undefined,
    fileName: string | undefined,
    dpbLength: number,
    dpb: Uint8Array | Pointer | undefined,
  ): Promise<Attachment | undefined>;
  attachServiceManagerSync(
    status: Status | undefined,
    service: string | undefined,
    spbLength: number,
    spb: Uint8Array | Pointer | undefined,
  ): Service | undefined;
  attachServiceManagerAsync(
    status: Status | undefined,
    service: string | undefined,
    spbLength: number,
    spb: Uint8Array | Pointer | undefined,
  ): Promise<Service | undefined>;
  shutdownSync(status: Status | undefined, timeout: number, reason: number): void;
  shutdownAsync(status: Status | undefined, timeout: number, reason: number): Promise<void>;
  setDbCryptCallbackSync(status: Status | undefined, cryptCallback: CryptKeyCallback | undefined): void;
  setDbCryptCallbackAsync(status: Status | undefined, cryptCallback: CryptKeyCallback | undefined): Promise<void>;
}

export interface DtcStart extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  addAttachmentSync(status: Status | undefined, att: Attachment | undefined): void;
  addAttachmentAsync(status: Status | undefined, att: Attachment | undefined): Promise<void>;
  addWithTpbSync(
    status: Status | undefined,
    att: Attachment | undefined,
    length: number,
    tpb: Uint8Array | Pointer | undefined,
  ): void;
  addWithTpbAsync(
    status: Status | undefined,
    att: Attachment | undefined,
    length: number,
    tpb: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  startSync(status: Status | undefined): Transaction | undefined;
  startAsync(status: Status | undefined): Promise<Transaction | undefined>;
}

export interface Dtc extends Versioned {
  joinSync(
    status: Status | undefined,
    one: Transaction | undefined,
    two: Transaction | undefined,
  ): Transaction | undefined;
  joinAsync(
    status: Status | undefined,
    one: Transaction | undefined,
    two: Transaction | undefined,
  ): Promise<Transaction | undefined>;
  startBuilderSync(status: Status | undefined): DtcStart | undefined;
  startBuilderAsync(status: Status | undefined): Promise<DtcStart | undefined>;
}

export interface Auth extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
}

export namespace Auth {
  export const AUTH_FAILED: number = -1;
  export const AUTH_SUCCESS: number = 0;
  export const AUTH_MORE_DATA: number = 1;
  export const AUTH_CONTINUE: number = 2;
  export const AUTH_SUCCESS_WITH_DATA: number = 3;
}

export interface Writer extends Versioned {
  resetSync(): void;
  resetAsync(): Promise<void>;
  addSync(status: Status | undefined, name: string | undefined): void;
  addAsync(status: Status | undefined, name: string | undefined): Promise<void>;
  setTypeSync(status: Status | undefined, value: string | undefined): void;
  setTypeAsync(status: Status | undefined, value: string | undefined): Promise<void>;
  setDbSync(status: Status | undefined, value: string | undefined): void;
  setDbAsync(status: Status | undefined, value: string | undefined): Promise<void>;
}

export interface ServerBlock extends Versioned {
  getLoginSync(): string | undefined;
  getLoginAsync(): Promise<string | undefined>;
  getDataSync(length: Uint32Array | undefined): Pointer | undefined;
  getDataAsync(length: Uint32Array | undefined): Promise<Pointer | undefined>;
  putDataSync(status: Status | undefined, length: number, data: Uint8Array | Pointer | undefined): void;
  putDataAsync(status: Status | undefined, length: number, data: Uint8Array | Pointer | undefined): Promise<void>;
  newKeySync(status: Status | undefined): CryptKey | undefined;
  newKeyAsync(status: Status | undefined): Promise<CryptKey | undefined>;
}

export interface ClientBlock extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getLoginSync(): string | undefined;
  getLoginAsync(): Promise<string | undefined>;
  getPasswordSync(): string | undefined;
  getPasswordAsync(): Promise<string | undefined>;
  getDataSync(length: Uint32Array | undefined): Pointer | undefined;
  getDataAsync(length: Uint32Array | undefined): Promise<Pointer | undefined>;
  putDataSync(status: Status | undefined, length: number, data: Uint8Array | Pointer | undefined): void;
  putDataAsync(status: Status | undefined, length: number, data: Uint8Array | Pointer | undefined): Promise<void>;
  newKeySync(status: Status | undefined): CryptKey | undefined;
  newKeyAsync(status: Status | undefined): Promise<CryptKey | undefined>;
  getAuthBlockSync(status: Status | undefined): AuthBlock | undefined;
  getAuthBlockAsync(status: Status | undefined): Promise<AuthBlock | undefined>;
}

export interface Server extends Auth {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
  authenticateSync(
    status: Status | undefined,
    sBlock: ServerBlock | undefined,
    writerInterface: Writer | undefined,
  ): number;
  authenticateAsync(
    status: Status | undefined,
    sBlock: ServerBlock | undefined,
    writerInterface: Writer | undefined,
  ): Promise<number>;
  setDbCryptCallbackSync(status: Status | undefined, cryptCallback: CryptKeyCallback | undefined): void;
  setDbCryptCallbackAsync(status: Status | undefined, cryptCallback: CryptKeyCallback | undefined): Promise<void>;
}

export interface Client extends Auth {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
  authenticateSync(status: Status | undefined, cBlock: ClientBlock | undefined): number;
  authenticateAsync(status: Status | undefined, cBlock: ClientBlock | undefined): Promise<number>;
}

export interface UserField extends Versioned {
  enteredSync(): number;
  enteredAsync(): Promise<number>;
  specifiedSync(): number;
  specifiedAsync(): Promise<number>;
  setEnteredSync(status: Status | undefined, newValue: number): void;
  setEnteredAsync(status: Status | undefined, newValue: number): Promise<void>;
}

export interface CharUserField extends UserField {
  enteredSync(): number;
  enteredAsync(): Promise<number>;
  specifiedSync(): number;
  specifiedAsync(): Promise<number>;
  setEnteredSync(status: Status | undefined, newValue: number): void;
  setEnteredAsync(status: Status | undefined, newValue: number): Promise<void>;
  getSync(): string | undefined;
  getAsync(): Promise<string | undefined>;
  setSync(status: Status | undefined, newValue: string | undefined): void;
  setAsync(status: Status | undefined, newValue: string | undefined): Promise<void>;
}

export interface IntUserField extends UserField {
  enteredSync(): number;
  enteredAsync(): Promise<number>;
  specifiedSync(): number;
  specifiedAsync(): Promise<number>;
  setEnteredSync(status: Status | undefined, newValue: number): void;
  setEnteredAsync(status: Status | undefined, newValue: number): Promise<void>;
  getSync(): number;
  getAsync(): Promise<number>;
  setSync(status: Status | undefined, newValue: number): void;
  setAsync(status: Status | undefined, newValue: number): Promise<void>;
}

export interface User extends Versioned {
  operationSync(): number;
  operationAsync(): Promise<number>;
  userNameSync(): CharUserField | undefined;
  userNameAsync(): Promise<CharUserField | undefined>;
  passwordSync(): CharUserField | undefined;
  passwordAsync(): Promise<CharUserField | undefined>;
  firstNameSync(): CharUserField | undefined;
  firstNameAsync(): Promise<CharUserField | undefined>;
  lastNameSync(): CharUserField | undefined;
  lastNameAsync(): Promise<CharUserField | undefined>;
  middleNameSync(): CharUserField | undefined;
  middleNameAsync(): Promise<CharUserField | undefined>;
  commentSync(): CharUserField | undefined;
  commentAsync(): Promise<CharUserField | undefined>;
  attributesSync(): CharUserField | undefined;
  attributesAsync(): Promise<CharUserField | undefined>;
  activeSync(): IntUserField | undefined;
  activeAsync(): Promise<IntUserField | undefined>;
  adminSync(): IntUserField | undefined;
  adminAsync(): Promise<IntUserField | undefined>;
  clearSync(status: Status | undefined): void;
  clearAsync(status: Status | undefined): Promise<void>;
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
  listSync(status: Status | undefined, user: User | undefined): void;
  listAsync(status: Status | undefined, user: User | undefined): Promise<void>;
}

export interface LogonInfo extends Versioned {
  nameSync(): string | undefined;
  nameAsync(): Promise<string | undefined>;
  roleSync(): string | undefined;
  roleAsync(): Promise<string | undefined>;
  networkProtocolSync(): string | undefined;
  networkProtocolAsync(): Promise<string | undefined>;
  remoteAddressSync(): string | undefined;
  remoteAddressAsync(): Promise<string | undefined>;
  authBlockSync(length: Uint32Array | undefined): Pointer | undefined;
  authBlockAsync(length: Uint32Array | undefined): Promise<Pointer | undefined>;
  attachmentSync(status: Status | undefined): Attachment | undefined;
  attachmentAsync(status: Status | undefined): Promise<Attachment | undefined>;
  transactionSync(status: Status | undefined): Transaction | undefined;
  transactionAsync(status: Status | undefined): Promise<Transaction | undefined>;
}

export interface Management extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
  startSync(status: Status | undefined, logonInfo: LogonInfo | undefined): void;
  startAsync(status: Status | undefined, logonInfo: LogonInfo | undefined): Promise<void>;
  executeSync(status: Status | undefined, user: User | undefined, callback: ListUsers | undefined): number;
  executeAsync(status: Status | undefined, user: User | undefined, callback: ListUsers | undefined): Promise<number>;
  commitSync(status: Status | undefined): void;
  commitAsync(status: Status | undefined): Promise<void>;
  rollbackSync(status: Status | undefined): void;
  rollbackAsync(status: Status | undefined): Promise<void>;
}

export interface AuthBlock extends Versioned {
  getTypeSync(): string | undefined;
  getTypeAsync(): Promise<string | undefined>;
  getNameSync(): string | undefined;
  getNameAsync(): Promise<string | undefined>;
  getPluginSync(): string | undefined;
  getPluginAsync(): Promise<string | undefined>;
  getSecurityDbSync(): string | undefined;
  getSecurityDbAsync(): Promise<string | undefined>;
  getOriginalPluginSync(): string | undefined;
  getOriginalPluginAsync(): Promise<string | undefined>;
  nextSync(status: Status | undefined): boolean;
  nextAsync(status: Status | undefined): Promise<boolean>;
  firstSync(status: Status | undefined): boolean;
  firstAsync(status: Status | undefined): Promise<boolean>;
}

export interface WireCryptPlugin extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
  getKnownTypesSync(status: Status | undefined): string | undefined;
  getKnownTypesAsync(status: Status | undefined): Promise<string | undefined>;
  setKeySync(status: Status | undefined, key: CryptKey | undefined): void;
  setKeyAsync(status: Status | undefined, key: CryptKey | undefined): Promise<void>;
  encryptSync(
    status: Status | undefined,
    length: number,
    from: Uint8Array | Pointer | undefined,
    to: Uint8Array | Pointer | undefined,
  ): void;
  encryptAsync(
    status: Status | undefined,
    length: number,
    from: Uint8Array | Pointer | undefined,
    to: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  decryptSync(
    status: Status | undefined,
    length: number,
    from: Uint8Array | Pointer | undefined,
    to: Uint8Array | Pointer | undefined,
  ): void;
  decryptAsync(
    status: Status | undefined,
    length: number,
    from: Uint8Array | Pointer | undefined,
    to: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  getSpecificDataSync(
    status: Status | undefined,
    keyType: string | undefined,
    length: Uint32Array | undefined,
  ): Pointer | undefined;
  getSpecificDataAsync(
    status: Status | undefined,
    keyType: string | undefined,
    length: Uint32Array | undefined,
  ): Promise<Pointer | undefined>;
  setSpecificDataSync(
    status: Status | undefined,
    keyType: string | undefined,
    length: number,
    data: Uint8Array | Pointer | undefined,
  ): void;
  setSpecificDataAsync(
    status: Status | undefined,
    keyType: string | undefined,
    length: number,
    data: Uint8Array | Pointer | undefined,
  ): Promise<void>;
}

export interface CryptKeyCallback extends Versioned {
  callbackSync(
    dataLength: number,
    data: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): number;
  callbackAsync(
    dataLength: number,
    data: Uint8Array | Pointer | undefined,
    bufferLength: number,
    buffer: Uint8Array | Pointer | undefined,
  ): Promise<number>;
  dummy1Sync(status: Status | undefined): void;
  dummy1Async(status: Status | undefined): Promise<void>;
  dummy2Sync(): void;
  dummy2Async(): Promise<void>;
  getHashLengthSync(status: Status | undefined): number;
  getHashLengthAsync(status: Status | undefined): Promise<number>;
  getHashDataSync(status: Status | undefined, hash: Uint8Array | Pointer | undefined): void;
  getHashDataAsync(status: Status | undefined, hash: Uint8Array | Pointer | undefined): Promise<void>;
}

export interface KeyHolderPlugin extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
  keyCallbackSync(status: Status | undefined, callback: CryptKeyCallback | undefined): number;
  keyCallbackAsync(status: Status | undefined, callback: CryptKeyCallback | undefined): Promise<number>;
  keyHandleSync(status: Status | undefined, keyName: string | undefined): CryptKeyCallback | undefined;
  keyHandleAsync(status: Status | undefined, keyName: string | undefined): Promise<CryptKeyCallback | undefined>;
  useOnlyOwnKeysSync(status: Status | undefined): boolean;
  useOnlyOwnKeysAsync(status: Status | undefined): Promise<boolean>;
  chainHandleSync(status: Status | undefined): CryptKeyCallback | undefined;
  chainHandleAsync(status: Status | undefined): Promise<CryptKeyCallback | undefined>;
}

export interface DbCryptInfo extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  getDatabaseFullPathSync(status: Status | undefined): string | undefined;
  getDatabaseFullPathAsync(status: Status | undefined): Promise<string | undefined>;
}

export interface DbCryptPlugin extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
}

export interface ExternalContext extends Versioned {}

export interface ExternalResultSet extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  fetchSync(status: Status | undefined): boolean;
  fetchAsync(status: Status | undefined): Promise<boolean>;
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
  getPackageSync(status: Status | undefined): string | undefined;
  getPackageAsync(status: Status | undefined): Promise<string | undefined>;
  getNameSync(status: Status | undefined): string | undefined;
  getNameAsync(status: Status | undefined): Promise<string | undefined>;
  getEntryPointSync(status: Status | undefined): string | undefined;
  getEntryPointAsync(status: Status | undefined): Promise<string | undefined>;
  getBodySync(status: Status | undefined): string | undefined;
  getBodyAsync(status: Status | undefined): Promise<string | undefined>;
  getInputMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getInputMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  getOutputMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getOutputMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  getTriggerMetadataSync(status: Status | undefined): MessageMetadata | undefined;
  getTriggerMetadataAsync(status: Status | undefined): Promise<MessageMetadata | undefined>;
  getTriggerTableSync(status: Status | undefined): string | undefined;
  getTriggerTableAsync(status: Status | undefined): Promise<string | undefined>;
  getTriggerTypeSync(status: Status | undefined): number;
  getTriggerTypeAsync(status: Status | undefined): Promise<number>;
}

export interface ExternalEngine extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
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
  startSync(status: Status | undefined, timer: Timer | undefined, microSeconds: number): void;
  startAsync(status: Status | undefined, timer: Timer | undefined, microSeconds: number): Promise<void>;
  stopSync(status: Status | undefined, timer: Timer | undefined): void;
  stopAsync(status: Status | undefined, timer: Timer | undefined): Promise<void>;
}

export interface VersionCallback extends Versioned {
  callbackSync(status: Status | undefined, text: string | undefined): void;
  callbackAsync(status: Status | undefined, text: string | undefined): Promise<void>;
}

export interface Util extends Versioned {
  getFbVersionSync(
    status: Status | undefined,
    att: Attachment | undefined,
    callback: VersionCallback | undefined,
  ): void;
  getFbVersionAsync(
    status: Status | undefined,
    att: Attachment | undefined,
    callback: VersionCallback | undefined,
  ): Promise<void>;
  executeCreateDatabaseSync(
    status: Status | undefined,
    stmtLength: number,
    creatDBstatement: string | undefined,
    dialect: number,
    stmtIsCreateDb: Uint8Array | Pointer | undefined,
  ): Attachment | undefined;
  executeCreateDatabaseAsync(
    status: Status | undefined,
    stmtLength: number,
    creatDBstatement: string | undefined,
    dialect: number,
    stmtIsCreateDb: Uint8Array | Pointer | undefined,
  ): Promise<Attachment | undefined>;
  decodeDateSync(
    date: number,
    year: Uint32Array | undefined,
    month: Uint32Array | undefined,
    day: Uint32Array | undefined,
  ): void;
  decodeDateAsync(
    date: number,
    year: Uint32Array | undefined,
    month: Uint32Array | undefined,
    day: Uint32Array | undefined,
  ): Promise<void>;
  decodeTimeSync(
    time: number,
    hours: Uint32Array | undefined,
    minutes: Uint32Array | undefined,
    seconds: Uint32Array | undefined,
    fractions: Uint32Array | undefined,
  ): void;
  decodeTimeAsync(
    time: number,
    hours: Uint32Array | undefined,
    minutes: Uint32Array | undefined,
    seconds: Uint32Array | undefined,
    fractions: Uint32Array | undefined,
  ): Promise<void>;
  encodeDateSync(year: number, month: number, day: number): number;
  encodeDateAsync(year: number, month: number, day: number): Promise<number>;
  encodeTimeSync(hours: number, minutes: number, seconds: number, fractions: number): number;
  encodeTimeAsync(hours: number, minutes: number, seconds: number, fractions: number): Promise<number>;
  getClientVersionSync(): number;
  getClientVersionAsync(): Promise<number>;
  getXpbBuilderSync(
    status: Status | undefined,
    kind: number,
    buf: Uint8Array | Pointer | undefined,
    len: number,
  ): XpbBuilder | undefined;
  getXpbBuilderAsync(
    status: Status | undefined,
    kind: number,
    buf: Uint8Array | Pointer | undefined,
    len: number,
  ): Promise<XpbBuilder | undefined>;
  setOffsetsSync(
    status: Status | undefined,
    metadata: MessageMetadata | undefined,
    callback: OffsetsCallback | undefined,
  ): number;
  setOffsetsAsync(
    status: Status | undefined,
    metadata: MessageMetadata | undefined,
    callback: OffsetsCallback | undefined,
  ): Promise<number>;
  getDecFloat16Sync(status: Status | undefined): DecFloat16 | undefined;
  getDecFloat16Async(status: Status | undefined): Promise<DecFloat16 | undefined>;
  getDecFloat34Sync(status: Status | undefined): DecFloat34 | undefined;
  getDecFloat34Async(status: Status | undefined): Promise<DecFloat34 | undefined>;
  encodeTimeTzSync(
    status: Status | undefined,
    timeTz: Uint8Array | Pointer | undefined,
    hours: number,
    minutes: number,
    seconds: number,
    fractions: number,
    timeZone: string | undefined,
  ): void;
  encodeTimeTzAsync(
    status: Status | undefined,
    timeTz: Uint8Array | Pointer | undefined,
    hours: number,
    minutes: number,
    seconds: number,
    fractions: number,
    timeZone: string | undefined,
  ): Promise<void>;
  encodeTimeStampTzSync(
    status: Status | undefined,
    timeStampTz: Uint8Array | Pointer | undefined,
    year: number,
    month: number,
    day: number,
    hours: number,
    minutes: number,
    seconds: number,
    fractions: number,
    timeZone: string | undefined,
  ): void;
  encodeTimeStampTzAsync(
    status: Status | undefined,
    timeStampTz: Uint8Array | Pointer | undefined,
    year: number,
    month: number,
    day: number,
    hours: number,
    minutes: number,
    seconds: number,
    fractions: number,
    timeZone: string | undefined,
  ): Promise<void>;
  getInt128Sync(status: Status | undefined): Int128 | undefined;
  getInt128Async(status: Status | undefined): Promise<Int128 | undefined>;
}

export interface OffsetsCallback extends Versioned {
  setOffsetSync(status: Status | undefined, index: number, offset: number, nullOffset: number): void;
  setOffsetAsync(status: Status | undefined, index: number, offset: number, nullOffset: number): Promise<void>;
}

export interface XpbBuilder extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  clearSync(status: Status | undefined): void;
  clearAsync(status: Status | undefined): Promise<void>;
  removeCurrentSync(status: Status | undefined): void;
  removeCurrentAsync(status: Status | undefined): Promise<void>;
  insertIntSync(status: Status | undefined, tag: number, value: number): void;
  insertIntAsync(status: Status | undefined, tag: number, value: number): Promise<void>;
  insertBigIntSync(status: Status | undefined, tag: number, value: number): void;
  insertBigIntAsync(status: Status | undefined, tag: number, value: number): Promise<void>;
  insertBytesSync(
    status: Status | undefined,
    tag: number,
    bytes: Uint8Array | Pointer | undefined,
    length: number,
  ): void;
  insertBytesAsync(
    status: Status | undefined,
    tag: number,
    bytes: Uint8Array | Pointer | undefined,
    length: number,
  ): Promise<void>;
  insertStringSync(status: Status | undefined, tag: number, str: string | undefined): void;
  insertStringAsync(status: Status | undefined, tag: number, str: string | undefined): Promise<void>;
  insertTagSync(status: Status | undefined, tag: number): void;
  insertTagAsync(status: Status | undefined, tag: number): Promise<void>;
  isEofSync(status: Status | undefined): boolean;
  isEofAsync(status: Status | undefined): Promise<boolean>;
  moveNextSync(status: Status | undefined): void;
  moveNextAsync(status: Status | undefined): Promise<void>;
  rewindSync(status: Status | undefined): void;
  rewindAsync(status: Status | undefined): Promise<void>;
  findFirstSync(status: Status | undefined, tag: number): boolean;
  findFirstAsync(status: Status | undefined, tag: number): Promise<boolean>;
  findNextSync(status: Status | undefined): boolean;
  findNextAsync(status: Status | undefined): Promise<boolean>;
  getTagSync(status: Status | undefined): number;
  getTagAsync(status: Status | undefined): Promise<number>;
  getLengthSync(status: Status | undefined): number;
  getLengthAsync(status: Status | undefined): Promise<number>;
  getIntSync(status: Status | undefined): number;
  getIntAsync(status: Status | undefined): Promise<number>;
  getBigIntSync(status: Status | undefined): number;
  getBigIntAsync(status: Status | undefined): Promise<number>;
  getStringSync(status: Status | undefined): string | undefined;
  getStringAsync(status: Status | undefined): Promise<string | undefined>;
  getBytesSync(status: Status | undefined): Pointer | undefined;
  getBytesAsync(status: Status | undefined): Promise<Pointer | undefined>;
  getBufferLengthSync(status: Status | undefined): number;
  getBufferLengthAsync(status: Status | undefined): Promise<number>;
  getBufferSync(status: Status | undefined): Pointer | undefined;
  getBufferAsync(status: Status | undefined): Promise<Pointer | undefined>;
}

export namespace XpbBuilder {
  export const DPB: number = 1;
  export const SPB_ATTACH: number = 2;
  export const SPB_START: number = 3;
  export const TPB: number = 4;
  export const BATCH: number = 5;
  export const BPB: number = 6;
  export const SPB_SEND: number = 7;
  export const SPB_RECEIVE: number = 8;
  export const SPB_RESPONSE: number = 9;
  export const INFO_SEND: number = 10;
  export const INFO_RESPONSE: number = 11;
}

export interface TraceConnection extends Versioned {
  getKindSync(): number;
  getKindAsync(): Promise<number>;
  getProcessIDSync(): number;
  getProcessIDAsync(): Promise<number>;
  getUserNameSync(): string | undefined;
  getUserNameAsync(): Promise<string | undefined>;
  getRoleNameSync(): string | undefined;
  getRoleNameAsync(): Promise<string | undefined>;
  getCharSetSync(): string | undefined;
  getCharSetAsync(): Promise<string | undefined>;
  getRemoteProtocolSync(): string | undefined;
  getRemoteProtocolAsync(): Promise<string | undefined>;
  getRemoteAddressSync(): string | undefined;
  getRemoteAddressAsync(): Promise<string | undefined>;
  getRemoteProcessIDSync(): number;
  getRemoteProcessIDAsync(): Promise<number>;
  getRemoteProcessNameSync(): string | undefined;
  getRemoteProcessNameAsync(): Promise<string | undefined>;
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
  getUserNameSync(): string | undefined;
  getUserNameAsync(): Promise<string | undefined>;
  getRoleNameSync(): string | undefined;
  getRoleNameAsync(): Promise<string | undefined>;
  getCharSetSync(): string | undefined;
  getCharSetAsync(): Promise<string | undefined>;
  getRemoteProtocolSync(): string | undefined;
  getRemoteProtocolAsync(): Promise<string | undefined>;
  getRemoteAddressSync(): string | undefined;
  getRemoteAddressAsync(): Promise<string | undefined>;
  getRemoteProcessIDSync(): number;
  getRemoteProcessIDAsync(): Promise<number>;
  getRemoteProcessNameSync(): string | undefined;
  getRemoteProcessNameAsync(): Promise<string | undefined>;
  getConnectionIDSync(): number;
  getConnectionIDAsync(): Promise<number>;
  getDatabaseNameSync(): string | undefined;
  getDatabaseNameAsync(): Promise<string | undefined>;
}

export interface TraceTransaction extends Versioned {}

export namespace TraceTransaction {
  export const ISOLATION_CONSISTENCY: number = 1;
  export const ISOLATION_CONCURRENCY: number = 2;
  export const ISOLATION_READ_COMMITTED_RECVER: number = 3;
  export const ISOLATION_READ_COMMITTED_NORECVER: number = 4;
  export const ISOLATION_READ_COMMITTED_READ_CONSISTENCY: number = 5;
}

export interface TraceParams extends Versioned {}

export interface TraceStatement extends Versioned {}

export interface TraceSQLStatement extends TraceStatement {}

export interface TraceBLRStatement extends TraceStatement {}

export interface TraceDYNRequest extends Versioned {}

export interface TraceContextVariable extends Versioned {}

export interface TraceProcedure extends Versioned {}

export interface TraceFunction extends Versioned {}

export interface TraceTrigger extends Versioned {}

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
  getUserNameSync(): string | undefined;
  getUserNameAsync(): Promise<string | undefined>;
  getRoleNameSync(): string | undefined;
  getRoleNameAsync(): Promise<string | undefined>;
  getCharSetSync(): string | undefined;
  getCharSetAsync(): Promise<string | undefined>;
  getRemoteProtocolSync(): string | undefined;
  getRemoteProtocolAsync(): Promise<string | undefined>;
  getRemoteAddressSync(): string | undefined;
  getRemoteAddressAsync(): Promise<string | undefined>;
  getRemoteProcessIDSync(): number;
  getRemoteProcessIDAsync(): Promise<number>;
  getRemoteProcessNameSync(): string | undefined;
  getRemoteProcessNameAsync(): Promise<string | undefined>;
}

export interface TraceStatusVector extends Versioned {}

export interface TraceSweepInfo extends Versioned {}

export interface TraceLogWriter extends ReferenceCounted {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
}

export interface TraceInitInfo extends Versioned {}

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
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
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
  export const TRACE_EVENT_PROC_COMPILE: number = 20;
  export const TRACE_EVENT_FUNC_COMPILE: number = 21;
  export const TRACE_EVENT_TRIGGER_COMPILE: number = 22;
  export const TRACE_EVENT_MAX: number = 23;
}

export interface UdrFunctionFactory extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  setupSync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
    inBuilder: MetadataBuilder | undefined,
    outBuilder: MetadataBuilder | undefined,
  ): void;
  setupAsync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
    inBuilder: MetadataBuilder | undefined,
    outBuilder: MetadataBuilder | undefined,
  ): Promise<void>;
  newItemSync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
  ): ExternalFunction | undefined;
  newItemAsync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
  ): Promise<ExternalFunction | undefined>;
}

export interface UdrProcedureFactory extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  setupSync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
    inBuilder: MetadataBuilder | undefined,
    outBuilder: MetadataBuilder | undefined,
  ): void;
  setupAsync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
    inBuilder: MetadataBuilder | undefined,
    outBuilder: MetadataBuilder | undefined,
  ): Promise<void>;
  newItemSync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
  ): ExternalProcedure | undefined;
  newItemAsync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
  ): Promise<ExternalProcedure | undefined>;
}

export interface UdrTriggerFactory extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  setupSync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
    fieldsBuilder: MetadataBuilder | undefined,
  ): void;
  setupAsync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
    fieldsBuilder: MetadataBuilder | undefined,
  ): Promise<void>;
  newItemSync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
  ): ExternalTrigger | undefined;
  newItemAsync(
    status: Status | undefined,
    context: ExternalContext | undefined,
    metadata: RoutineMetadata | undefined,
  ): Promise<ExternalTrigger | undefined>;
}

export interface UdrPlugin extends Versioned {
  getMasterSync(): Master | undefined;
  getMasterAsync(): Promise<Master | undefined>;
  registerFunctionSync(
    status: Status | undefined,
    name: string | undefined,
    factory: UdrFunctionFactory | undefined,
  ): void;
  registerFunctionAsync(
    status: Status | undefined,
    name: string | undefined,
    factory: UdrFunctionFactory | undefined,
  ): Promise<void>;
  registerProcedureSync(
    status: Status | undefined,
    name: string | undefined,
    factory: UdrProcedureFactory | undefined,
  ): void;
  registerProcedureAsync(
    status: Status | undefined,
    name: string | undefined,
    factory: UdrProcedureFactory | undefined,
  ): Promise<void>;
  registerTriggerSync(
    status: Status | undefined,
    name: string | undefined,
    factory: UdrTriggerFactory | undefined,
  ): void;
  registerTriggerAsync(
    status: Status | undefined,
    name: string | undefined,
    factory: UdrTriggerFactory | undefined,
  ): Promise<void>;
}

export interface DecFloat16 extends Versioned {
  toBcdSync(
    from: Uint8Array | Pointer | undefined,
    sign: Int32Array | undefined,
    bcd: Uint8Array | Pointer | undefined,
    exp: Int32Array | undefined,
  ): void;
  toBcdAsync(
    from: Uint8Array | Pointer | undefined,
    sign: Int32Array | undefined,
    bcd: Uint8Array | Pointer | undefined,
    exp: Int32Array | undefined,
  ): Promise<void>;
  fromBcdSync(
    sign: number,
    bcd: Uint8Array | Pointer | undefined,
    exp: number,
    to: Uint8Array | Pointer | undefined,
  ): void;
  fromBcdAsync(
    sign: number,
    bcd: Uint8Array | Pointer | undefined,
    exp: number,
    to: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  fromStringSync(status: Status | undefined, from: string | undefined, to: Uint8Array | Pointer | undefined): void;
  fromStringAsync(
    status: Status | undefined,
    from: string | undefined,
    to: Uint8Array | Pointer | undefined,
  ): Promise<void>;
}

export namespace DecFloat16 {
  export const BCD_SIZE: number = 16;
  export const STRING_SIZE: number = 24;
}

export interface DecFloat34 extends Versioned {
  toBcdSync(
    from: Uint8Array | Pointer | undefined,
    sign: Int32Array | undefined,
    bcd: Uint8Array | Pointer | undefined,
    exp: Int32Array | undefined,
  ): void;
  toBcdAsync(
    from: Uint8Array | Pointer | undefined,
    sign: Int32Array | undefined,
    bcd: Uint8Array | Pointer | undefined,
    exp: Int32Array | undefined,
  ): Promise<void>;
  fromBcdSync(
    sign: number,
    bcd: Uint8Array | Pointer | undefined,
    exp: number,
    to: Uint8Array | Pointer | undefined,
  ): void;
  fromBcdAsync(
    sign: number,
    bcd: Uint8Array | Pointer | undefined,
    exp: number,
    to: Uint8Array | Pointer | undefined,
  ): Promise<void>;
  fromStringSync(status: Status | undefined, from: string | undefined, to: Uint8Array | Pointer | undefined): void;
  fromStringAsync(
    status: Status | undefined,
    from: string | undefined,
    to: Uint8Array | Pointer | undefined,
  ): Promise<void>;
}

export namespace DecFloat34 {
  export const BCD_SIZE: number = 34;
  export const STRING_SIZE: number = 43;
}

export interface Int128 extends Versioned {
  fromStringSync(
    status: Status | undefined,
    scale: number,
    from: string | undefined,
    to: Uint8Array | Pointer | undefined,
  ): void;
  fromStringAsync(
    status: Status | undefined,
    scale: number,
    from: string | undefined,
    to: Uint8Array | Pointer | undefined,
  ): Promise<void>;
}

export namespace Int128 {
  export const STRING_SIZE: number = 46;
}

export interface ReplicatedField extends Versioned {
  getNameSync(): string | undefined;
  getNameAsync(): Promise<string | undefined>;
  getTypeSync(): number;
  getTypeAsync(): Promise<number>;
  getSubTypeSync(): number;
  getSubTypeAsync(): Promise<number>;
  getScaleSync(): number;
  getScaleAsync(): Promise<number>;
  getLengthSync(): number;
  getLengthAsync(): Promise<number>;
  getCharSetSync(): number;
  getCharSetAsync(): Promise<number>;
}

export interface ReplicatedRecord extends Versioned {
  getCountSync(): number;
  getCountAsync(): Promise<number>;
  getFieldSync(index: number): ReplicatedField | undefined;
  getFieldAsync(index: number): Promise<ReplicatedField | undefined>;
  getRawLengthSync(): number;
  getRawLengthAsync(): Promise<number>;
  getRawDataSync(): Pointer | undefined;
  getRawDataAsync(): Promise<Pointer | undefined>;
}

export interface ReplicatedTransaction extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
  prepareSync(status: Status | undefined): void;
  prepareAsync(status: Status | undefined): Promise<void>;
  commitSync(status: Status | undefined): void;
  commitAsync(status: Status | undefined): Promise<void>;
  rollbackSync(status: Status | undefined): void;
  rollbackAsync(status: Status | undefined): Promise<void>;
  startSavepointSync(status: Status | undefined): void;
  startSavepointAsync(status: Status | undefined): Promise<void>;
  releaseSavepointSync(status: Status | undefined): void;
  releaseSavepointAsync(status: Status | undefined): Promise<void>;
  rollbackSavepointSync(status: Status | undefined): void;
  rollbackSavepointAsync(status: Status | undefined): Promise<void>;
  insertRecordSync(status: Status | undefined, name: string | undefined, record: ReplicatedRecord | undefined): void;
  insertRecordAsync(
    status: Status | undefined,
    name: string | undefined,
    record: ReplicatedRecord | undefined,
  ): Promise<void>;
  updateRecordSync(
    status: Status | undefined,
    name: string | undefined,
    orgRecord: ReplicatedRecord | undefined,
    newRecord: ReplicatedRecord | undefined,
  ): void;
  updateRecordAsync(
    status: Status | undefined,
    name: string | undefined,
    orgRecord: ReplicatedRecord | undefined,
    newRecord: ReplicatedRecord | undefined,
  ): Promise<void>;
  deleteRecordSync(status: Status | undefined, name: string | undefined, record: ReplicatedRecord | undefined): void;
  deleteRecordAsync(
    status: Status | undefined,
    name: string | undefined,
    record: ReplicatedRecord | undefined,
  ): Promise<void>;
  executeSqlSync(status: Status | undefined, sql: string | undefined): void;
  executeSqlAsync(status: Status | undefined, sql: string | undefined): Promise<void>;
  executeSqlIntlSync(status: Status | undefined, charset: number, sql: string | undefined): void;
  executeSqlIntlAsync(status: Status | undefined, charset: number, sql: string | undefined): Promise<void>;
}

export interface ReplicatedSession extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
  initSync(status: Status | undefined, attachment: Attachment | undefined): boolean;
  initAsync(status: Status | undefined, attachment: Attachment | undefined): Promise<boolean>;
  startTransactionSync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    number: number,
  ): ReplicatedTransaction | undefined;
  startTransactionAsync(
    status: Status | undefined,
    transaction: Transaction | undefined,
    number: number,
  ): Promise<ReplicatedTransaction | undefined>;
  cleanupTransactionSync(status: Status | undefined, number: number): void;
  cleanupTransactionAsync(status: Status | undefined, number: number): Promise<void>;
  setSequenceSync(status: Status | undefined, name: string | undefined, value: number): void;
  setSequenceAsync(status: Status | undefined, name: string | undefined, value: number): Promise<void>;
}

export interface ProfilerPlugin extends PluginBase {
  addRefSync(): void;
  addRefAsync(): Promise<void>;
  releaseSync(): number;
  releaseAsync(): Promise<number>;
  setOwnerSync(r: ReferenceCounted | undefined): void;
  setOwnerAsync(r: ReferenceCounted | undefined): Promise<void>;
  getOwnerSync(): ReferenceCounted | undefined;
  getOwnerAsync(): Promise<ReferenceCounted | undefined>;
}

export interface ProfilerSession extends Disposable {
  disposeSync(): void;
  disposeAsync(): Promise<void>;
}

export namespace ProfilerSession {
  export const FLAG_BEFORE_EVENTS: number = 1;
  export const FLAG_AFTER_EVENTS: number = 2;
}

export interface ProfilerStats extends Versioned {
  getElapsedTicksSync(): number;
  getElapsedTicksAsync(): Promise<number>;
}
