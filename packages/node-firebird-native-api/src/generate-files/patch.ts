import { Library } from 'node-cloop-gen';


type InterfaceConfig = Record<string, { deleteMethods?: string[] }>;

const interfaceConfig: InterfaceConfig = {
	Util: {
		deleteMethods: [
			'dumpBlob',
			'loadBlob',
			'getPerfCounters',
			'formatStatus'
		]
	},

	Statement: {
	},

	Status: {
		deleteMethods: [
			'getErrors',
			'getWarnings',
			'setErrors',
			'setErrors2',
			'setWarnings',
			'setWarnings2'
		]
	},

	Attachment: {
		deleteMethods: [
			'getSlice',
			'putSlice'
		]
	},

	Transaction: {
	},

	Provider: {
	},

	CryptKey: {
		deleteMethods: [
			'*'
		]
	},

	DbCryptPlugin: {
		deleteMethods: [
			'*'
		]
	},

	ExternalEngine: {
		deleteMethods: [
			'*'
		]
	},

	ExternalContext: {
		deleteMethods: [
			'*'
		]
	},

	ExternalFunction: {
		deleteMethods: [
			'*'
		]
	},

	ExternalProcedure: {
		deleteMethods: [
			'*'
		]
	},

	ExternalTrigger: {
		deleteMethods: [
			'*'
		]
	},

	TraceTransaction: {
		deleteMethods: [
			'*'
		]
	},

	TraceParams: {
		deleteMethods: [
			'*'
		]
	},

	TraceStatement: {
		deleteMethods: [
			'*'
		]
	},

	TraceSQLStatement: {
		deleteMethods: [
			'*'
		]
	},

	TraceBLRStatement: {
		deleteMethods: [
			'*'
		]
	},

	TraceDYNRequest: {
		deleteMethods: [
			'*'
		]
	},

	TraceContextVariable: {
		deleteMethods: [
			'*'
		]
	},

	TraceProcedure: {
		deleteMethods: [
			'*'
		]
	},

	TraceFunction: {
		deleteMethods: [
			'*'
		]
	},

	TraceTrigger: {
		deleteMethods: [
			'*'
		]
	},

	TraceServiceConnection: {
		deleteMethods: [
			'*'
		]
	},

	TraceStatusVector: {
		deleteMethods: [
			'*'
		]
	},

	TraceSweepInfo: {
		deleteMethods: [
			'*'
		]
	},

	TraceLogWriter: {
		deleteMethods: [
			'*'
		]
	},

	TraceInitInfo: {
		deleteMethods: [
			'*'
		]
	},

	TracePlugin: {
		deleteMethods: [
			'*'
		]
	},

	TraceFactory: {
		deleteMethods: [
			'*'
		]
	}
};


export function patch(library: Library) {
	for (const intfName in interfaceConfig) {
		if (!Object.prototype.hasOwnProperty.call(interfaceConfig, intfName))
			continue;

		const intf = library.interfacesByName[intfName];
		const config = interfaceConfig[intfName];

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

	library.interfacesByName.Util.methodsByName.decodeDate.parameters[0].type.name = 'int';
	library.interfacesByName.Util.methodsByName.decodeTime.parameters[0].type.name = 'int';
	library.interfacesByName.Util.methodsByName.encodeDate.returnType.name = 'int';
	library.interfacesByName.Util.methodsByName.encodeTime.returnType.name = 'int';
}
