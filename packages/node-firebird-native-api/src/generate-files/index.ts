// eslint-disable-next-line @typescript-eslint/no-require-imports
require('source-map-support').install();

import { generate, load } from 'node-cloop-gen';
import { patch } from './patch';


const root = process.cwd();
const inputFile = `${root}/src/generate-files/firebird.cloop.json`;
const outputCppNapi = `${root}/src/native/cloop-gen.h`;
const outputTs = `${root}/src/lib/cloop-gen.ts`;

const library = load(inputFile);

patch(library);

generate({
	library,
	outputCppNapi,
	outputTs,
	namespace: 'fb'
});
