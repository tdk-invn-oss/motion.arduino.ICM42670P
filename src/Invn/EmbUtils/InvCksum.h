/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup InvCksum InvCksum
	@brief Function to compute a basic 16 bits checksum
    @ingroup EmbUtils
    @{
*/

#ifndef _LOG2U_H_
#define _LOG2U_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/** @brief 	Compute 16 bits checksum over a buffer
	@param[in] 	data 	pointer to data
	@param[in] 	len 	size of data
	@return 16 bits checksum
*/
uint16_t InvCksum_compute(const void *data, unsigned long len);

#ifdef __cplusplus
}
#endif

#endif

/** @} */
