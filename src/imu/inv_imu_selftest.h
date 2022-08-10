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

/** @defgroup selftest Self-Test
 *  @brief High-level functions for Self-Test procedures
 *  @{
 */

/** @file inv_imu_selftest.h */

#ifndef _INV_IMU_SELFTEST_H_
#define _INV_IMU_SELFTEST_H_

#include <stdint.h>

#include "Invn/InvExport.h"
#include "imu/inv_imu_defs.h"
#include "imu/inv_imu_driver.h"

#ifdef __cplusplus
extern "C" {
#endif

/* forward declaration */
struct inv_imu_device;

/** Self-test input parameters */
typedef struct {
	ST_CONFIG_NUM_SAMPLES_t     st_num_samples; /**< Number of samples used to perform self-test */
	SELFTEST_ACCEL_GYRO_ST_EN_t st_control; /**< Define which sensor is under self-test */
} inv_imu_selftest_parameters_t;

/** Self-test routine outputs */
typedef struct {
	int8_t accel_status; /**< global accel self-test passed */
	int8_t gyro_status; /**< global gyro self-test status: st_pass (bit0), st_incomplete (bit1) */
	int8_t ax_status; /**< AX self-test status */
	int8_t ay_status; /**< AY self-test status */
	int8_t az_status; /**< AZ self-test status */
	int8_t gx_status; /**< GX self-test status */
	int8_t gy_status; /**< GY self-test status */
	int8_t gz_status; /**< GZ self-test status */
} inv_imu_selftest_output_t;

/** @brief Execute self-test for Accel and Gyro.
 *  @param[in] s           Pointer to device.
 *  @param[in] st_params   Self-test parameters.
 *  @param[out] st_output  Self-test results.
 *  @return                0 on success, negative value on error.
 */
int inv_imu_run_selftest(struct inv_imu_device *s, const inv_imu_selftest_parameters_t st_params,
                         inv_imu_selftest_output_t *st_output);

/** @brief Fill the self-test configuration structure with default configuration.
 *  @param[in] s                Pointer to device.
 *  @param[in] selftest_params  Self-test parameters to be initialized.
 *  @return                     0 on success, negative value on error.
 */
int inv_imu_init_selftest_parameters_struct(struct inv_imu_device *        s,
                                            inv_imu_selftest_parameters_t *selftest_params);

/** @brief Load self-test data.
 *  @param[in] s  Pointer to device.
 *  @return       0 on success, negative value on error.
 */
int inv_imu_load_selftest_data(struct inv_imu_device *s);

#ifdef __cplusplus
}
#endif

#endif /* _INV_IMU_SELFTEST_H_ */

/** @} */
