require('source-map-support').install();

import { generate, load } from 'node-cloop-gen';
import { patch } from './patch';


const root = process.cwd();
const inputFile = `${root}/src/generate-files/firebird.cloop.json`;
const outputCpp = `${root}/src/native/cloop-gen.h`;
const outputTs = `${root}/src/lib/cloop-gen.ts`;

const library = load(inputFile);

patch(library);

generate({
	library,
	outputCpp,
	outputTs,
	namespace: 'fb'
});
