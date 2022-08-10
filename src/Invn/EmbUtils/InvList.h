/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup InvList InvList
	@brief Basic methods to manage singly link-list
    @ingroup EmbUtils
    @{
*/

#ifndef _INV_LIST_H_
#define _INV_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "InvAssert.h"
#include "Invn/InvBool.h"

#include <stddef.h>		// for offsetof

/** @brief 	InvList definition
*/
typedef struct InvList {
	struct InvList *next;	/**< pointer to next element */
} InvList ;

/** @brief 	Initialize a list
*/
static inline void InvList_init(InvList *list)
{
	ASSERT(list);

	list->next = 0;
}

/** @brief 	Return pointer to object based on node address
*/
#define INVLIST_GET(pnode, type, member) ((type *)((ptrdiff_t)(pnode) - offsetof(type, member)))

/** @brief 	Add item at the tail of a list
	@return 0 on success, -1 on error (ie: node is already in list)
*/
int InvList_add(InvList *list, InvList *node);

/** @brief 	Remove item from list
	@return 0 on success, -1 on error (ie: node is not in list)
*/
int InvList_remove(InvList *list, InvList *node);

/** @brief 	Get pointer to first node
*/
static inline InvList *InvList_head(InvList *list)
{
	ASSERT(list);

	return list->next;
}

/** @brief 	Get pointer to next node
*/
static inline InvList *InvList_next(InvList *list)
{
	ASSERT(list);

	return list->next;
}

/** @brief 	Get list emptiness status
	@param[in]  list    list to be parsed
	@return true if list is empty, false otherwise
*/
static inline inv_bool_t InvList_isEmpty(InvList *list)
{
	ASSERT(list);

	return (list->next == 0);
}

/** @brief 	Check if node is in list
	@param[in]  list    list to be parsed
	@return true if node is in list, false otherwise
*/
inv_bool_t InvList_isIn(const InvList *list, const InvList *node);

/** @brief 	Walk through entire list to return the number of element
	@param[in]  list    list to be parsed
	@return number of element in list
*/
unsigned InvList_getListCount(const InvList *list);


#ifdef __cplusplus
}
#endif

#endif 	/* _INV_LIST_H_ */

/** @} */
