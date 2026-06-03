import { resolve } from 'node:path';

import { defineConfig } from 'vitest/config';

export default defineConfig({
  resolve: {
    alias: [
      {
        find: 'node-firebird-driver/dist/lib/impl',
        replacement: resolve(__dirname, '../node-firebird-driver/src/lib/impl/index.ts'),
      },
      {
        find: 'node-firebird-driver',
        replacement: resolve(__dirname, '../node-firebird-driver/src/lib/index.ts'),
      },
    ],
  },
  test: {
    globals: true,
    include: ['src/test/**/*.{test,spec}.ts', 'src/test/test.ts'],
    testTimeout: 10000,
  },
});
