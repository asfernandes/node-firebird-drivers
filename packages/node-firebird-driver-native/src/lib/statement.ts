import { AttachmentImpl } from './attachment';
import { ResultSetImpl } from './resultset';
import { TransactionImpl } from './transaction';

import { ExecuteOptions, ExecuteQueryOptions, PrepareOptions, StatementType } from 'node-firebird-driver';

import { AbstractStatement, commonInfo, getPortableInteger, statementInfo } from 'node-firebird-driver/dist/lib/impl';

import { createDataReader, createDataWriter, createDescriptors, DataReader, DataWriter, fixMetadata } from './fb-util';

import * as fb from 'node-firebird-native-api';

import { TextDecoder } from 'util';

/** Statement implementation. */
export class StatementImpl extends AbstractStatement {
  // Override declarations.
  override attachment: AttachmentImpl;
  override hasResultSet: boolean;

  statementHandle?: fb.Statement;
  inMetadata?: fb.MessageMetadata;
  outMetadata?: fb.MessageMetadata;
  inBuffer: Uint8Array;
  outBuffer: Uint8Array;
  dataWriter: DataWriter;
  dataReader: DataReader;
  typePromise?: Promise<StatementType>;

  static async prepare(
    attachment: AttachmentImpl,
    transaction: TransactionImpl,
    sqlStmt: string,
    _options?: PrepareOptions,
  ): Promise<StatementImpl> {
    const statement = new StatementImpl(attachment);

    return await attachment.client.statusAction(async (status) => {
      //// FIXME: options/flags, dialect
      statement.statementHandle = await attachment!.attachmentHandle!.prepareAsync(
        status,
        transaction?.transactionHandle,
        0,
        sqlStmt,
        3,
        fb.Statement.PREPARE_PREFETCH_ALL,
      );

      statement.hasResultSet = (statement.statementHandle!.getFlagsSync(status) & fb.Statement.FLAG_HAS_CURSOR) != 0;

      statement.inMetadata = fixMetadata(status, await statement.statementHandle!.getInputMetadataAsync(status));
      statement.outMetadata = fixMetadata(status, await statement.statementHandle!.getOutputMetadataAsync(status));

      if (statement.inMetadata) {
        statement.inBuffer = new Uint8Array(statement.inMetadata.getMessageLengthSync(status));
        statement.dataWriter = createDataWriter(createDescriptors(status, statement.inMetadata), attachment.encoding);
      }

      if (statement.outMetadata) {
        statement.outBuffer = new Uint8Array(statement.outMetadata.getMessageLengthSync(status));
        statement.dataReader = createDataReader(createDescriptors(status, statement.outMetadata), attachment.encoding);
      }

      return statement;
    });
  }

  /** Disposes this statement's resources. */
  protected async internalDispose(): Promise<void> {
    if (this.outMetadata) {
      this.outMetadata.releaseSync();
      this.outMetadata = undefined;
    }

    if (this.inMetadata) {
      this.inMetadata.releaseSync();
      this.inMetadata = undefined;
    }

    await this.attachment.client.statusAction((status) => this.statementHandle!.freeAsync(status));

    this.statementHandle = undefined;
  }

  /** Executes a prepared statement that uses the SET TRANSACTION command. Returns the new transaction. */
  protected async internalExecuteTransaction(_transaction: TransactionImpl): Promise<TransactionImpl> {
    throw new Error('Uninplemented method: executeTransaction.');
  }

  /** Executes a prepared statement that has no result set. */
  protected async internalExecute(
    transaction: TransactionImpl,
    parameters?: any[],
    _options?: ExecuteOptions,
  ): Promise<any[]> {
    return await this.attachment.client.statusAction(async (status) => {
      await this.dataWriter(this.attachment, transaction, this.inBuffer, parameters);

      const newTransaction = await this.statementHandle!.executeAsync(
        status,
        transaction?.transactionHandle,
        this.inMetadata,
        this.inBuffer,
        this.outMetadata,
        this.outBuffer,
      );

      if (newTransaction && transaction?.transactionHandle != newTransaction) {
        //// FIXME: newTransaction.releaseSync();
      }

      return this.outMetadata ? await this.dataReader(this.attachment, transaction, this.outBuffer) : [];
    });
  }

  /** Executes a prepared statement that has result set. */
  protected async internalExecuteQuery(
    transaction: TransactionImpl,
    parameters?: any[],
    options?: ExecuteQueryOptions,
  ): Promise<ResultSetImpl> {
    return await ResultSetImpl.open(this, transaction as TransactionImpl, parameters, options);
  }

  async setCursorName(cursorName: string): Promise<void> {
    return await this.attachment.client.statusAction(
      async (status) => await this.statementHandle!.setCursorNameAsync(status, cursorName),
    );
  }

  async getExecPathText(): Promise<string | undefined> {
    return await this.attachment.client.statusAction(async (status) => {
      const infoReq = new Uint8Array([statementInfo.sqlExecPathBlrText]);
      const infoRet = new Uint8Array(65535);
      await this.statementHandle!.getInfoAsync(status, infoReq.byteLength, infoReq, infoRet.byteLength, infoRet);

      if (infoRet[0] == commonInfo.end) {
        return undefined;
      } else {
        if (infoRet[0] != statementInfo.sqlExecPathBlrText) {
          throw new Error('Error retrieving statement execution path.');
        }

        const size = getPortableInteger(infoRet.subarray(1), 2);
        return new TextDecoder().decode(infoRet.subarray(3, 3 + size));
      }
    });
  }

  get columnLabels(): Promise<string[]> {
    const asyncFunc = async (): Promise<string[]> => {
      if (!this.outMetadata) {
        return [];
      }

      return await this.attachment.client.statusAction(async (status) => {
        const metaData = this.outMetadata!;
        const count = metaData.getCountSync(status);
        const array: string[] = [];

        for (let i = 0; i < count; ++i) {
          array.push(metaData.getAliasSync(status, i)!);
        }

        return array;
      });
    };

    return asyncFunc();
  }

  get type(): Promise<StatementType> {
    if (!this.typePromise) {
      const asyncFunc = async (): Promise<StatementType> => {
        return await this.attachment.client.statusAction((status) => this.statementHandle!.getTypeAsync(status));
      };
      this.typePromise = asyncFunc();
    }

    return this.typePromise;
  }
}
