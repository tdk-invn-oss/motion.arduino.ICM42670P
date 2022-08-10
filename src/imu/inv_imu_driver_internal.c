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

#include "imu/inv_imu_driver_internal.h"
#include "imu/inv_imu_extfunc.h"

int inv_imu_read_chip_config(struct inv_imu_device *s, inv_imu_chip_config_t *cfg)
{
	int status = 0;

	status |= inv_imu_read_reg(s, GYRO_CONFIG1, 1, &cfg->gyro_ui_filt_ord_ind);
	cfg->gyro_ui_filt_ord_ind &= GYRO_CONFIG1_GYRO_UI_FILT_BW_MASK;
	status |= inv_imu_read_reg(s, ACCEL_CONFIG1, 1, &cfg->accel_ui_filt_ord_ind);
	cfg->accel_ui_filt_ord_ind &= ACCEL_CONFIG1_ACCEL_UI_FILT_BW_MASK;

	cfg->gyro_ui_filt_ord_ind >>= GYRO_CONFIG1_GYRO_UI_FILT_BW_POS;
	cfg->accel_ui_filt_ord_ind >>= ACCEL_CONFIG1_ACCEL_UI_FILT_BW_POS;

	return status;
}

int inv_read_manufacturing_info(struct inv_imu_device *s, 
                                inv_imu_manufacturing_info_t *info)
{
	int status = 0;
	uint8_t data;
	uint8_t otp[11] = {0xAA};

	status |= inv_imu_switch_on_mclk(s);

	/* Power-up OTP */
	status |= inv_imu_read_reg(s, OTP_CTRL7_MREG2, 1, &data);
	data &= ~OTP_CTRL7_OTP_PWR_DOWN_MASK;
	data |= OTP_CTRL7_PWR_DOWN_DIS;
	status |= inv_imu_write_reg(s, OTP_CTRL7_MREG2, 1, &data);
	inv_imu_sleep_us(300);

	/* Read manufacturing info */
	status |= inv_imu_read_reg(s, 0x23EE /* OTPBLK0 */, 11, otp);

	/* Power-down OTP */
	data &= ~OTP_CTRL7_OTP_PWR_DOWN_MASK;
	data |= OTP_CTRL7_PWR_DOWN_EN;
	status |= inv_imu_write_reg(s, OTP_CTRL7_MREG2, 1, &data);

	status |= inv_imu_switch_off_mclk(s);

	// Update info fields
	info->manu_id  = otp[0];
	info->chip_id  = otp[1];
	info->rev_id   = otp[2];
	info->die_id   = otp[3] | ((otp[4] & 0x7F) << 8);
	info->wafer_id = (otp[9]>>4) | ((otp[10] & 0x01 )<<4);
	info->die_rev  = (otp[10] & 0xFC) >> 2;

	return status;
}

static int select_rcosc(struct inv_imu_device *s)
{
	int     status = 0;
	uint8_t data;

	status |= inv_imu_read_reg(s, PWR_MGMT0, 1, &data);
	data &= ~PWR_MGMT0_ACCEL_LP_CLK_SEL_MASK;
	data |= PWR_MGMT0_ACCEL_LP_CLK_RCOSC;
	status |= inv_imu_write_reg(s, PWR_MGMT0, 1, &data);

	return status;
}

