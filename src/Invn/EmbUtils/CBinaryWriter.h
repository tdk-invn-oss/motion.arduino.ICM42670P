/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** \defgroup CBinaryWriter CBinaryWriter
	\brief Functions to serialize data into a linear buffer
    \ingroup EmbUtils
    \{
*/

#ifndef _C_BINARY_WRITER_H_
#define _C_BINARY_WRITER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "InvString.h"

/** \brief  CBinaryWriter definition
*/
typedef struct {
	uint8_t 	*buffer;
	uint16_t	size;
	uint16_t	offset;
} CBinaryWriter;

/** \brief  Initialize states of a CBinaryWriter object
	\param[in]	reader 	pointer to CBinaryWriter object
	\param[in]	buffer 	pointer to buffer that will contained serialized data
	\param[in]	size 	maximum size of the buffer
*/
static inline void CBinaryWriter_init(CBinaryWriter *reader, void *buffer,
                                      uint16_t size)
{
	reader->buffer 	= (uint8_t *)buffer;
	reader->size 	= size;
	reader->offset  = 0;
}

/** \brief  Write data to CBinaryWriter object
	\param[in]	reader 	pointer to CBinaryWriter object
	\param[in]	in 		pointer to data to write
	\param[in]	size 	size of data to write
	\return 	number of bytes written
*/
static inline uint16_t CBinaryWriter_write(CBinaryWriter *reader,
                const void *in, uint16_t size)
{
	if (reader->offset + size > reader->size) {
		size = reader->size - reader->offset;
	}

	InvString_memcpy(&reader->buffer[reader->offset], in, size);

	reader->offset += size;

	return size;
}

/** \brief  Return size of data contained in a CBinaryWriter object
	\return 	size of the CBinaryWriter buffer
*/
static inline uint16_t CBinaryWriter_size(CBinaryWriter *reader)
{
	return reader->offset;
}

/** \brief  Return pointer to data contained in a CBinaryWriter object
	\return 	pointer to the CBinaryWriter buffer
*/
static inline void *CBinaryWriter_data(CBinaryWriter *reader)
{
	return reader->buffer;
}

#ifdef __cplusplus
}
#endif

#endif

/** \} */
