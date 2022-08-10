/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** \defgroup CBinaryReader CBinaryReader
	\brief Functions to unserialize data from a linear buffer
	\ingroup EmbUtils
	\{
*/

#ifndef _C_BINARY_READER_H_
#define _C_BINARY_READER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "InvString.h"

/** \brief  CBinaryReader definition
*/
typedef struct {
	const uint8_t *buffer;
	uint16_t 			size;
	uint16_t 			offset;
} CBinaryReader;

/** \brief  Initialize states of a CBinaryReader object
	\param[in]	reader 	pointer to CBinaryReader object
	\param[in]	buffer 	pointer to serialized data
	\param[in]	size 	size of serialized data
*/
static inline void CBinaryReader_init(CBinaryReader *reader, const void *buffer,
                                      uint16_t size)
{
	reader->buffer 	= (const uint8_t *)buffer;
	reader->size 	= size;
	reader->offset  = 0;
}

/** \brief  Read data from a CBinaryReader object
	\param[in]	reader 	pointer to CBinaryReader object
	\param[in]	out 	pointer to output buffer
	\param[in]	size 	size of data to read
	\return 	number of bytes read
*/
static inline uint16_t CBinaryReader_read(CBinaryReader *reader, void *out,
                uint16_t size)
{
	if (reader->offset + size > reader->size) {
		size = reader->size - reader->offset;
	}

	InvString_memcpy(out, &reader->buffer[reader->offset], size);

	reader->offset += size;

	return size;
}

/** \brief  	Return current offset of a CBinaryReader object
	\return 	Current offset
*/
static inline uint16_t CBinaryReader_offset(CBinaryReader *reader)
{
	return reader->offset;
}

#ifdef __cplusplus
}
#endif

#endif

/** \} */
