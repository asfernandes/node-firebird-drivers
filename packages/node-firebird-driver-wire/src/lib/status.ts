import { FbError, parseRawStatusVector } from 'node-firebird-driver';

import { statusArgument } from './constants';
import { errorMessagesByCode } from './error-messages';

const {
  cstring: isc_arg_cstring,
  end: isc_arg_end,
  gds: isc_arg_gds,
  interpreted: isc_arg_interpreted,
  number: isc_arg_number,
  string: isc_arg_string,
  warning: isc_arg_warning,
} = statusArgument;

export interface ParsedStatusVector {
  readonly isError: boolean;
  readonly gdsCodes: number[];
  readonly warnings: number[];
  readonly messages: string[];
  readonly statusArguments: readonly StatusVectorArgument[];
}

export type StatusVectorArgument =
  | { readonly type: 'gds'; readonly code: number }
  | { readonly type: 'warning'; readonly code: number }
  | { readonly type: 'string' | 'interpreted' | 'number'; readonly value: string };

export class FirebirdWireError extends FbError {
  override readonly name = 'FirebirdWireError';
  readonly wireStatus: ParsedStatusVector;

  constructor(message: string, wireStatus: ParsedStatusVector) {
    super(message, parseRawStatusVector(wireStatus.statusArguments as any));
    this.wireStatus = wireStatus;
  }
}

function formatDecodedStatus(status: ParsedStatusVector): string | undefined {
  const lines: string[] = [];
  let currentSegment: { readonly code: number; readonly parameters: string[] } | undefined;

  const flushCurrentSegment = () => {
    if (!currentSegment) {
      return true;
    }

    const template = errorMessagesByCode[currentSegment.code];

    if (!template) {
      return false;
    }

    lines.push(formatTemplate(template, currentSegment.parameters));
    currentSegment = undefined;
    return true;
  };

  for (const argument of status.statusArguments) {
    if (argument.type === 'gds') {
      if (!flushCurrentSegment()) {
        return undefined;
      }

      currentSegment = { code: argument.code, parameters: [] };
      continue;
    }

    if (argument.type === 'warning') {
      if (!flushCurrentSegment()) {
        return undefined;
      }

      continue;
    }

    if (argument.type === 'interpreted') {
      if (!flushCurrentSegment()) {
        return undefined;
      }

      lines.push(argument.value);
      continue;
    }

    if (currentSegment) {
      currentSegment.parameters.push(argument.value);
    }
  }

  if (!flushCurrentSegment() || lines.length === 0) {
    return undefined;
  }

  return lines.map((line, index) => (index === 0 ? line : `-${line}`)).join('\n');
}

function formatTemplate(template: string, parameters: readonly string[]): string {
  return template.replace(/@(\d+)/g, (placeholder, positionText: string) => {
    const parameter = parameters[Number(positionText) - 1];
    return parameter ?? placeholder;
  });
}

export function parseStatusVector(buffer: Buffer): ParsedStatusVector {
  const gdsCodes: number[] = [];
  const warnings: number[] = [];
  const messages: string[] = [];
  const statusArguments: StatusVectorArgument[] = [];
  let isError = false;
  let offset = 0;

  const readInt32 = () => {
    const value = buffer.readInt32BE(offset);
    offset += 4;
    return value;
  };

  while (true) {
    const tag = readInt32();
    if (tag === isc_arg_end) {
      break;
    }

    if (tag === isc_arg_gds) {
      const code = readInt32();
      if (code !== 0) {
        isError = true;
        gdsCodes.push(code);
        statusArguments.push({ type: 'gds', code });
      }
      continue;
    }

    if (tag === isc_arg_warning) {
      const code = readInt32();
      if (code !== 0) {
        warnings.push(code);
        statusArguments.push({ type: 'warning', code });
      }
      continue;
    }

    if (tag === isc_arg_string || tag === isc_arg_interpreted) {
      const textLength = readInt32();
      const text = buffer.subarray(offset, offset + textLength).toString('utf8');
      offset += textLength;
      messages.push(text);
      statusArguments.push({ type: tag === isc_arg_interpreted ? 'interpreted' : 'string', value: text });
      continue;
    }

    if (tag === isc_arg_cstring) {
      const textLength = readInt32();
      const text = buffer.subarray(offset, offset + textLength).toString('utf8');
      offset += textLength;
      messages.push(text);
      statusArguments.push({ type: 'string', value: text });
      continue;
    }

    if (tag === isc_arg_number) {
      const value = String(readInt32());
      messages.push(value);
      statusArguments.push({ type: 'number', value });
      continue;
    }

    readInt32();
  }

  return { isError, gdsCodes, warnings, messages, statusArguments };
}

export function assertSuccessfulResponse(status: ParsedStatusVector, fallbackMessage: string): void {
  if (!status.isError) {
    return;
  }

  const knownStatus = formatDecodedStatus(status);

  if (knownStatus) {
    throw new FirebirdWireError(knownStatus, status);
  }

  const detailParts: string[] = [];

  if (status.gdsCodes.length > 0) {
    detailParts.push(`gds=${status.gdsCodes.join(',')}`);
  }

  if (status.messages.length > 0) {
    detailParts.push(status.messages.join(' | '));
  }

  throw new FirebirdWireError(
    detailParts.length > 0 ? `${fallbackMessage}: ${detailParts.join(' | ')}` : fallbackMessage,
    status,
  );
}
