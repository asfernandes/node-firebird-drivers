/** A status vector item representing an error or warning code and its associated arguments. */
export interface FbStatus {
  readonly type: 'error' | 'warning';
  readonly code: number;
  readonly args: readonly (string | number)[];
}

/** Firebird error class representing a database exception. */
export class FbError extends Error {
  override readonly name: string = 'FbError';

  /** Array of structured status items. */
  readonly status: readonly FbStatus[];

  constructor(message: string, status: readonly FbStatus[]) {
    super(message);
    this.status = status;
  }

  /** Array of error codes. */
  get errors(): readonly number[] {
    return this.status.filter((s) => s.type === 'error').map((s) => s.code);
  }

  /** Array of error codes (alias for errors). */
  get gdsCodes(): readonly number[] {
    return this.errors;
  }

  /** Array of warning codes. */
  get warnings(): readonly number[] {
    return this.status.filter((s) => s.type === 'warning').map((s) => s.code);
  }

  /** Array of diagnostic/error message strings. */
  get messages(): readonly string[] {
    const list: string[] = [];
    for (const item of this.status) {
      for (const arg of item.args) {
        list.push(String(arg));
      }
    }
    return list;
  }
}
