/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "InvFormat.h"

#include "InvString.h"

static char *InvFormat_uint2hex(char *out, uint32_t a, size_t size)
{
	static const char hexTab[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	size_t i = size;

	InvString_memset(out, '0', size);
	out[size] = '\0';

	do
	{
		uint32_t remain;
		remain = a % 16;
		a >>= 4;
		out[--i] = hexTab[remain];
	} while (a != 0 && i != 0);

	return out;
}

char *InvFormat_uint162hex(char out[5], uint16_t a)
{
	return InvFormat_uint2hex(out, a, 2 * sizeof(a));
}

char *InvFormat_uint322hex(char out[9], uint32_t a)
{
	return InvFormat_uint2hex(out, a, 2 * sizeof(a));
}
