/*
 * ________________________________________________________________________________________________________
 * Copyright (c) 2015-2015 InvenSense Inc. All rights reserved.
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

/** @defgroup selftestdirectmode Self-Test Direct Mode
 *  @brief High-level functions for Self-Test procedures in Direct Mode
 *  @{
 */

/** @file inv_imu_selftest_directmode.h */

#ifndef _INV_IMU_SELFTEST_DIRECTMODE_H_
#define _INV_IMU_SELFTEST_DIRECTMODE_H_

#include <stdint.h>

#include "Invn/InvExport.h"
#include "imu/inv_imu_defs.h"
#include "imu/inv_imu_driver.h"
#include "imu/inv_imu_selftest.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forward declaration */
struct inv_imu_device;

/** Self-test debug outputs */
typedef struct {
	int32_t st_off[3]; /**< Average value when ST is off */
	int32_t st_on[3]; /**< Average value when ST is on */
	int32_t st_diff[3]; /**< Difference between ST on and ST off */
	int32_t st_otp[3]; /**< OTP value to compare to */
} inv_imu_selftest_internal_state_t;

/** Self-test routine outputs */
typedef struct {
	int8_t                            accel_status; /**< global accel self-test status */
	int8_t                            gyro_status; /**< global gyro self-test status */
	int8_t                            ax_status; /**< AX self-test status */
	int8_t                            ay_status; /**< AY self-test status */
	int8_t                            az_status; /**< AZ self-test status */
	int8_t                            gx_status; /**< GX self-test status */
	int8_t                            gy_status; /**< GY self-test status */
	int8_t                            gz_status; /**< GZ self-test status */
	inv_imu_selftest_internal_state_t accel; /**< Accel internal state. For debug purpose */
	inv_imu_selftest_internal_state_t gyro; /**< Gyro internal state. For debug purpose */
} inv_imu_selftest_directmode_output_t;

/** @brief Perform hardware self-test for Accel and Gyro in direct mode.
 *  @param[in] s           Pointer to device.
 *  @param[in] st_params   Self-test parameters.
 *  @param[out] st_output  Self-test results.
 *  @return                0 on success, negative value on error.
 */
int inv_imu_run_selftest_directmode(struct inv_imu_device *               s,
                                    const inv_imu_selftest_parameters_t   st_params,
                                    inv_imu_selftest_directmode_output_t *st_output);

#ifdef __cplusplus
}
#endif

#endif /* _INV_IMU_SELFTEST_DIRECTMODE_H_ */

/** @} */
