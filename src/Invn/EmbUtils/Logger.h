/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup Logger Logger
	@brief Logger macros facility

	This file provides LOG macros to add trace to a programm. Trace can be disable by either module or level, depending on define.
	Caller is responsible for providing hooks to formating and writing function.
	This Logger provides optional capability to store log message in a ring buffer.

	@ingroup EmbUtils
    @{
*/

#ifndef _LOGGER_H_
#define _LOGGER_H_

#define LOG_LEVEL_DISABLE   0 /**< Sentinel level for Logger  */
#define LOG_LEVEL_PANIC     1 /**< Panic level for Logger  */
#define LOG_LEVEL_ERROR     2 /**< Error level for Logger  */
#define LOG_LEVEL_WARNING   3 /**< Warning level for Logger  */
#define LOG_LEVEL_NOTICE    4 /**< Notice level for Logger  */
#define LOG_LEVEL_INFO      5 /**<, Info level for Logger  */
#define LOG_LEVEL_VERBOSE   6 /**< Verbose level for Logger  */
#define LOG_LEVEL_DEBUG     7 /**< Debug level for Logger  */
#define LOG_LEVEL_TIMESTAMP 8 /**< Timestamp output for Logger */
#define LOG_LEVEL_MAX       9 /**< Sentinel value */

#define LOG_LEVEL_ALL       (LOG_LEVEL_MAX - 1)

#if !defined(LOG_LEVEL)
	#define LOG_LEVEL LOG_LEVEL_DISABLE
#elif LOG_LEVEL < LOG_LEVEL_DISABLE || LOG_LEVEL >= LOG_LEVEL_MAX
	#undef  LOG_LEVEL
	#define LOG_LEVEL LOG_LEVEL_DISABLE
#endif

#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

/** @brief	Set Logger level
	Message with a level higher to the current level will be discarded
*/
void Logger_setLevel(uint8_t level);

/** @brief	Set Logger level reference
	Allow to set location of where logger level is stored.
	This is useful if level must be modified outside the programm (by HW)
*/
void Logger_setLevelRef(volatile uint8_t * plevel);

/** @brief	Log a message
	@param[in]	label 		label of the message
	@param[in]	level 		level of the message
	@param[in]	msg 		description of the message
	@param[in]	len 		len of the message description
	@return 	none
*/
void Logger_log(const char *label, unsigned level, const char *msg, unsigned len);

/** @brief	Log a formated message
	@param[in]	label 		label of the message
	@param[in]	level 		level of the message
	@param[in]	msg 		format string of the message
	@param[in]	len 		message argument
	@return 	none
*/
void Logger_logf(const char *label, unsigned level, const char *msg, ...);

/** @brief	Overloadable hook to vprintf method
*/
#if !defined(LOGGER_VPRINTFHOOK)
#define LOGGER_VPRINTFHOOK vprintf
#else
extern int LOGGER_VPRINTFHOOK(const char *format, va_list ap);
#endif

/** @brief	Overloadable hook to putchar method
*/
#if !defined(LOGGER_PUTCHARHOOK)
#define LOGGER_PUTCHARHOOK putchar
#else
extern int LOGGER_PUTCHARHOOK(int c);
#endif

#if !defined(STRINGIFY)
#define STRINGIFY(s) #s
#endif

#if !defined(TOSTRING)
#define TOSTRING(s) STRINGIFY(s)
#endif

#if defined(LOG_LABEL_ENABLE)
#define LOG_LABEL_ENABLE_CMP(label) (strstr(":" TOSTRING(LOG_LABEL_ENABLE) ":", ":" label ":") != NULL)
#else
#define LOG_LABEL_ENABLE_CMP(label) (1)
#endif

#if defined(LOG_LABEL_DISABLE)
#define LOG_LABEL_DISABLE_CMP(label) (strstr(":"TOSTRING(LOG_LABEL_DISABLE)":", ":" label ":") != NULL)
#else
#define LOG_LABEL_DISABLE_CMP(label) (0)
#endif

#if LOG_LEVEL != LOG_LEVEL_DISABLE

/** @brief	Helper macro to log a formated message
*/
#define LOG(label, level, msg, ...)	\
		do { \
			if(level != LOG_LEVEL_DISABLE && level <= LOG_LEVEL && LOG_LABEL_ENABLE_CMP(label) && !LOG_LABEL_DISABLE_CMP(label)) { \
				Logger_logf(label, level, msg, ##__VA_ARGS__); \
			} \
		} while(0)

/** @brief	Helper macro to log an unformated message
*/
#define LOG_RAW(label, level, buf, size) \
		do { \
			if(level != LOG_LEVEL_DISABLE && level <= LOG_LEVEL && LOG_LABEL_ENABLE_CMP(label) && !LOG_LABEL_DISABLE_CMP(label)) { \
				Logger_log(0, level, buf, size); \
			} \
		} while(0)

/** @brief	Helper macro to log an unformated nul-terminated string
*/
#define LOG_STR(label, level, str) \
		do { \
			if(level != LOG_LEVEL_DISABLE && level <= LOG_LEVEL && LOG_LABEL_ENABLE_CMP(label) && !LOG_LABEL_DISABLE_CMP(label)) { \
				Logger_log(0, level, str, strlen(str)); \
			} \
		} while(0)

#else
#define LOG(label, level, ...)				((void)0)
#define LOG_RAW(label, level, buf, size)	((void)0)
#define LOG_STR(label, level, str)			((void)0)
#endif

#endif

/** @} */
