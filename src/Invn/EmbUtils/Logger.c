/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "Logger.h"
#include "InvFormat.h"
#include "InvAssert.h"
#include "RingByteBuffer.h"

static uint8_t            sLoggerLevel    = LOG_LEVEL;
static volatile uint8_t * sLoggerLevelRef = &sLoggerLevel;

void Logger_setLevel(uint8_t level)
{
	*sLoggerLevelRef = level;
}

void Logger_setLevelRef(volatile uint8_t * plevel)
{
	if(!plevel) {
		sLoggerLevelRef = &sLoggerLevel;
	} else {
		sLoggerLevelRef = plevel;
	}
}


void Logger_log(const char *label, unsigned level, const char *msg, unsigned len)
{
	if(level && level <= *sLoggerLevelRef) {
		unsigned i;
		for(i = 0; i < len; ++i) {
			LOGGER_PUTCHARHOOK(msg[i]);
		}
	}

	(void)label;
}

void Logger_logf(const char *label, unsigned level, const char *msg, ...)
{
	if(level && level <= *sLoggerLevelRef) {
		static const char level_label[LOG_LEVEL_MAX] = {
			'\0', 'P', 'E', 'W', 'N', 'I', 'V', 'D', 'T'
		};

		if(level < sizeof(level_label)) {
			LOGGER_PUTCHARHOOK('[');
			LOGGER_PUTCHARHOOK(level_label[level]);
			LOGGER_PUTCHARHOOK(']');
		}

		if(label) {
			const char *pc = label;
			while(*pc != '\0') {
				LOGGER_PUTCHARHOOK(*pc);
				++pc;
			}
			LOGGER_PUTCHARHOOK(':');
		}

		LOGGER_PUTCHARHOOK(' ');

		if(msg) {
			va_list ap;
			va_start(ap, msg);
			LOGGER_VPRINTFHOOK(msg, ap);
			va_end(ap);
		}

		LOGGER_PUTCHARHOOK('\r');
		LOGGER_PUTCHARHOOK('\n');
	}
}