int inv_imu_enable_gyro_low_power_mode(struct inv_imu_device *s)
{
	int                    status = 0;
	PWR_MGMT0_ACCEL_MODE_t accel_mode;
	PWR_MGMT0_GYRO_MODE_t  gyro_mode;
	ACCEL_CONFIG0_ODR_t    acc_odr_bitfield;
	uint32_t               accel_odr_us;
	uint8_t                pwr_mgmt0_reg;
	uint8_t                accel_config0_reg;

	status |= inv_imu_read_reg(s, PWR_MGMT0, 1, &pwr_mgmt0_reg);
	accel_mode = (PWR_MGMT0_ACCEL_MODE_t)(pwr_mgmt0_reg & PWR_MGMT0_ACCEL_MODE_MASK);
	gyro_mode  = (PWR_MGMT0_GYRO_MODE_t)(pwr_mgmt0_reg & PWR_MGMT0_GYRO_MODE_MASK);
	// Check if the accelerometer is the only one enabled
	if ((accel_mode == PWR_MGMT0_ACCEL_MODE_LP) &&
	    ((gyro_mode == PWR_MGMT0_GYRO_MODE_OFF) || (gyro_mode == PWR_MGMT0_GYRO_MODE_STANDBY))) {
		// Get accelerometer's ODR for next required wait
		status |= inv_imu_read_reg(s, ACCEL_CONFIG0, 1, &accel_config0_reg);
		acc_odr_bitfield = (ACCEL_CONFIG0_ODR_t)(accel_config0_reg & ACCEL_CONFIG0_ACCEL_ODR_MASK);
		accel_odr_us     = inv_imu_convert_odr_bitfield_to_us(acc_odr_bitfield);
		// Select the RC OSC as clock source for the accelerometer
		status |= select_rcosc(s);
		// Wait one accel ODR before enabling the gyroscope
		inv_imu_sleep_us(accel_odr_us);
	}

	// Enable/Switch the gyroscope in/to low power mode
	status |= inv_imu_read_reg(
	    s, PWR_MGMT0, 1, &pwr_mgmt0_reg); // Read a new time because select_rcosc() modified it
	pwr_mgmt0_reg &= ~PWR_MGMT0_GYRO_MODE_MASK;
	pwr_mgmt0_reg |= PWR_MGMT0_GYRO_MODE_LP;
	status |= inv_imu_write_reg(s, PWR_MGMT0, 1, &pwr_mgmt0_reg);
	inv_imu_sleep_us(200);

	if (gyro_mode == PWR_MGMT0_GYRO_MODE_OFF) {
		/* First data are wrong after gyro enable using IIR filter
		 There is no signal that says Gyro start-up has completed and data are stable using FIR filter
		 and the Gyro max start-up time is 40ms
		 So keep track of the time at start-up to discard the invalid data, about 60ms after enable 
		*/
		if (s->fifo_is_used)
			s->gyro_start_time_us = inv_imu_get_time_us();
	}

	return status;
}

int inv_imu_set_gyro_lp_avg(struct inv_imu_device *s, GYRO_CONFIG1_GYRO_FILT_AVG_t gyr_avg)
{
	uint8_t value;
	int     status = 0;

	status |= inv_imu_read_reg(s, GYRO_CONFIG1, 1, &value);
	if (status)
		return status;

	value &= ~GYRO_CONFIG1_GYRO_UI_AVG_IND_MASK;
	value |= gyr_avg;

	status |= inv_imu_write_reg(s, GYRO_CONFIG1, 1, &value);
	return status;
}

int inv_imu_read_dmp_ram(struct inv_imu_device *self, uint8_t *data, uint32_t offset, uint32_t size)
{
	uint8_t  memory_bank = 0x50;
	uint8_t  dmp_memory_address;
	uint32_t i;

	if (size + offset > 1280U)
		return INV_ERROR_SIZE;

	/* make sure mclk is on */
	inv_imu_switch_on_mclk(self);

	memory_bank += (offset / 256);
	dmp_memory_address = offset % 256;
	inv_imu_write_reg(self, BLK_SEL_R, 1, &memory_bank);
	inv_imu_sleep_us(4); /* wait 16 MCLK (4MHz) clock cycles */
	inv_imu_write_reg(self, MADDR_R, 1, &dmp_memory_address);
	inv_imu_sleep_us(4); /* wait 16 MCLK (4MHz) clock cycles */

	for (i = offset; i < size + offset; i++) {
		if (0 == (i % 256)) {
			memory_bank        = 0x50 + (i / 256);
			dmp_memory_address = 0;
			inv_imu_write_reg(self, BLK_SEL_R, 1, &memory_bank);
			inv_imu_write_reg(self, MADDR_R, 1, &dmp_memory_address);
			inv_imu_sleep_us(4);
		}

		inv_imu_read_reg(self, M_R, 1, &data[i - offset]);
		inv_imu_sleep_us(4);
	}

	memory_bank = 0;
	inv_imu_write_reg(self, BLK_SEL_R, 1, &memory_bank);

	/* cancel mclk request */
	inv_imu_switch_off_mclk(self);

	return 0;
}

