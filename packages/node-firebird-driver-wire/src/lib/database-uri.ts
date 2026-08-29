import { wireProtocol } from './constants';

export interface ParsedDatabaseUri {
  readonly host: string;
  readonly port: number;
  readonly database: string;
}

export function parseDatabaseUri(uri: string): ParsedDatabaseUri {
  // Treat rooted Windows drive paths as hostless URIs.
  if (/^[A-Za-z]:(?:[\\/]|$)/.test(uri)) {
    return {
      host: 'localhost',
      port: wireProtocol.defaultPort,
      database: uri,
    };
  }

  // Check for URL-like syntax with inet, inet4, inet6 protocols (and optionally others like xnet)
  // Format: [ <protocol> : // [ <host> [ : <port> ] ] ] / <file path to database or alias>
  const urlMatch = /^([A-Za-z0-9]+):\/\/(.*)$/.exec(uri);
  if (urlMatch) {
    const remainder = urlMatch[2];
    let host = 'localhost';
    let port = wireProtocol.defaultPort;
    let database: string;

    if (remainder.startsWith('/')) {
      // Hostless absolute Unix path: e.g. inet:///db/mydb.fdb
      database = remainder;
    } else {
      const slashIndex = remainder.indexOf('/');
      if (slashIndex !== -1) {
        const authority = remainder.substring(0, slashIndex);
        database = remainder.substring(slashIndex + 1);

        if (authority) {
          const portIndex = authority.lastIndexOf(':');
          if (portIndex !== -1) {
            host = authority.substring(0, portIndex);
            const portStr = authority.substring(portIndex + 1);
            if (portStr && !isNaN(Number(portStr))) {
              port = parseInt(portStr, 10);
            }
          } else {
            host = authority;
          }
        }
      } else {
        // Hostless, relative path, alias, or Windows drive path: e.g. inet://mydb, inet://C:\db\mydb.fdb
        database = remainder;
      }
    }

    return { host, port, database };
  }

  const match = /^(?:(.+?)(?:\/(\d+))?:)?(.+)$/.exec(uri);
  if (!match) {
    throw new Error(`Invalid Firebird database URI '${uri}'.`);
  }

  return {
    host: match[1] || 'localhost',
    port: match[2] ? parseInt(match[2], 10) : wireProtocol.defaultPort,
    database: match[3],
  };
}
