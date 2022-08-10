/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup InvFormat InvFormat
	@brief (Overloadable) macros and functions to convert number and format strings
    @ingroup EmbUtils
    @{
*/

#ifndef _INV_FORMAT_H_
#define _INV_FORMAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

/** @brief  Convert 16 bits integer to hexadecimal string
*/
char *InvFormat_uint162hex(char out[5], uint16_t a);

/** @brief  Convert 32 bits integer to hexadecimal string
*/
char *InvFormat_uint322hex(char out[9], uint32_t a);

#ifdef __cplusplus
}
#endif

#endif /* _INV_BASIC_MATH_H_ */

/** @} */