int inv_read_and_check_dmp_memory(struct inv_imu_device *self, const uint8_t *data, uint32_t bank,
                                  uint32_t offset, uint32_t size)
{
	uint8_t  memory_bank;
	uint8_t  dmp_memory_address;
	uint32_t i;
	int      rc = 0;

	/* make sure mclk is on */
	inv_imu_switch_on_mclk(self);

	/* Read DMP memory and check it against memory pointed by input parameter */
	memory_bank        = bank + (offset / 256);
	dmp_memory_address = offset % 256;

	inv_imu_write_reg(self, BLK_SEL_R, 1, &memory_bank);
	inv_imu_sleep_us(4);
	inv_imu_write_reg(self, MADDR_R, 1, &dmp_memory_address);
	inv_imu_sleep_us(4);

	for (i = offset; i < size + offset; i++) {
		uint8_t readByte;

		if (0 == (i % 256)) {
			memory_bank        = bank + (i / 256);
			dmp_memory_address = 0;
			inv_imu_write_reg(self, BLK_SEL_R, 1, &memory_bank);
			inv_imu_sleep_us(4);
			inv_imu_write_reg(self, MADDR_R, 1, &dmp_memory_address);
			inv_imu_sleep_us(4);
		}

		inv_imu_read_reg(self, M_R, 1, &readByte);
		inv_imu_sleep_us(4);
		if (readByte != data[i - offset]) {
			rc = -1;
			break;
		}
	}

	memory_bank = 0;
	inv_imu_write_reg(self, BLK_SEL_R, 1, &memory_bank);

	/* cancel mclk request */
	inv_imu_switch_off_mclk(self);

	return rc;
}

int inv_write_dmp_memory(struct inv_imu_device *self, const uint8_t *data, uint32_t bank,
                         uint32_t offset, uint32_t size)
{
	uint8_t  memory_bank;
	uint8_t  dmp_memory_address;
	uint32_t i;
	int      rc = 0;

	/* make sure mclk is on */
	inv_imu_switch_on_mclk(self);

	/* Write memory pointed by data into DMP memory */
	memory_bank        = bank + (offset / 256);
	dmp_memory_address = offset % 256;
	inv_imu_write_reg(self, BLK_SEL_W, 1, &memory_bank);
	inv_imu_sleep_us(4); /* wait 16 MCLK (4MHz) clock cycles */
	inv_imu_write_reg(self, MADDR_W, 1, &dmp_memory_address);
	inv_imu_sleep_us(4); /* wait 16 MCLK (4MHz) clock cycles */

	for (i = offset; i < size + offset; i++) {
		if (0 == (i % 256)) {
			memory_bank        = bank + (i / 256);
			dmp_memory_address = 0;
			inv_imu_write_reg(self, BLK_SEL_W, 1, &memory_bank);
			inv_imu_sleep_us(4);
			inv_imu_write_reg(self, MADDR_W, 1, &dmp_memory_address);
			inv_imu_sleep_us(4);
		}

		inv_imu_write_reg(self, M_W, 1, &data[i - offset]);
		inv_imu_sleep_us(4);
	}

	memory_bank = 0;
	inv_imu_write_reg(self, BLK_SEL_W, 1, &memory_bank);

	/* cancel mclk request */
	inv_imu_switch_off_mclk(self);

	rc |= inv_read_and_check_dmp_memory(self, data, bank, offset, size);

	return rc;
}

int inv_imu_write_dmp_ram(struct inv_imu_device *self, const uint8_t *data, uint32_t offset,
                          uint32_t size)
{
	if (size + offset > 1280U)
		return INV_ERROR_SIZE;

	return inv_write_dmp_memory(self, data, 0x50, offset, size);
}

int inv_imu_check_dmp_rom(struct inv_imu_device *self, uint8_t *expected_dmp_img, uint32_t size)
{
	if (size > 3584U)
		return INV_ERROR_SIZE;

	return inv_read_and_check_dmp_memory(self, expected_dmp_img, 0x30, 0, size);
}

int inv_load_dmp_rom(struct inv_imu_device *self, uint8_t *data, uint32_t size)
{
	if (size > 3584U)
		return INV_ERROR_SIZE;

	return inv_write_dmp_memory(self, data, 0x30, 0, size);
}

