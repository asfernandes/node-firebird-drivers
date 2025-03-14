import { AttachmentImpl } from './attachment';

import { AbstractEvents } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';

/** Events implementation. */
export class EventsImpl extends AbstractEvents {
  // Override declarations.
  override attachment: AttachmentImpl;

  eventCallback: fb.EventCallback;

  static async queue(
    attachment: AttachmentImpl,
    names: string[],
    callBack: (counters: [string, number][]) => Promise<void>,
  ): Promise<EventsImpl> {
    const events = new EventsImpl(attachment);
    const { client } = attachment;

    events.eventCallback = await fb.queueEvent(client.master!, attachment.attachmentHandle!, names, callBack);

    return events;
  }

  /** Disposes this events' resources. */
  protected async internalCancel(): Promise<void> {
    if (this.eventCallback) {
      const { eventCallback } = this;
      this.eventCallback = undefined!;
      await fb.cancelEvent(eventCallback);
    }
  }
}
