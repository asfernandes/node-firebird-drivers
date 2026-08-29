import { parseStatusVector } from './status';

export interface WireProtocolOptions {
  readonly host: string;
  readonly port?: number;
  readonly username: string;
  readonly password: string;
  readonly timeoutMs?: number;
  readonly statementTimeoutMs?: number;
}

export interface AttachmentHandle {
  readonly handle: number;
}

export interface TransactionHandle {
  readonly handle: number;
}

export interface StatementHandle {
  readonly handle: number;
}

export interface BlobHandle {
  readonly handle: number;
  readonly id: Buffer;
  readonly transaction: TransactionHandle;
  readonly bpb: Buffer;
}

export interface BlobSegmentResponse {
  readonly state: number;
  readonly data: Buffer;
}

export interface StatementColumn {
  readonly alias: string;
  readonly field: string;
  readonly relation: string;
  readonly type: number;
  readonly originalType: number;
  readonly subType: number;
  readonly charSet: number;
  readonly scale: number;
  readonly length: number;
  readonly nullable: boolean;
  readonly offset: number;
  readonly nullOffset: number;
}

export interface CursorHandle {
  readonly statement: StatementHandle;
  readonly transaction: TransactionHandle;
  readonly columns: readonly StatementColumn[];
  readonly fetchBlr: Buffer;
  readonly fetchMessageLength: number;
}

export interface EventHandle {
  readonly id: number;
  readonly names: readonly string[];
}

export type EventCallback = (counters: [string, number][]) => Promise<void> | void;

export interface AcceptMessage {
  readonly protocolVersion: number;
  readonly architecture: number;
  readonly packetType: number;
  readonly authenticated: boolean;
  readonly pluginName: string;
  readonly data: Buffer;
  readonly keys: Buffer;
}

export interface ResponseMessage {
  readonly handle: number;
  readonly objectId: bigint;
  readonly quad: Buffer;
  readonly data: Buffer;
  readonly status: ReturnType<typeof parseStatusVector>;
}

export interface DpbClumplet {
  readonly tag: number;
  readonly value: Buffer;
}

export interface StatementMetadata {
  readonly type: number;
  readonly flags: number;
  readonly inputColumns: readonly StatementColumn[];
  readonly outputColumns: readonly StatementColumn[];
  readonly inputBlr: Buffer;
  readonly inputMessageLength: number;
  readonly outputBlr: Buffer;
  readonly outputMessageLength: number;
}

export interface MutableStatementColumn {
  alias: string;
  field: string;
  relation: string;
  type: number;
  originalType: number;
  subType: number;
  charSet: number;
  scale: number;
  length: number;
  nullable: boolean;
  offset: number;
  nullOffset: number;
}

export interface EventMessage {
  readonly database: number;
  readonly items: Buffer;
  readonly requestId: number;
}

export interface EventSubscription {
  readonly id: number;
  readonly names: readonly string[];
  readonly callback: EventCallback;
  eventBuffer: Buffer;
}

export interface InlineBlobResponse {
  readonly transactionHandle: number;
  readonly blobId: Buffer;
  readonly info: Buffer;
  readonly data: Buffer;
}
