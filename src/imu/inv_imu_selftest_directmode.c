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

#include "imu/inv_imu_selftest_directmode.h"
#include "imu/inv_imu_extfunc.h"
#include "imu/inv_imu_transport.h"

#include <stdlib.h> /* abs */

struct backup_registers {
	uint8_t accel_config0;
	uint8_t accel_config1;
	uint8_t gyro_config0;
	uint8_t gyro_config1;
};

static int compute_mean_sensor_data(struct inv_imu_device *s, int num_samples,
                                    int32_t mean_accel[3], int32_t mean_gyro[3]);

static int parse_selftest_parameters(const inv_imu_selftest_parameters_t st_params,
                                     int *                               num_samples);

static int save_configuration(struct inv_imu_device *s, struct backup_registers *regs);

static int restore_configuration(struct inv_imu_device *s, const struct backup_registers regs);

int inv_imu_run_selftest_directmode(struct inv_imu_device *               s,
                                    const inv_imu_selftest_parameters_t   st_params,
                                    inv_imu_selftest_directmode_output_t *st_output)
{
	int     status = 0;
	uint8_t value;
	/* Variables used to save and restore device configuration */
	struct backup_registers bk_regs;
	/* Sensor settling duration */
	uint32_t settling_duration_us = (st_params.st_control & SELFTEST_GYRO_EN) ? 50000 : 25000;
	/* Number of sample to average on */
	int num_samples = 1;
	/* Limit to assess ST success */
	float st_lim_accel = 0.5;
	float st_lim_gyro  = 0.5;
	/* Contains ST value trimmed in OTP */
	uint8_t a_st_data[3];
	uint8_t g_st_data[3];

	/* Initialize st_output */
	st_output->ax_status    = 0;
	st_output->ay_status    = 0;
	st_output->az_status    = 0;
	st_output->accel_status = 0;
	st_output->gx_status    = 0;
	st_output->gy_status    = 0;
	st_output->gz_status    = 0;
	st_output->gyro_status  = 0;
	for (int i = 0; i < 3; i++) {
		st_output->accel.st_off[i]  = 0;
		st_output->accel.st_on[i]   = 0;
		st_output->accel.st_diff[i] = 0;
		st_output->accel.st_otp[i]  = 0;
		st_output->gyro.st_off[i]   = 0;
		st_output->gyro.st_on[i]    = 0;
		st_output->gyro.st_diff[i]  = 0;
		st_output->gyro.st_otp[i]   = 0;
	}

	/* Save current configuration to restore it at the end of the procedure */
	status |= save_configuration(s, &bk_regs);

	/* Parse parameters and convert them into usable values */
	status |= parse_selftest_parameters(st_params, &num_samples);

	/* Disables Gyro/Accel sensors */
	status |= inv_imu_read_reg(s, PWR_MGMT0, 1, &value);
	value &= ~(PWR_MGMT0_ACCEL_MODE_MASK | PWR_MGMT0_GYRO_MODE_MASK);
	status |= inv_imu_write_reg(s, PWR_MGMT0, 1, &value);

	/* Configure accel and gyro for self-test */
	if (st_params.st_control & SELFTEST_ACCEL_EN) {
		status |= inv_imu_set_accel_fsr(s, ACCEL_CONFIG0_FS_SEL_8g);
		status |= inv_imu_set_accel_frequency(s, ACCEL_CONFIG0_ODR_800_HZ);
		status |= inv_imu_set_accel_ln_bw(s, ACCEL_CONFIG1_ACCEL_FILT_BW_73);
		status |= inv_imu_enable_accel_low_noise_mode(s);
	}

	if (st_params.st_control & SELFTEST_GYRO_EN) {
		status |= inv_imu_set_gyro_fsr(s, GYRO_CONFIG0_FS_SEL_1000dps);
		status |= inv_imu_set_gyro_frequency(s, GYRO_CONFIG0_ODR_800_HZ);
		status |= inv_imu_set_gyro_ln_bw(s, GYRO_CONFIG1_GYRO_FILT_BW_73);
		status |= inv_imu_enable_gyro_low_noise_mode(s);
	}

	/* Wait for data to settle */
	inv_imu_sleep_us(settling_duration_us);

	/* Compute data mean when self-test is off */
	status |=
	    compute_mean_sensor_data(s, num_samples, st_output->accel.st_off, st_output->gyro.st_off);

	/* Check the gyro initial offset (should not exceed 20 dps) */
	if ((st_params.st_control & SELFTEST_GYRO_EN) &&
	    ((st_output->gyro.st_off[0] * 1000 > 20 * 32768) ||
	     (st_output->gyro.st_off[1] * 1000 > 20 * 32768) ||
	     (st_output->gyro.st_off[2] * 1000 > 20 * 32768))) {
		/* The gyro is considered a defect part */
		return status;
	}

	/* Enable self-test */
	if (st_params.st_control & SELFTEST_ACCEL_EN) {
		status |= inv_imu_read_reg(s, ST_CONFIG_MREG1, 1, &value);
		value |= ST_CONFIG_ACCEL_ST_REG_MASK;
		status |= inv_imu_write_reg(s, ST_CONFIG_MREG1, 1, &value);

		status |= inv_imu_read_reg(s, SELFTEST_MREG1, 1, &value);
		value |= SELFTEST_EN_AX_ST_MASK | SELFTEST_EN_AY_ST_MASK | SELFTEST_EN_AZ_ST_MASK;
		status |= inv_imu_write_reg(s, SELFTEST_MREG1, 1, &value);
	}
	if (st_params.st_control & SELFTEST_GYRO_EN) {
		/* Enable self-test */
		status |= inv_imu_read_reg(s, SELFTEST_MREG1, 1, &value);
		value |= SELFTEST_EN_GX_ST_MASK | SELFTEST_EN_GY_ST_MASK | SELFTEST_EN_GZ_ST_MASK;
		status |= inv_imu_write_reg(s, SELFTEST_MREG1, 1, &value);
	}

	/* Wait for data to settle */
	inv_imu_sleep_us(settling_duration_us);

	/* Compute data mean when self-test is on */
	status |=
	    compute_mean_sensor_data(s, num_samples, st_output->accel.st_on, st_output->gyro.st_on);

	/* Compute difference between self-test on and self-test off */
	for (int i = 0; i < 3; i++) {
		st_output->accel.st_diff[i] = st_output->accel.st_on[i] - st_output->accel.st_off[i];
		st_output->gyro.st_diff[i]  = st_output->gyro.st_on[i] - st_output->gyro.st_off[i];
	}

	/* Load self-test data */
	status |= inv_imu_load_selftest_data(s);

	/* Read self-test OTP */
	status |= inv_imu_read_reg(s, XA_ST_DATA_MREG3, 3, a_st_data);
	status |= inv_imu_read_reg(s, XG_ST_DATA_MREG3, 3, g_st_data);

	/* 
	 * Compute self-test threshold based on OTP values 
	 * For accel: 16 * xyz_selftest_data 
	 * For gyro:  32 * xyz_selftest_data
	 */
	for (int i = 0; i < 3; i++) {
		st_output->accel.st_otp[i] = a_st_data[i] * 16;
		st_output->gyro.st_otp[i]  = g_st_data[i] * 32;
	}

	/* Check accel status and update st_output */
	if (st_params.st_control & SELFTEST_ACCEL_EN) {
		int8_t st_status[3];
		for (int i = 0; i < 3; i++) {
			float error = (float)(abs(st_output->accel.st_diff[i] - st_output->accel.st_otp[i]));
			error /= st_output->accel.st_otp[i];
			st_status[i] = (error < st_lim_accel) ? 1 : 0;
		}
		st_output->ax_status    = st_status[0];
		st_output->ay_status    = st_status[1];
		st_output->az_status    = st_status[2];
		st_output->accel_status = (st_status[0] && st_status[1] && st_status[2]) ? 1 : 0;
	} else {
		/* Reset internal states for accel */
		for (int i = 0; i < 3; i++) {
			st_output->accel.st_off[i]  = 0;
			st_output->accel.st_on[i]   = 0;
			st_output->accel.st_diff[i] = 0;
			st_output->accel.st_otp[i]  = 0;
		}
	}

	/* Check gyro status and update st_output */
	if (st_params.st_control & SELFTEST_GYRO_EN) {
		int8_t st_status[3];
		for (int i = 0; i < 3; i++) {
			float error = (float)(abs(st_output->gyro.st_diff[i] - st_output->gyro.st_otp[i]));
			error /= st_output->gyro.st_otp[i];
			st_status[i] = (error < st_lim_gyro) ? 1 : 0;
		}
		st_output->gx_status   = st_status[0];
		st_output->gy_status   = st_status[1];
		st_output->gz_status   = st_status[2];
		st_output->gyro_status = (st_status[0] && st_status[1] && st_status[2]) ? 1 : 0;
	} else {
		/* Reset internal states for gyro */
		for (int i = 0; i < 3; i++) {
			st_output->gyro.st_off[i]  = 0;
			st_output->gyro.st_on[i]   = 0;
			st_output->gyro.st_diff[i] = 0;
			st_output->gyro.st_otp[i]  = 0;
		}
	}

	/* Disable self-test */
	if (st_params.st_control & SELFTEST_ACCEL_EN) {
		status |= inv_imu_read_reg(s, ST_CONFIG_MREG1, 1, &value);
		value &= ~ST_CONFIG_ACCEL_ST_REG_MASK;
		status |= inv_imu_write_reg(s, ST_CONFIG_MREG1, 1, &value);

		status |= inv_imu_read_reg(s, SELFTEST_MREG1, 1, &value);
		value &= (~SELFTEST_EN_AX_ST_MASK) & (~SELFTEST_EN_AY_ST_MASK) & (~SELFTEST_EN_AZ_ST_MASK);
		status |= inv_imu_write_reg(s, SELFTEST_MREG1, 1, &value);
	}
	if (st_params.st_control & SELFTEST_GYRO_EN) {
		status |= inv_imu_read_reg(s, SELFTEST_MREG1, 1, &value);
		value &= (~SELFTEST_EN_GX_ST_MASK) & (~SELFTEST_EN_GY_ST_MASK) & (~SELFTEST_EN_GZ_ST_MASK);
		status |= inv_imu_write_reg(s, SELFTEST_MREG1, 1, &value);
	}

	/* Save current configuration to restore it at the end of the procedure */
	status |= restore_configuration(s, bk_regs);

	return status;
}

