/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup InvPrintf InvPrintf
	@brief Basic printf variant
    @ingroup EmbUtils
    @{
*/

#ifndef _INV_PRINTF_H_
#define _INV_PRINTF_H_

#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief	Overloadable hook to putchar method
 */
#if !defined(INV_PRINTF_PUTCHAR_HOOK)
	#define INV_PRINTF_PUTCHAR_HOOK putchar
#else
	extern int INV_PRINTF_PUTCHAR_HOOK(int c);
#endif

/** @brief	Basic version of vprintf()
 */
int inv_vprintf(const char *fmt, va_list args);

/** @brief	Basic version of printf()
 */
static inline int inv_printf(const char *fmt, ...)
{
	va_list args;
	int rc;
	va_start(args, fmt);
	rc = inv_vprintf(fmt, args);
	va_end(args);
	return rc;
}

#ifdef __cplusplus
}
#endif

#endif /* _INV_PRINTF_H_ */

/** @} */
