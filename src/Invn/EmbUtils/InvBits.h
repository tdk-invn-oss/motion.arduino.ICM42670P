/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup InvBits InvBits
	@brief Useful macros to allow bit twidling and play with compact bitfields of arbitrary size
    @ingroup EmbUtils
    @{
*/

/** @brief This file provides
*/

#ifndef _INV_BITS_H_
#define _INV_BITS_H_

#include <limits.h>		/* for CHAR_BIT */
#include <string.h>		/* for memset and memcpy */

/** @brief Declare a bit fields of nb size
*/
#define BITDECLARE(a, nb) 	unsigned char (a)[BITNSLOTS(nb)]

/** @brief Define a bit fields of nb size implented using array of bytes
*/
#define BITDEFINE(a, nb) 	BITDECLARE(a, nb) = {0}

/** @brief Reset bit fields
*/
#define BITRESET(a, nb) 	memset(a, 0, BITNSLOTS(nb))

/** @brief Copy bit fields
*/
#define BITCOPY(a, b, nb) 	memcpy(a, b, BITNSLOTS(nb))

/** @brief Return number of slot in the byte array for nb bits
*/
#define BITNSLOTS(nb) 		(((nb) + CHAR_BIT - 1) / CHAR_BIT)

/** @brief Get mask of b-th bit
*/
#define BITMASK(b) 			(1U << ((b) % CHAR_BIT))

/** @brief Get slot in byte array for b-th bit
*/
#define BITSLOT(b) 			((b) / CHAR_BIT)

/** @brief Set bit b in bitfield a
*/
#define BITSET(a, b) 		((a)[BITSLOT(b)] |= BITMASK(b))

/** @brief Clear bit b in bitfield a
*/
#define BITCLEAR(a, b) 		((a)[BITSLOT(b)] &= ~BITMASK(b))

/** @brief Return true if bit b in bitfield a is set
*/
#define BITTEST(a, b) 		((a)[BITSLOT(b)] & BITMASK(b))

/** @brief Test if a bitfiel is empty
*/
#define BITEMPTY(a, nb) (BitEmpty(a, nb) == 1)

/** @brief Return 1 if bitfiel is empty, 0 if not and -1 on error (nb > 128)
*/
static inline int BitEmpty(const unsigned char *a, unsigned nb)
{
	BITDEFINE(zero, 256); // maximum bit field

	if (nb > 256) {
		return -1;
	}

	const int cmp = memcmp(zero, a, BITNSLOTS(nb));
	return (cmp == 0);
}

#endif /* _INV_BITS_H_ */

/** @} */
