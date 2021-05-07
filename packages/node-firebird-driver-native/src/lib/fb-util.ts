import { charSets, sqlTypes, Descriptor } from 'node-firebird-driver/dist/lib/impl';
export * from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';


/** Fix metadata descriptors to types we want to read. */
export function fixMetadata(status: fb.Status, metadata?: fb.MessageMetadata): fb.MessageMetadata | undefined {
	if (!metadata)
		return undefined;

	let ret: fb.MessageMetadata;

	const outBuilder = metadata.getBuilderSync(status)!;
	try {
		for (let i = metadata.getCountSync(status) - 1; i >= 0; --i) {
			switch (metadata.getTypeSync(status, i)) {
				// Transform CHAR descriptors to VARCHAR.
				case sqlTypes.SQL_TEXT:
					outBuilder.setTypeSync(status, i, sqlTypes.SQL_VARYING);
					break;

				// Transform numeric descriptors to DOUBLE PRECISION.
				case sqlTypes.SQL_SHORT:
				case sqlTypes.SQL_LONG:
				case sqlTypes.SQL_INT64:
				case sqlTypes.SQL_FLOAT:
					outBuilder.setTypeSync(status, i, sqlTypes.SQL_DOUBLE);
					outBuilder.setLengthSync(status, i, 8);
					outBuilder.setScaleSync(status, i, 0);
					break;

				// Transform INT128, DEC16 and DEC34 descriptors to VARCHAR.
				case sqlTypes.SQL_INT128:
				case sqlTypes.SQL_DEC16:
				case sqlTypes.SQL_DEC34:
					outBuilder.setTypeSync(status, i, sqlTypes.SQL_VARYING);
					outBuilder.setLengthSync(status, i, 45);
					outBuilder.setCharSetSync(status, i, charSets.ascii);
					break;
			}
		}

		ret = outBuilder.getMetadataSync(status)!;
	}
	finally {
		outBuilder.releaseSync();
	}

	metadata.releaseSync();

	return ret;
}

export function createDescriptors(status: fb.Status, metadata?: fb.MessageMetadata): Descriptor[] {
	if (!metadata)
		return [];

	const count = metadata.getCountSync(status);
	const ret: Descriptor[] = [];

	for (let i = 0; i < count; ++i) {
		ret.push({
			type: metadata.getTypeSync(status, i),
			subType: metadata.getSubTypeSync(status, i),
			nullOffset: metadata.getNullOffsetSync(status, i),
			offset: metadata.getOffsetSync(status, i),
			length: metadata.getLengthSync(status, i),
			scale: metadata.getScaleSync(status, i)
		});
	}

	return ret;
}
