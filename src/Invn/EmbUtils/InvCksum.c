/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "InvCksum.h"

uint16_t InvCksum_compute(const void *data, unsigned long len)
{
	uint16_t chk = 1;
	unsigned long i;
	const uint8_t *pdata = data;

	for (i = 0; i < len; ++i) {
		chk = (chk << 1) + chk + pdata[i];
	}

	return chk;
}


