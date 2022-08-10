/*
 * ________________________________________________________________________________________________________
 * Copyright (c) 2017 InvenSense Inc. All rights reserved.
 *
 * This software, related documentation and any modifications thereto (collectively "Software") is subject
 * to InvenSense and its licensors' intellectual property rights under U.S. and international copyright
 * and other intellectual property rights laws.
 *
 * InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
 * and any use, reproduction, disclosure or distribution of the Software without an express license agreement
 * from InvenSense is strictly prohibited.
 *
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, IN NO EVENT SHALL
 * INVENSENSE BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THE SOFTWARE.
 * ________________________________________________________________________________________________________
 */

#ifndef _INV_IMU_DEFS_INTERNAL_H_
#define _INV_IMU_DEFS_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file inv_imu_defs_internal.h
 * File exposing the device register map
 */

#include <stdint.h>

/* forward declaration */
struct inv_imu_device;

#include "imu/inv_imu_defs.h"

#include "imu/inv_imu_regmap_internal.h"

/* ----------------------------------------------------------------------------
 * Device registers description
 *
 * Next section defines some of the registers bitfield and declare corresponding
 * accessors.
 * Note that descriptors and accessors are not provided for all the registers 
 * but only for the most useful ones.
 * For all details on registers and bitfields functionalities please refer to 
 * the device datasheet.
 * ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
 * BANK0
 * ---------------------------------------------------------------------------- */

/*
 * GYRO_CONFIG1
 * Register Name: GYRO_CONFIG1
 */

/* GYRO_UI_AVG_IND */
typedef enum {
	GYRO_CONFIG1_GYRO_FILT_AVG_64 = (0x05 << GYRO_CONFIG1_GYRO_UI_AVG_IND_POS),
	GYRO_CONFIG1_GYRO_FILT_AVG_32 = (0x04 << GYRO_CONFIG1_GYRO_UI_AVG_IND_POS),
	GYRO_CONFIG1_GYRO_FILT_AVG_16 = (0x03 << GYRO_CONFIG1_GYRO_UI_AVG_IND_POS),
	GYRO_CONFIG1_GYRO_FILT_AVG_8  = (0x02 << GYRO_CONFIG1_GYRO_UI_AVG_IND_POS),
	GYRO_CONFIG1_GYRO_FILT_AVG_4  = (0x01 << GYRO_CONFIG1_GYRO_UI_AVG_IND_POS),
	GYRO_CONFIG1_GYRO_FILT_AVG_2  = (0x00 << GYRO_CONFIG1_GYRO_UI_AVG_IND_POS),
} GYRO_CONFIG1_GYRO_FILT_AVG_t;

/*
 * INTF_CONFIG0
 * Register Name: INTF_CONFIG0
 */

/* FIFO_SREG_INVALID_IND */
typedef enum {
	INTF_CONFIG0_FIFO_SREG_INVALID_IND_DIS = (0x01 << INTF_CONFIG0_FIFO_SREG_INVALID_IND_DIS_POS),
	INTF_CONFIG0_FIFO_SREG_INVALID_IND_EN  = (0x00 << INTF_CONFIG0_FIFO_SREG_INVALID_IND_DIS_POS),
} INTF_CONFIG0_FIFO_SREG_INVALID_IND_t;

/* UI_SIFS_CFG */
typedef enum {
	INTF_CONFIG0_UI_SIFS_CFG_DIS_I2C = (0x03 << INTF_CONFIG0_SIFS_AP_CFG_POS),
	INTF_CONFIG0_UI_SIFS_CFG_DIS_SPI = (0x02 << INTF_CONFIG0_SIFS_AP_CFG_POS),
} INTF_CONFIG0_UI_SIFS_CFG_t;

/* ----------------------------------------------------------------------------
 * MREG_TOP1
 * ---------------------------------------------------------------------------- */

/*
 * INT_CONFIG1_MREG_TOP1
 * Register Name: INT_CONFIG1
 */

/* INT_ASYNC_RESET */
typedef enum {
	INT_CONFIG1_INT_ASYNC_RESET_DIS = (0x1 << INT_CONFIG1_INT_ASYNC_RESET_POS),
	INT_CONFIG1_INT_ASYNC_RESET_EN  = (0x0 << INT_CONFIG1_INT_ASYNC_RESET_POS),
} INT_CONFIG1_INT_ASYNC_RESET_t;

/*
 * ST_CONFIG_MREG1
 * Register Name: ST_CONFIG
 */

/* ACCEL_ST_LIM */
typedef enum {
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_5  = (0 << ST_CONFIG_ACCEL_ST_LIM_POS),
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_10 = (1 << ST_CONFIG_ACCEL_ST_LIM_POS),
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_15 = (2 << ST_CONFIG_ACCEL_ST_LIM_POS),
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_20 = (3 << ST_CONFIG_ACCEL_ST_LIM_POS),
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_25 = (4 << ST_CONFIG_ACCEL_ST_LIM_POS),
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_30 = (5 << ST_CONFIG_ACCEL_ST_LIM_POS),
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_40 = (6 << ST_CONFIG_ACCEL_ST_LIM_POS),
	ST_CONFIG_ACCEL_ST_LIM_INTERNAL_50 = (7 << ST_CONFIG_ACCEL_ST_LIM_POS),
} ST_CONFIG_ACCEL_ST_LIM_INTERNAL_t;

/* GYRO_ST_LIM */
typedef enum {
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_5  = (0 << ST_CONFIG_GYRO_ST_LIM_POS),
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_10 = (1 << ST_CONFIG_GYRO_ST_LIM_POS),
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_15 = (2 << ST_CONFIG_GYRO_ST_LIM_POS),
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_20 = (3 << ST_CONFIG_GYRO_ST_LIM_POS),
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_25 = (4 << ST_CONFIG_GYRO_ST_LIM_POS),
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_30 = (5 << ST_CONFIG_GYRO_ST_LIM_POS),
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_40 = (6 << ST_CONFIG_GYRO_ST_LIM_POS),
	ST_CONFIG_GYRO_ST_LIM_INTERNAL_50 = (7 << ST_CONFIG_GYRO_ST_LIM_POS),
} ST_CONFIG_GYRO_ST_LIM_INTERNAL_t;

/*
 * OTP_CTRL7_MREG_OTP
 * Register Name: OTP_CTRL7
 */

/* OTP_LOW_PWR_MODE */
typedef enum {
	OTP_CTRL7_OTP_LPM_EN  = (1 << OTP_CTRL7_OTP_LOW_PWR_MODE_POS),
	OTP_CTRL7_OTP_LPM_DIS = (0 << OTP_CTRL7_OTP_LOW_PWR_MODE_POS),
} OTP_CTRL7_OTP_LPM_t;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _INV_IMU_DEFS_INTERNAL_H_ */