static int compute_mean_sensor_data(struct inv_imu_device *s, int num_samples,
                                    int32_t mean_accel[3], int32_t mean_gyro[3])
{
	int     status      = 0;
	int32_t accel_sum_x = 0;
	int32_t accel_sum_y = 0;
	int32_t accel_sum_z = 0;
	int32_t gyro_sum_x  = 0;
	int32_t gyro_sum_y  = 0;
	int32_t gyro_sum_z  = 0;

	for (int i = 0; i < num_samples; i++) {
		uint8_t int_status = 0;
		uint8_t data[ACCEL_DATA_SIZE + GYRO_DATA_SIZE];

		/* Wait for interrupt */
		do {
			status |= inv_imu_read_reg(s, INT_STATUS_DRDY, 1, &int_status);
		} while (!(int_status & INT_STATUS_DRDY_DATA_RDY_INT_MASK) && !status);

		/* Read all data from registers */
		status |= inv_imu_read_reg(s, ACCEL_DATA_X1, ACCEL_DATA_SIZE + GYRO_DATA_SIZE, &data[0]);

		if (s->endianness_data == INTF_CONFIG0_DATA_BIG_ENDIAN) {
			accel_sum_x += (int16_t)((data[0] << 8) | data[1]);
			accel_sum_y += (int16_t)((data[2] << 8) | data[3]);
			accel_sum_z += (int16_t)((data[4] << 8) | data[5]);
			gyro_sum_x += (int16_t)((data[6] << 8) | data[7]);
			gyro_sum_y += (int16_t)((data[8] << 8) | data[9]);
			gyro_sum_z += (int16_t)((data[10] << 8) | data[11]);
		} else {
			accel_sum_x += (int16_t)((data[1] << 8) | data[0]);
			accel_sum_y += (int16_t)((data[3] << 8) | data[2]);
			accel_sum_z += (int16_t)((data[5] << 8) | data[4]);
			gyro_sum_x += (int16_t)((data[7] << 8) | data[6]);
			gyro_sum_y += (int16_t)((data[9] << 8) | data[8]);
			gyro_sum_z += (int16_t)((data[11] << 8) | data[10]);
		}
	}

	mean_accel[0] = accel_sum_x / num_samples;
	mean_accel[1] = accel_sum_y / num_samples;
	mean_accel[2] = accel_sum_z / num_samples;
	mean_gyro[0]  = gyro_sum_x / num_samples;
	mean_gyro[1]  = gyro_sum_y / num_samples;
	mean_gyro[2]  = gyro_sum_z / num_samples;

	return status;
}

