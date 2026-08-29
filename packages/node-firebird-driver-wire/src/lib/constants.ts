export namespace wireProtocol {
  export const connectVersion3 = 3;
  export const archGeneric = 1;
  export const defaultPort = 3050;

  export const protocolFlag = 0x8000;
  export const version11 = protocolFlag | 11;
  export const version12 = protocolFlag | 12;
  export const version13 = protocolFlag | 13;
  export const version14 = protocolFlag | 14;
  export const version15 = protocolFlag | 15;
  export const version16 = protocolFlag | 16;
  export const version17 = protocolFlag | 17;
  export const version18 = protocolFlag | 18;
  export const version19 = protocolFlag | 19;
  export const version20 = protocolFlag | 20;
  export const supportedProtocols = [
    version20,
    version19,
    version18,
    version17,
    version16,
    version15,
    version14,
    version13,
  ];
}

export namespace wireOp {
  export const connect = 1;
  export const accept = 3;
  export const reject = 4;
  export const disconnect = 6;
  export const response = 9;
  export const attach = 19;
  export const create = 20;
  export const detach = 21;
  export const transaction = 29;
  export const commit = 30;
  export const rollback = 31;
  export const createBlob = 34;
  export const openBlob = 35;
  export const getSegment = 36;
  export const putSegment = 37;
  export const cancelBlob = 38;
  export const closeBlob = 39;
  export const infoBlob = 43;
  export const queEvents = 48;
  export const cancelEvents = 49;
  export const commitRetaining = 50;
  export const prepare2 = 51;
  export const event = 52;
  export const connectRequest = 53;
  export const auxConnect = 54;
  export const openBlob2 = 56;
  export const createBlob2 = 57;
  export const seekBlob = 61;
  export const allocateStatement = 62;
  export const execute = 63;
  export const fetch = 65;
  export const fetchResponse = 66;
  export const freeStatement = 67;
  export const prepareStatement = 68;
  export const setCursor = 69;
  export const infoSql = 70;
  export const dummy = 71;
  export const execute2 = 76;
  export const sqlResponse = 78;
  export const dropDatabase = 81;
  export const rollbackRetaining = 86;
  export const cancel = 91;
  export const contAuth = 92;
  export const ping = 93;
  export const acceptData = 94;
  export const crypt = 96;
  export const condAccept = 98;
  export const inlineBlob = 114;
}

export namespace wirePacketType {
  export const batchSend = 3;
  export const lazySend = 5;
  export const compressFlag = 0x100;
}

export namespace wireProtocolFeature {
  export const invalidObjectHandle = 0xffff;
  export const inlineBlobMaxSize = 65535;
  export const prepareFlagNoPlan = 0x1;
  export const prepareFlagNoBatch = 0x2;
  export const prepareFlagUseDatails = 0x4;
  export const prepareFlagDescribe = 0x8;
}

export namespace connectParameter {
  export const user = 1;
  export const host = 4;
  export const userVerification = 6;
  export const specificData = 7;
  export const pluginName = 8;
  export const login = 9;
  export const pluginList = 10;
  export const clientCrypt = 11;
}

export namespace wireCrypt {
  export const disabled = 0;
  export const enabled = 1;
}

export namespace protocolRequest {
  export const async = 1;
}

export namespace statusArgument {
  export const end = 0;
  export const gds = 1;
  export const string = 2;
  export const cstring = 3;
  export const number = 4;
  export const interpreted = 5;
  export const warning = 18;
}

export namespace dsql {
  export const drop = 2;
  export const close = 1;
}

export namespace blr {
  export const text = 14;
  export const text2 = 15;
  export const short = 7;
  export const long = 8;
  export const double = 27;
  export const timestamp = 35;
  export const varying = 37;
  export const varying2 = 38;
  export const sqlDate = 12;
  export const sqlTime = 13;
  export const sqlTimeTz = 28;
  export const timestampTz = 29;
  export const exTimeTz = 30;
  export const exTimestampTz = 31;
  export const int64 = 16;
  export const blob2 = 17;
  export const bool = 23;
  export const null_ = 45;
  export const version5 = 5;
  export const eoc = 76;
  export const end = 255;
  export const begin = 2;
  export const message = 4;
}

export namespace statementFlag {
  export const hasCursor = 0x1;
}

export namespace authPlugin {
  export const list = ['Srp256', 'Srp', 'Legacy_Auth'] as const;
  export type Name = (typeof list)[number];
}
