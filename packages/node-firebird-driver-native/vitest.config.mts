import { defineConfig } from 'vitest/config';

export default defineConfig({
  test: {
    globals: true,
    include: ['src/test/**/*.{test,spec}.ts', 'src/test/test.ts'],
    testTimeout: 10000,
  },
});
