/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "InvList.h"

int InvList_add(InvList *list, InvList *node)
{
	InvList *cur = list;

	ASSERT(list && node);

	while (cur->next != 0) {
		if (cur->next == node)
			return -1;

		cur = cur->next;
	}

	cur->next = node;
	node->next = 0;

	return 0;
}

int InvList_remove(InvList *list, InvList *node)
{
	InvList *cur = list;

	ASSERT(list && node);

	while (cur->next != 0) {
		if (cur->next == node) {
			cur->next = node->next;
			return 0;
		}

		cur = cur->next;
	}

	return -1;
}

inv_bool_t InvList_isIn(const InvList *list, const InvList *node)
{
	const InvList *cur = list;

	ASSERT(list && node);

	while (cur->next != 0) {
		if (cur->next == node)
			return true;

		cur = cur->next;
	}

	return false;
}

unsigned InvList_getListCount(const InvList *list)
{
	unsigned count = 0;
	const InvList *cur = list;

	ASSERT(list);

	while (cur->next != 0) {
		++count;
		cur = cur->next;
	}

	return count;
}
