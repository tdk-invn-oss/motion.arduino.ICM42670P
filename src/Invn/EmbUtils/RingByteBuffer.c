/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "RingByteBuffer.h"

void RingByteBuffer_init(RingByteBuffer *self, uint8_t *pBuffer,
                         uint16_t sizeBuffer)
{
	ASSERT(self);
	ASSERT(pBuffer);

	self->buffer 	= pBuffer;
	self->size 		= sizeBuffer;

	RingByteBuffer_clear(self);
}

void RingByteBuffer_clear(RingByteBuffer *self)
{
	ASSERT(self);

	self->start		= 0;
	self->end		= 0;
	self->msbStart	= 0;
	self->msbEnd	= 0;
}

uint16_t RingByteBuffer_size(const RingByteBuffer *self)
{
	ASSERT(self);

	if (self->end > self->start) {
		return self->end - self->start;
	} else if (self->end < self->start) {
		return self->size - self->start + self->end;
	} else if (self->msbEnd != self->msbStart) {
		return self->size;
	} else {
		return 0;
	}
}

void RingByteBuffer_pushByte(RingByteBuffer *self, uint8_t byte)
{
	ASSERT(self);

	self->buffer[self->end] = byte;

	if (++self->end == self->size) {
		self->msbEnd ^= 1;
		self->end 	  = 0;
	}
}

uint8_t RingByteBuffer_popByte(RingByteBuffer *self)
{
	uint8_t byte;

	ASSERT(self);

	byte = self->buffer[self->start];

	if (++self->start == self->size) {
		self->msbStart ^= 1;
		self->start     = 0;
	}

	return byte;
}

void RingByteBuffer_pushBuffer(RingByteBuffer *self, const void *data,
                               uint16_t len)
{
	const uint8_t *byte;
	uint16_t i;

	ASSERT(self);
	ASSERT(data);

	byte = (const uint8_t *)data;

	for (i = 0; i < len; ++i) {
		RingByteBuffer_pushByte(self, byte[i]);
	}
}

void RingByteBuffer_popBuffer(RingByteBuffer *self, void *data, uint16_t len)
{
	uint8_t *byte;
	uint16_t i;

	ASSERT(self);
	ASSERT(data);

	byte = (uint8_t *)data;

	for (i = 0; i < len; ++i) {
		byte[i] = RingByteBuffer_popByte(self);
	}
}