static int parse_selftest_parameters(const inv_imu_selftest_parameters_t st_params,
                                     int *                               num_samples)
{
	int status = 0;

	/* Configure number of sample to read */
	switch (st_params.st_num_samples) {
	case ST_CONFIG_16_SAMPLES:
		*num_samples = 16;
		break;
	case ST_CONFIG_200_SAMPLES:
		*num_samples = 200;
		break;
	default:
		return -1; /* Invalid value for st_params.st_num_samples */
	}

	return status;
}

static int save_configuration(struct inv_imu_device *s, struct backup_registers *regs)
{
	int status = 0;

	status |= inv_imu_read_reg(s, ACCEL_CONFIG0, 1, &(regs->accel_config0));
	status |= inv_imu_read_reg(s, ACCEL_CONFIG1, 1, &(regs->accel_config1));
	status |= inv_imu_read_reg(s, GYRO_CONFIG0, 1, &(regs->gyro_config0));
	status |= inv_imu_read_reg(s, GYRO_CONFIG1, 1, &(regs->gyro_config1));

	return status;
}

static int restore_configuration(struct inv_imu_device *s, const struct backup_registers regs)
{
	int status = 0;

	status |= inv_imu_write_reg(s, ACCEL_CONFIG0, 1, &(regs.accel_config0));
	status |= inv_imu_write_reg(s, ACCEL_CONFIG1, 1, &(regs.accel_config1));
	status |= inv_imu_write_reg(s, GYRO_CONFIG0, 1, &(regs.gyro_config0));
	status |= inv_imu_write_reg(s, GYRO_CONFIG1, 1, &(regs.gyro_config1));

	return status;
}
