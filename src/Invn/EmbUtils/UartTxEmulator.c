/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "UartTxEmulator.h"
#include "RingBuffer.h"

/** @brief Set of possible values for UARTTxEmulator current state */
enum UartTxEmulatorState {
	UARTXEMULATOR_STATE_STOPPED, /**< UART Tx emulator is currently sending nothing*/
	UARTXEMULATOR_STATE_START_BIT, /**< UART Tx emulator is currently sending start bit*/
	UARTXEMULATOR_STATE_SEND_BIT, /**< UART Tx emulator is currently sending data itself*/
	UARTXEMULATOR_STATE_STOP_BIT /**< UART Tx emulator is currently sending stop bit*/
};

static RINGBUFFER(sUartTxEmulatorFifoData, UARTTXEMULATOR_MAX_BUFFER_SIZE,
                  uint8_t);

static void UartTxEmulator_IRQTimerHandlerHook(void)
{
	static enum UartTxEmulatorState sUartTxEmulatorState =
	        UARTXEMULATOR_STATE_STOPPED; // current UART Tx emulator state
	static uint8_t lBitsToSend; // number of data bits still to be sent
	uint32_t nitem; // number of bytes to send over UART
	static uint8_t item; // byte to send over UART

	if (sUartTxEmulatorState == UARTXEMULATOR_STATE_STOPPED) {
		nitem = RINGBUFFER_SIZE(&sUartTxEmulatorFifoData);
		if (nitem != 0) {
			// in case some UART data is to be sent, pop 1 byte
			RINGBUFFER_POP(&sUartTxEmulatorFifoData, &item);
			// and start to send it right now
			sUartTxEmulatorState = UARTXEMULATOR_STATE_START_BIT;
		}
	}

	switch (sUartTxEmulatorState) {
	case UARTXEMULATOR_STATE_STOPPED:
		// nothing to do
		break;

	case UARTXEMULATOR_STATE_START_BIT:
		// start bit
		UARTTXEMULATOR_SETGPIOHOOK(0) ;
		// configuration is 8 data bits
		lBitsToSend = 8;

		// update UART TX emulator state
		sUartTxEmulatorState = UARTXEMULATOR_STATE_SEND_BIT;
		break;

	case UARTXEMULATOR_STATE_SEND_BIT:
		if (item & 0x01)
			UARTTXEMULATOR_SETGPIOHOOK(1) ;
		else
			UARTTXEMULATOR_SETGPIOHOOK(0) ;
		item = item >> 1;
		lBitsToSend--;

		// update UART TX emulator state if 8 bits where previously sent
		if (lBitsToSend == 0)
			sUartTxEmulatorState = UARTXEMULATOR_STATE_STOP_BIT;
		break;

	case UARTXEMULATOR_STATE_STOP_BIT:
		// stop bit
		UARTTXEMULATOR_SETGPIOHOOK(1) ;
		// update UART TX emulator state, end of current transaction
		sUartTxEmulatorState = UARTXEMULATOR_STATE_STOPPED;
		break;

	default:
		// error
		break;
	}
}

void UartTxEmulator_init(void)
{
	UARTTXEMULATOR_INITGPIOHOOK();
	UARTTXEMULATOR_SETGPIOHOOK(1);
	// UARTTXEMULATOR_BAUDRATE bit per second
	// so timer must be triggered every 1000000/UARTTXEMULATOR_BAUDRATE us
	UARTTXEMULATOR_INITTIMERHOOK((1000000 / UARTTXEMULATOR_BAUDRATE),
	                             UartTxEmulator_IRQTimerHandlerHook);

	RINGBUFFER_CLEAR(&sUartTxEmulatorFifoData);
}

int8_t UartTxEmulator_send(uint8_t c)
{
	uint32_t nitem = RINGBUFFER_SIZE(&sUartTxEmulatorFifoData);
	if (nitem < RINGBUFFER_MAXSIZE(&sUartTxEmulatorFifoData)) {
		const uint8_t data = c;
		RINGBUFFER_PUSH(&sUartTxEmulatorFifoData, &data);
		// data correctly pushed on UART FIFO, will be poped during next timer interrupt
		return 0;
	} else {
		// FIFO is full, return an error
		return -1;
	}
}
