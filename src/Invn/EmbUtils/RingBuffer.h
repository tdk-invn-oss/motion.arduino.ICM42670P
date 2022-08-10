/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** \defgroup RingBuffer RingBuffer
	\brief Macros to manage static circular buffer of any data type
	\ingroup EmbUtils
	\{
*/

#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <stdint.h>
#include <string.h>


/** \brief  Macro to declare a ring buffer
	\param[in] type		type of item contained in the ring buffer
	\param[in] size 	number of items that can contain the ring buffer
						To improve speed, size should be a power of 2
*/
#define RINGBUFFER_DECLARE(type, size) \
	struct {	\
		uint16_t 	read, write;	\
		type	 	buffer[size]; 	\
	}

/** \brief  Macro to declare a volatile ring buffer, i.e. modified within an interrupt context
	\param[in] type		type of item contained in the ring buffer
	\param[in] size 	number of items that can contain the ring buffer
						To improve speed, size should be a power of 2
*/
#define RINGBUFFER_VOLATILE_DECLARE(type, size) \
	struct {	\
		volatile uint16_t 	read, write;	\
		volatile type	 	buffer[size]; 	\
	}

/** \brief  Macro to declare a ring buffer
	\param[in] name 	name of the circular buffer
	\param[in] size 	number of items that can contain the ring buffer
						To improve speed, size should be a power of 2
	\param[in] type		type of item contained in the ring buffer
*/
#define RINGBUFFER(name, size, type) RINGBUFFER_DECLARE(type, size) name

/** \brief  Macro to declare a volatile ring buffer, i.e. modified within an interrupt context
	\param[in] name 	name of the circular buffer
	\param[in] size 	number of items that can contain the ring buffer
						To improve speed, size should be a power of 2
	\param[in] type		type of item contained in the ring buffer
*/
#define RINGBUFFER_VOLATILE(name, size, type) RINGBUFFER_VOLATILE_DECLARE(type, size) name

/** \brief  Macro to get maximum size of a ring buffer
	\param[in] rb 		pointer to the ring buffer
	\return  	maximum number of items that can contain the ringbuffer
*/
#define RINGBUFFER_MAXSIZE(rb)		(sizeof((rb)->buffer)/sizeof((rb)->buffer[0]))

/** \brief  Macro to get maximum size of a volatile ring buffer, i.e. modified within an interrupt context
	\param[in] rb 		pointer to the ring buffer
	\return  	maximum number of items that can contain the ringbuffer
*/
#define RINGBUFFER_VOLATILE_MAXSIZE(rb)		RINGBUFFER_MAXSIZE(rb)

/** \brief   Macro to get current size of a ring buffer
	\param[in] rb 		pointer to the ring buffer
	\return  	current number of items hold in the ringbuffer
*/
#define RINGBUFFER_SIZE(rb) 		((uint16_t)((rb)->write - (rb)->read))

static inline uint16_t get_ringbuffer_volatile_size(void * rb)
{
	struct { uint16_t read, write; } rb_var;
	memcpy(&rb_var, rb, sizeof(rb_var));
	return (rb_var.write - rb_var.read);
}

/** \brief   Macro to get current size of a volatile ring buffer, i.e. modified within an interrupt context
	\param[in] rb 		pointer to the ring buffer
	\return  	current number of items hold in the ringbuffer
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_SIZE(rb)	get_ringbuffer_volatile_size(rb)

/** \brief   Macro to check if a ring buffer is full
	\param[in] rb 		pointer to the ring buffer
	\return  	1 if there is no slot left in the ring buffer, 0 otherwise
*/
#define RINGBUFFER_FULL(rb) 		(RINGBUFFER_SIZE(rb) == RINGBUFFER_MAXSIZE(rb))

/** \brief   Macro to check if a volatile ring buffer, i.e. modified within an interrupt context, is full
	\param[in] rb 		pointer to the ring buffer
	\return  	1 if there is no slot left in the ring buffer, 0 otherwise
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_FULL(rb) 		(RINGBUFFER_VOLATILE_SIZE(rb) == RINGBUFFER_VOLATILE_MAXSIZE(rb))

/** \brief   Macro to check if a ring buffer is empty
	\param[in] rb 		pointer to the ring buffer
	\return  	1 if there is no item in the ring buffer, 0 otherwise
*/
#define RINGBUFFER_EMPTY(rb) 		(RINGBUFFER_SIZE(rb) == 0)

/** \brief   Macro to check if a volatile ring buffer, i.e. modified within an interrupt context, is empty
	\param[in] rb 		pointer to the ring buffer
	\return  	1 if there is no item in the ring buffer, 0 otherwise
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_EMPTY(rb) 		(RINGBUFFER_VOLATILE_SIZE(rb) == 0)

/** \brief   Macro to get number of available slot in a ring buffer
	\param[in] rb 		pointer to the ring buffer
	\return  	number of empty slot in the ring buffer
*/
#define RINGBUFFER_AVAILABLE(rb) 	(RINGBUFFER_MAXSIZE(rb) - RINGBUFFER_SIZE(rb))

/** \brief   Macro to get number of available slot in a volatile ring buffer, i.e. modified within an interrupt context
	\param[in] rb 		pointer to the ring buffer
	\return  	number of empty slot in the ring buffer
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_AVAILABLE(rb) 	(RINGBUFFER_VOLATILE_MAXSIZE(rb) - RINGBUFFER_VOLATILE_SIZE(rb))

/** \brief   Macro to clear a ring buffer
	\param[in] rb 		pointer to the ring buffer
*/
#define RINGBUFFER_CLEAR(rb)	\
	do {	\
		(rb)->read = 0, (rb)->write = 0;	\
	} while(0)
		
/** \brief   Macro to clear a volatile ring buffer, i.e. modified within an interrupt context
	\param[in] rb 		pointer to the ring buffer
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_CLEAR(rb)	RINGBUFFER_CLEAR(rb)

/** \brief   Push item by reference
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	to available item slot
	\warning There is no error checking done.
*/
#define RINGBUFFER_PUSHREF(rb, refData) \
	do { \
		refData = &(rb)->buffer[(rb)->write % RINGBUFFER_MAXSIZE(rb)];	\
		++(rb)->write;	\
	} while(0)

/** \brief   Push item by reference
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	to available item slot
	\warning There is no error checking done.
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_PUSHREF(rb, refData) \
	do { \
		uint16_t wr_ptr = (rb)->write; \
		refData = &(rb)->buffer[wr_ptr % RINGBUFFER_VOLATILE_MAXSIZE(rb)];	\
		++(rb)->write;	\
	} while(0)

/** \brief  Return reference to next available slot
			No push is performed
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	to available item slot
	\warning There is no error checking done.
*/
#define RINGBUFFER_GETREFNEXT(rb, refData) \
	do { \
		refData = &(rb)->buffer[(rb)->write % RINGBUFFER_MAXSIZE(rb)];	\
	} while(0)

/** \brief  Return reference to next available slot
			No push is performed
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	to available item slot
	\warning There is no error checking done.
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_GETREFNEXT(rb, refData) \
	do { \
		uint16_t wr_ptr = (rb)->write; \
		refData = &(rb)->buffer[wr_ptr % RINGBUFFER_VOLATILE_MAXSIZE(rb)];	\
	} while(0)

/** \brief  Increment write counter
			Actually performed a push (assuming data were already copied)
	\param[in] rb 			pointer to the ring buffer
	\warning There is no error checking done.
*/
#define RINGBUFFER_INCREMENT(rb, refData) \
	do { \
		++(rb)->write;	\
	} while(0)
		
/** \brief  Increment write counter
			Actually performed a push (assuming data were already copied)
	\param[in] rb 			pointer to the ring buffer
	\warning There is no error checking done.
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_INCREMENT(rb, refData) \
	do { \
		++(rb)->write;	\
	} while(0)

/** \brief   Return reference to youngest item
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	reference to yougiest item
	\warning There is no error checking done.
*/
#define RINGBUFFER_BACK(rb, refData) \
	do { \
		refData = &(rb)->buffer[((rb)->write-1) % RINGBUFFER_MAXSIZE(rb)];	\
	} while(0)

/** \brief   Return reference to youngest item
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	reference to yougiest item
	\warning There is no error checking done.
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_BACK(rb, refData) \
	do { \
		uint16_t wr_ptr = (rb)->write; \
		refData = &(rb)->buffer[(wr_ptr-1) % RINGBUFFER_VOLATILE_MAXSIZE(rb)];	\
	} while(0)

/** \brief   Macro to push an item to a ring buffer
	\param[in] rb 		pointer to the ring buffer
	\param[in] ptrData 	pointer to the item to push.
	\warning There is no error checking done.
	You must check for fullness before pushing data
*/
#define RINGBUFFER_PUSH(rb, ptrData)	\
	do {	\
		(rb)->buffer[(rb)->write % RINGBUFFER_MAXSIZE(rb)] = *ptrData;	\
		++(rb)->write;	\
	} while(0)

/** \brief   Macro to push an item to a volatile ring buffer
	\param[in] rb 		pointer to the ring buffer
	\param[in] ptrData 	pointer to the item to push.
	\warning There is no error checking done.
	You must check for fullness before pushing data
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_PUSH(rb, ptrData)	\
	do {	\
		uint16_t wr_ptr = (rb)->write; \
		(rb)->buffer[wr_ptr % RINGBUFFER_VOLATILE_MAXSIZE(rb)] = *ptrData;	\
		++(rb)->write;	\
	} while(0)

/** \brief   Macro to unpush an item to a ring buffer
	\param[in] rb 		pointer to the ring buffer
	\param[in] ptrData 	pointer to placeholder to hold unpushed item
	\warning There is no error checking done.
	You must check for emptyness before pushing data
*/
#define RINGBUFFER_UNPUSH(rb, ptrData)	\
	do {	\
		--(rb)->write;	\
		*ptrData = (rb)->buffer[(rb)->write % RINGBUFFER_MAXSIZE(rb)];	\
	} while(0)

/** \brief   Macro to unpush an item to a volatile ring buffer
	\param[in] rb 		pointer to the ring buffer
	\param[in] ptrData 	pointer to placeholder to hold unpushed item
	\warning There is no error checking done.
	You must check for emptyness before pushing data
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_UNPUSH(rb, ptrData)	\
	do {	\
		--(rb)->write;	\
		uint16_t wr_ptr = (rb)->write; \
		*ptrData = (rb)->buffer[wr_ptr % RINGBUFFER_VOLATILE_MAXSIZE(rb)];	\
	} while(0)

/** \brief   Return reference to oldiest item
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	reference to oldeist item
	\warning There is no error checking done.
*/
#define RINGBUFFER_FRONT(rb, refData) \
	do { \
		refData = &(rb)->buffer[(rb)->read % RINGBUFFER_MAXSIZE(rb)];	\
	} while(0)

/** \brief   Return reference to oldiest item
	\param[in] rb 			pointer to the ring buffer
	\param[out] refData 	reference to oldeist item
	\warning There is no error checking done.
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_FRONT(rb, refData) \
	do { \
		uint16_t rd_ptr = (rb)->read; \
		refData = &(rb)->buffer[rd_ptr % RINGBUFFER_VOLATILE_MAXSIZE(rb)];	\
	} while(0)

/** \brief   Macro to pop an item from a ring buffer
	\param[in] rb 			pointer to the ring buffer
	\param[out] ptrData 	pointer to placeholder to hold poped item
	\warning There is no error checking done.
	You must check for emptyness before poping data
*/
#define RINGBUFFER_POP(rb, ptrData) \
	do { \
		*ptrData = (rb)->buffer[(rb)->read % RINGBUFFER_MAXSIZE(rb)];	\
		++(rb)->read;	\
	} while(0)

/** \brief   Macro to pop an item from a volatile ring buffer
	\param[in] rb 			pointer to the ring buffer
	\param[out] ptrData 	pointer to placeholder to hold poped item
	\warning There is no error checking done.
	You must check for emptyness before poping data
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_POP(rb, ptrData) \
	do { \
		uint16_t rd_ptr = (rb)->read; \
		*ptrData = (rb)->buffer[rd_ptr % RINGBUFFER_VOLATILE_MAXSIZE(rb)];	\
		++(rb)->read;	\
	} while(0)

/** \brief   Macro to pop an item from a ring buffer (data is not copied)
	\param[in] rb 			pointer to the ring buffer
	\warning There is no error checking done.
	You must check for emptyness before poping data
*/
#define RINGBUFFER_POPNLOSE(rb) \
	do { \
		++(rb)->read;	\
	} while(0)

/** \brief   Macro to pop an item from a volatile ring buffer (data is not copied)
	\param[in] rb 			pointer to the ring buffer
	\warning There is no error checking done.
	You must check for emptyness before poping data
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_POPNLOSE(rb) \
	do { \
		++(rb)->read;	\
	} while(0)

/** \brief   Macro to unpop an item to a ring buffer
	\param[in] rb 			pointer to the ring buffer
	\param[out] ptrData 	pointer to to the item to unpop.
	\warning There is no error checking done.
	You must check for fullness before unpoping data
*/
#define RINGBUFFER_UNPOP(rb, ptrData) \
	do { \
		--(rb)->read;	\
		(rb)->buffer[(rb)->read % RINGBUFFER_MAXSIZE(rb)] = *ptrData;	\
	} while(0)

/** \brief   Macro to unpop an item to a volatile ring buffer
	\param[in] rb 			pointer to the ring buffer
	\param[out] ptrData 	pointer to to the item to unpop.
	\warning There is no error checking done.
	You must check for fullness before unpoping data
	\warning it is advised to put this in a critical section
*/
#define RINGBUFFER_VOLATILE_UNPOP(rb, ptrData) \
	do { \
		--(rb)->read;	\
		uint16_t rd_ptr = (rb)->read; \
		(rb)->buffer[rd_ptr % RINGBUFFER_VOLATILE_MAXSIZE(rb)] = *ptrData;	\
	} while(0)

#endif

/** \} */
