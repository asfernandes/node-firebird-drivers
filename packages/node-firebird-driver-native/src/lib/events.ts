import { AttachmentImpl } from './attachment';

import { AbstractEvents, epb } from 'node-firebird-driver/dist/lib/impl';

import * as fb from 'node-firebird-native-api';

import { StringDecoder } from 'string_decoder';


/** Events implementation. */
export class EventsImpl extends AbstractEvents {
	// Override declarations.
	attachment: AttachmentImpl;

	eventBlock: EventBlock;
	eventsHandle: fb.Events;

	static async queue(attachment: AttachmentImpl, names: string[], callBack: (counters: [string, number][]) => Promise<void>):
			Promise<EventsImpl> {
		const events = new EventsImpl(attachment);
		const { client } = attachment;

		events.eventBlock = newEventBlock(names);

		const scheduleEvent = async () => {
			const eventCallback = createEventCallback(events.eventBlock, async counters => {
				await callBack(counters);

				if (events.eventsHandle)
					await scheduleEvent();
			});

			if (events.eventsHandle) {
				const { eventsHandle } = events;
				events.eventsHandle = undefined!;
				eventsHandle.releaseSync();
			}

			events.eventsHandle = (await client.statusAction(async status =>
				await attachment.attachmentHandle!.queEventsAsync(status, eventCallback,
					events.eventBlock.eventBuffer.length, events.eventBlock.eventBuffer)
			))!;
		};

		await scheduleEvent();

		return events;
	}

	/** Disposes this events' resources. */
	protected async internalCancel(): Promise<void> {
		await this.attachment.client.statusAction(async status => {
			const { eventsHandle } = this;

			if (eventsHandle) {
				this.eventsHandle = undefined!;
				await eventsHandle.cancelAsync(status);
			}
		});
	}
}


interface EventBlock {
	eventBuffer: Buffer;
	map: Map<string, number>;
}

function newEventBlock(names: string[]): EventBlock {
	const buffers = names.map(name => {
		const buffer = Buffer.from(name.trimRight());

		if (buffer.byteLength > 255)
			throw new Error(`Invalid event name: ${name}.`);

		return buffer;
	});

	const eventBuffer = Buffer.concat([
		Buffer.from([epb.version1]),
		...buffers.map(nameBuffer => Buffer.concat([
			Buffer.from([nameBuffer.byteLength]),
			nameBuffer,
			Buffer.from([1, 0, 0, 0])
		]))
	]);

	return {
		eventBuffer,
		map: new Map<string, number>(names.map(name => [name, 1]))
	};
}

function createEventCallback(eventBlock: EventBlock, callBack: (counters: [string, number][]) => Promise<void>) {
	const eventCallBack = fb.newEventCallback(async buffer => {
		const counters: [string, number][] = [];
		const dv = new DataView(buffer);
		let pos = 1;

		while (pos < dv.byteLength) {
			const nameLen = dv.getUint8(pos);
			const name = new StringDecoder('utf8').end(Buffer.from(buffer.slice(pos + 1, pos + 1 + nameLen)));
			const count = dv.getUint32(pos + 1 + nameLen, true);

			counters.push([name, count - (eventBlock.map.get(name) || 0)]);
			eventBlock.map.set(name, count);

			pos += 1 + nameLen + 4;
		}

		eventBlock.eventBuffer.fill(new Uint8Array(buffer));

		await callBack(counters);
	});

	eventCallBack.addRefSync();

	return eventCallBack;
}
