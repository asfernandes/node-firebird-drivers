/*******************************************************************************
The MIT License (MIT)

Copyright (c) 2013-2016 Hajime Nakagami

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*******************************************************************************/

// These functions was adapted from https://github.com/nakagami/firebirdsql

/** Decode a date. */
export function decodeDate(date: number) {
	let nday = date + 678882;
	const century = Math.trunc((4 * nday - 1) / 146097);
	nday = 4 * nday - 1 - 146097 * century;
	let day = Math.trunc(nday / 4);

	nday = Math.trunc((4 * day + 3) / 1461);
	day = 4 * day + 3 - 1461 * nday;
	day = Math.trunc((day + 4) / 4);

	let month = Math.trunc((5 * day - 3) / 153);
	day = 5 * day - 3 - 153 * month;
	day = Math.trunc((day + 5) / 5);
	let year = 100 * century + nday;

	if (month < 10)
		month += 3;
	else {
		month -= 9;
		year += 1;
	}

	return { year, month, day };
}

/** Encode a date. */
export function encodeDate(year: number, month: number, day: number): number {
	const i = month + 9;
	let jy = year + Math.trunc(i / 12) - 1;
	const jm = i % 12;
	const c = Math.trunc(jy / 100);
	jy -= 100 * c;
	const j = Math.trunc((146097 * c) / 4) + Math.trunc((1461 * jy) / 4) + Math.trunc((153 * jm + 2) / 5) + day - 678882;

	return j;
}

/** Descode a time. */
export function decodeTime(time: number) {
	let seconds = Math.trunc(time / 10000);
	let minutes = Math.trunc(seconds / 60);
	const hours = Math.trunc(minutes / 60);
	minutes = minutes % 60;
	seconds = seconds % 60;
	const fractions = time % 10000;

	return { hours, minutes, seconds, fractions };
}

/** Encode a time. */
export function encodeTime(hours: number, minutes: number, seconds: number, fractions: number): number {
	return (hours * 3600 + minutes * 60 + seconds) * 10000 + fractions;
}
