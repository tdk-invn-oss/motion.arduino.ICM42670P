/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** \defgroup InvString InvString
	\brief Macros to wrap C lib functions from string.h
    \ingroup EmbUtils
    \{
*/

#ifndef _INV_STRING_H_
#define _INV_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <string.h>

/** \brief  Copies block of memory

    Copies n bytes from memory area src to memory area dest.
    The memory areas must not overlap.
*/
#ifndef InvString_memcpy
static inline void *InvString_memcpy(void *dest, const void *src, size_t n)
{
	return memcpy(dest, src, n);
}
#else
#undef InvString_memcpy
extern void *InvString_memcpy(void *dest, const void *src, size_t n);
#endif

/** \brief  Fills block of memory

    Fills the first n bytes of the memory area pointed to by s with the constant byte c.
*/
#ifndef InvString_memset
static inline void *InvString_memset(void *s, int c, size_t n)
{
	return memset(s, c, n);
}
#else
#undef InvString_memset
extern void *InvString_memset(void *s, int c, size_t n);
#endif

/** \brief  Copies block of memory

    Copies n bytes from memory area src to memory area dest.
    The memory areas may overlap: copying takes place as though the bytes in src
    are first copied into a temporary array that does not overlap src or dest,
    and the bytes are then copied from the temporary array to dest.
*/
#ifndef InvString_memset
static inline void *InvString_memmove(void *dest, const void *src, size_t n)
{
	return memmove(dest, src, n);
}
#else
#undef InvString_memset
extern void *InvString_memset(void *s, int c, size_t n);
#endif

/** \brief  Compare block of memory

    Compares the first n bytes (each interpreted as unsigned char) of
    the memory areas s1 and s2.  It returns  an  integer less  than,
    equal  to,  or  greater than zero if s1 is found, respectively,
    to be less than, to match, or be greater than s2.
*/
#ifndef InvString_memcmp
static inline int InvString_memcmp(const void *s1, const void *s2, size_t n)
{
	return memcmp(s1, s2, n);
}
#else
#undef InvString_memcmp
extern void *InvString_memcmp(void *s, int c, size_t n);
#endif

#ifdef __cplusplus
}
#endif

#endif

/** \} */
