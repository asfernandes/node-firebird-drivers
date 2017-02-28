import { Library } from 'node-cloop-gen';


interface InterfaceConfig
{
	[intf: string]: {
		deleteMethods?: string[],
		asyncMethods?: string[]
	};
}

//// FIXME: release/dispose - async?

const interfaceConfig: InterfaceConfig = {
	'Util': {
		deleteMethods: [
			'dumpBlob',
			'loadBlob',
			'getPerfCounters',
			'formatStatus'
		]
	},

	'Statement': {
		asyncMethods: [
			'getInfo',
			'getType',
			'getPlan',
			'getAffectedRecords',
			'getInputMetadata',
			'getOutputMetadata',
			'execute',
			'openCursor',
			'setCursorName',
			'free',
			'getFlags'
		]
	},

	'Status': {
		deleteMethods: [
			'getErrors',
			'getWarnings',
			'setErrors',
			'setErrors2',
			'setWarnings',
			'setWarnings2'
		]
	},

	'Attachment': {
		asyncMethods: [
			'getInfo',
			'startTransaction',
			'reconnectTransaction',
			'compileRequest',
			'transactRequest',
			'executeDyn',
			'prepare',
			'execute',
			'openCursor',
			'queEvents',
			'cancelOperation',
			'ping',
			'detach',
			'dropDatabase',
			'createBlob',
			'openBlob',
			'getSlice',
			'putSlice'
		],

		deleteMethods: [
			'createBlob',
			'openBlob',
			'getSlice',
			'putSlice'
		]
	},

	'Transaction': {
		asyncMethods: [
			'commit',
			'commitRetaining'
		]
	},

	'Provider': {
		asyncMethods: [
			'createDatabase'
		]
	},

	'CryptKey': {
		deleteMethods: [
			'*'
		]
	},

	'DbCryptPlugin': {
		deleteMethods: [
			'*'
		]
	},

	'ExternalEngine': {
		deleteMethods: [
			'*'
		]
	},

	'ExternalContext': {
		deleteMethods: [
			'*'
		]
	},

	'ExternalFunction': {
		deleteMethods: [
			'*'
		]
	},

	'ExternalProcedure': {
		deleteMethods: [
			'*'
		]
	},

	'ExternalTrigger': {
		deleteMethods: [
			'*'
		]
	},

	'TraceTransaction': {
		deleteMethods: [
			'*'
		]
	},

	'TraceParams': {
		deleteMethods: [
			'*'
		]
	},

	'TraceStatement': {
		deleteMethods: [
			'*'
		]
	},

	'TraceSQLStatement': {
		deleteMethods: [
			'*'
		]
	},

	'TraceBLRStatement': {
		deleteMethods: [
			'*'
		]
	},

	'TraceDYNRequest': {
		deleteMethods: [
			'*'
		]
	},

	'TraceContextVariable': {
		deleteMethods: [
			'*'
		]
	},

	'TraceProcedure': {
		deleteMethods: [
			'*'
		]
	},

	'TraceFunction': {
		deleteMethods: [
			'*'
		]
	},

	'TraceTrigger': {
		deleteMethods: [
			'*'
		]
	},

	'TraceServiceConnection': {
		deleteMethods: [
			'*'
		]
	},

	'TraceStatusVector': {
		deleteMethods: [
			'*'
		]
	},

	'TraceSweepInfo': {
		deleteMethods: [
			'*'
		]
	},

	'TraceLogWriter': {
		deleteMethods: [
			'*'
		]
	},

	'TraceInitInfo': {
		deleteMethods: [
			'*'
		]
	},

	'TracePlugin': {
		deleteMethods: [
			'*'
		]
	},

	'TraceFactory': {
		deleteMethods: [
			'*'
		]
	}
};


export function patch(library: Library) {
	for (const intfName in interfaceConfig) {
		const intf = library.interfacesByName[intfName];
		const config = interfaceConfig[intfName];

		for (const asyncMethod of config.asyncMethods || [])
			intf.methodsByName[asyncMethod].async = true;

		for (const deleteMethod of config.deleteMethods || []) {
			const methods = intf.methods;
			let found = false;

			for (const [index, method] of methods.entries()) {
				if (deleteMethod == '*') {
					methods.splice(0);
					found = true;
				}
				else if (method.name == deleteMethod) {
					methods.splice(index, 1);
					found = true;
					break;
				}
			}

			if (!found) {
				console.error(`Method '${intfName}#${deleteMethod}' not found for deletion.`);
				process.exit(1);
			}
		}
	}

	library.interfacesByName['Util'].methodsByName['decodeDate'].parameters[0].type.name = "int";
	library.interfacesByName['Util'].methodsByName['decodeTime'].parameters[0].type.name = "int";
	library.interfacesByName['Util'].methodsByName['encodeDate'].returnType.name = "int";
	library.interfacesByName['Util'].methodsByName['encodeTime'].returnType.name = "int";

	for (const intf of library.interfaces) {
		for (const method of intf.methods)
			method.async = true;
	}
}
