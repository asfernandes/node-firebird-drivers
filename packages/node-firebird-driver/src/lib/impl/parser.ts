type State = 'DEFAULT' | 'QUOTE' | 'COMMENT' | 'LINECOMMENT';

const isValidParamName = (ch: string) => {
	const CODE_A                = 'a'.charCodeAt(0);
	const CODE_Z                = 'z'.charCodeAt(0);
	const CODE_A_UPPER          = 'A'.charCodeAt(0);
	const CODE_Z_UPPER          = 'Z'.charCodeAt(0);
	const CODE_0                = '0'.charCodeAt(0);
	const CODE_9                = '9'.charCodeAt(0);
	const c = ch.charCodeAt(0);
	return (c >= CODE_A && c <= CODE_Z)
		|| (c >= CODE_A_UPPER && c <= CODE_Z_UPPER)
		|| (c >= CODE_0 && c <= CODE_9)
		|| (ch === '_');
};

export interface IParseResult {
  sqlStmt: string;
  paramNames?: string[];
};

export const parseParams = (sqlStmt: string): IParseResult => {
	let i = 0;
	let state: State = 'DEFAULT';
	let quoteChar = '';
	const params: [number, number][] = [];

	while (i < sqlStmt.length - 1) {
		// Get the current token and a look-ahead
		const c = sqlStmt[i];
		const nc = sqlStmt[i + 1];

		// Now act based on the current state
		switch (state) {
			case 'DEFAULT':
				switch (c) {
					case '"':
					case '\'':
						quoteChar = c;
						state = 'QUOTE';
						break;

					case ':': {
						const paramStart = i + 1;
						for (i = paramStart; i < sqlStmt.length && isValidParamName(sqlStmt[i]); i++);
						if (i === paramStart) {
							throw new Error(`SQL syntax error. No param name found at position ${i}.`);
						}
						params.push([paramStart, i]);
						i--;
						break;
					}

					case '/':
						if (nc === '*') {
							i++;
							state = 'COMMENT';
						}
						break;

					case '-':
						if (nc === '-') {
							i++;
							state = 'LINECOMMENT';
						}
						break;
				}
				break;

			case 'COMMENT':
				if (c === '*' && nc === '/') {
					i++;
					state = 'DEFAULT';
				}
				break;

			case 'LINECOMMENT':
				if (nc === '\n' || nc === '\r') {
					i++;
					state = 'DEFAULT';
				}
				break;

			case 'QUOTE':
				if (c === quoteChar) {
					if (nc === quoteChar) {
						i++;
					} else {
						state = 'DEFAULT';
					}
				}
				break;
		}

		i++;
	}

	if (state !== 'DEFAULT' && state !== 'LINECOMMENT') {
		throw new Error('SQL syntax error');
	}

	const paramNames = params.map( ([start, end]) => sqlStmt.slice(start, end) );

	return paramNames.length ?
		{
			sqlStmt: params
				.map( ([start], idx) => sqlStmt.slice(idx ? params[idx - 1][1] : 0, start - 1) )
				.concat(sqlStmt.slice(params[params.length - 1][1]))
				.join('?'),
			paramNames
	  	}
	  	:
		{
			sqlStmt
	  	};
};