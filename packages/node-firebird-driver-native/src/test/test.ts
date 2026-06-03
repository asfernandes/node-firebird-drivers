import { createNativeClient, getDefaultLibraryFilename } from '../lib';

import { runCommonTests } from '../../../node-firebird-driver/src/test/tests';

const client = createNativeClient(getDefaultLibraryFilename());

runCommonTests(client);
