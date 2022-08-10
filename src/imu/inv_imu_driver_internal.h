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

/** @defgroup DriverInternal Driver Internal
 *  @brief Internal high-level functions to drive the device.
 *  @{
 */

/** @file inv_imu_driver_internal.h */

#ifndef _INV_IMU_DRIVER_INTERNAL_H_
#define _INV_IMU_DRIVER_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "imu/inv_imu_defs.h"
#include "imu/inv_imu_defs_internal.h"
#include "imu/inv_imu_driver.h"

#include "Invn/InvError.h"

#include <stdint.h>
#include <string.h>

typedef struct {
	uint8_t gyro_ui_filt_ord_ind;
	uint8_t accel_ui_filt_ord_ind;
	uint8_t nospur_mode;
} inv_imu_chip_config_t;

typedef struct {
	uint8_t  manu_id;
	uint8_t  chip_id;
	uint8_t  rev_id;
	uint16_t die_id;
	uint8_t  wafer_id;
	uint8_t  die_rev;
} inv_imu_manufacturing_info_t;

int inv_imu_read_chip_config(struct inv_imu_device *s, inv_imu_chip_config_t *cfg);

/** @brief Read the manufacturing info and fill the 'info' structure.
 *  @param[in] s     Pointer to device.
 *  @param[in] info  Strucutre filled up with manufacturing info.
 *  @return          0 on success, negative value on error.
 *  @warning To guarantee the reliability of the values, SPI frequency should be 5MHz or less
 */
int inv_read_manufacturing_info(struct inv_imu_device *s, inv_imu_manufacturing_info_t *info);

/** @brief Enable/put gyro in low power mode
 *  @return 0 on success, negative value on error.
 *  @details
 *  It enables gyro and accel data in the FIFO (so
 *  the packet format is 16 bytes). If called first,
 *  the configuration will be applied, otherwise it
 *  will be ignored if the FIFO is not empty (but since
 *  the new configuration is identical it is not a issue).
 *  @warning inv_device::register_cache::pwr_mgmt0_reg is modified by this function
 */
int inv_imu_enable_gyro_low_power_mode(struct inv_imu_device *s);

/** @brief Set gyro Low-Power averaging value
 *  @param[in] gyr_avg requested averaging value
 *  @sa GYRO_CONFIG1_GYRO_FILT_AVG_t
 *  @return 0 on success, negative value on error.
 */
int inv_imu_set_gyro_lp_avg(struct inv_imu_device *s, GYRO_CONFIG1_GYRO_FILT_AVG_t gyr_avg);

/** @brief  Copy 'size' bytes fom DMP RAM at offset given in parameters to address pointed by 'data'.
 *  @param[in] data location where read data should be stored
 *  @param[in] offset offset in bytes from RAM start address where data should be read
 *  @param[in] size number of bytes to read
 *  @return 0 in case of success, negative value on error. See enum inv_error
 */
int inv_imu_read_dmp_ram(struct inv_imu_device *self, uint8_t *data, uint32_t offset,
                         uint32_t size);

/** @brief  Write 'size' bytes pointed by 'data' in DMP RAM at offset given in parameters.
 *  @param[in] data pointer to data to be stored in RAM
 *  @param[in] offset offset in bytes from RAM start address where data should be written
 *  @param[in] size number of bytes to write
 *  @return 0 in case of success, negative value on error. See enum inv_error
 */
int inv_imu_write_dmp_ram(struct inv_imu_device *self, const uint8_t *data, uint32_t offset,
                          uint32_t size);

/** @brief  Check DMP ROM with data pointed by input pointer.
 *  @param[in] data source data address to be compared to ROM
 *  @param[in] size number of bytes to be compared
 *  @return 0 in case of success, negative value on error. See enum inv_error
 */
int inv_imu_check_dmp_rom(struct inv_imu_device *self, uint8_t *data, uint32_t size);


#ifdef __cplusplus
}
#endif

#endif /* _INV_IMU_DRIVER_INTERNAL_H_ */

/** @} */
