import { createNativeClient, getDefaultLibraryFilename } from '../lib';

import { runCommonTests } from 'node-firebird-driver/dist/test/tests';

const client = createNativeClient(getDefaultLibraryFilename());

runCommonTests(client);
