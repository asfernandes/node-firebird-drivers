import { Socket } from 'node:net';
import { deflateSync, inflateSync } from 'node:zlib';

export class SocketChannel {
  private readonly buffers: Buffer[] = [];
  private bufferedLength = 0;
  private ended = false;
  private incomingTransform?: ((chunk: Buffer) => Buffer) | undefined;
  private outgoingTransform?: ((chunk: Buffer) => Buffer) | undefined;
  private incomingCompress = false;
  private outgoingCompress = false;
  private pendingRead?:
    | {
        length: number;
        resolve: (value: Buffer) => void;
        reject: (reason?: unknown) => void;
      }
    | undefined;

  constructor(private readonly socket: Socket) {
    socket.on('data', (chunk: Buffer) => {
      let data = chunk;
      if (this.incomingCompress) {
        data = inflateSync(data);
      }
      if (this.incomingTransform) {
        data = this.incomingTransform(data);
      }
      this.buffers.push(data);
      this.bufferedLength += data.length;
      this.flushPendingRead();
    });
    socket.on('end', () => {
      this.ended = true;
      this.flushPendingRead();
    });
    socket.on('close', () => {
      this.ended = true;
      this.flushPendingRead();
    });
    socket.on('error', (error) => {
      this.pendingRead?.reject(error);
      this.pendingRead = undefined;
    });
  }

  async readExactly(length: number): Promise<Buffer> {
    if (this.bufferedLength >= length) {
      return this.consume(length);
    }

    if (this.ended) {
      throw new Error(`Socket closed before ${length} bytes were available.`);
    }

    return await new Promise<Buffer>((resolve, reject) => {
      this.pendingRead = { length, resolve, reject };
    });
  }

  async write(buffer: Buffer): Promise<void> {
    let data = this.outgoingTransform ? this.outgoingTransform(buffer) : buffer;
    if (this.outgoingCompress) {
      data = deflateSync(data);
    }

    await new Promise<void>((resolve, reject) => {
      this.socket.write(data, (error) => {
        if (error) {
          reject(error);
        } else {
          resolve();
        }
      });
    });
  }

  setTransforms(transforms: {
    incoming?: ((chunk: Buffer) => Buffer) | undefined;
    outgoing?: ((chunk: Buffer) => Buffer) | undefined;
  }): void {
    if (this.bufferedLength !== 0 || this.pendingRead) {
      throw new Error('Cannot switch socket transforms while buffered data is pending.');
    }

    this.incomingTransform = transforms.incoming;
    this.outgoingTransform = transforms.outgoing;
  }

  enableCompression(): void {
    this.incomingCompress = true;
    this.outgoingCompress = true;
  }

  private flushPendingRead(): void {
    if (!this.pendingRead) {
      return;
    }

    if (this.bufferedLength >= this.pendingRead.length) {
      const pendingRead = this.pendingRead;
      this.pendingRead = undefined;
      pendingRead.resolve(this.consume(pendingRead.length));
      return;
    }

    if (this.ended) {
      const pendingRead = this.pendingRead;
      this.pendingRead = undefined;
      pendingRead.reject(new Error(`Socket closed before ${pendingRead.length} bytes were available.`));
    }
  }

  private consume(length: number): Buffer {
    const result = Buffer.alloc(length);
    let offset = 0;

    while (offset < length) {
      const chunk = this.buffers[0];
      const take = Math.min(chunk.length, length - offset);
      chunk.copy(result, offset, 0, take);
      offset += take;

      if (take === chunk.length) {
        this.buffers.shift();
      } else {
        this.buffers[0] = chunk.subarray(take);
      }
    }

    this.bufferedLength -= length;

    return result;
  }
}
