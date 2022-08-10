/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup UartTxEmulator UartTxEmulator
	@brief UART TX Emulator facility

	This file provides UART TX emulator to add UART trace to a program with GPIO when no UART IP is available at hardware level.
	UART Tx configuration is 8N1 : 8 data bits / No parity bit / 1 stop bit
	Caller is responsible for providing hooks to handle timer and GPIO.

	@ingroup EmbUtils
    @{
*/

#ifndef _UART_TX_EMULATOR_H_
#define _UART_TX_EMULATOR_H_

#include <stdint.h>

#ifndef UARTTXEMULATOR_MAX_BUFFER_SIZE
#	define UARTTXEMULATOR_MAX_BUFFER_SIZE 128	/**< Maximum size of buffer before sending over UART, advised to have an exponent 2 value to improve modulo operation underneath */
#endif


#ifndef UARTTXEMULATOR_BAUDRATE
#	define UARTTXEMULATOR_BAUDRATE 1200	/**< Baudrate used by UART Tx emulator*/
#endif

/** @brief	Prototype of callback called by timer interrupt handler
*/
typedef void (*UartTxEmulatorTimerIrqCb)(void);

/** @brief	Initialize UART Tx emulator module and associated hardware
	@param[in]	none
	@return 	none
*/
void UartTxEmulator_init(void);

/** @brief	Initialize UART Tx emulator module and associated hardware
	@param[in]	none
	@return 	0 if byte successfully added to list of bytes to send over UART, -1 in case of any error, it is up to the application to try to send again this byte in that case
*/
int8_t UartTxEmulator_send(uint8_t c);

/** @brief	Overloadable hook to drive high or low the GPIO expected to emulate UART Tx
	@param[in]	level 		1 if GPIO must be set high, 0 if GPIO must be set low
*/
#if !defined(UARTTXEMULATOR_SETGPIOHOOK)
#define UARTTXEMULATOR_SETGPIOHOOK(level)	(void)0
#else
extern void UARTTXEMULATOR_SETGPIOHOOK(uint8_t level);
#endif

/** @brief	Overloadable hook to init the GPIO expected to emulate UART Tx
*/
#if !defined(UARTTXEMULATOR_INITGPIOHOOK)
#define UARTTXEMULATOR_INITGPIOHOOK() 	(void)0
#else
extern void UARTTXEMULATOR_INITGPIOHOOK(void);
#endif

/** @brief	Overloadable hook to init the timer dedicated to UART emulation
	@param[in]	period 		period in us at which timer interrupt handler must be called
	@param[in]	timerIrqCb 	function called in IRQ context when timer interrupt is triggered
	@note This function must also set the timer period, enable timer interrupt and start the timer
*/
#if !defined(UARTTXEMULATOR_INITTIMERHOOK)
#define UARTTXEMULATOR_INITTIMERHOOK(period,timerIrqCb)	(void)timerIrqCb
#else
extern void UARTTXEMULATOR_INITTIMERHOOK(uint32_t period,
                UartTxEmulatorTimerIrqCb timerIrqCb);
#endif

#endif

/** @} */
