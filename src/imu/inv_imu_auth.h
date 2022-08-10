/*
 * ________________________________________________________________________________________________________
 * Copyright (c) 2015-2015 InvenSense Inc. All rights reserved.
 *
 * This software, related documentation and any modifications thereto (collectively “Software”) is subject
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

/** @defgroup authentication Secure Authentication
 *  @brief High-level functions to execute authentication routine.
 *  @{
 */

/** @file inv_imu_auth.h */

#ifndef _INV_IMU_AUTH_H_
#define _INV_IMU_AUTH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

#if defined(__ICCARM__)
#define STATIC_INLINE _Pragma("inline=forced") static inline
#else
#define STATIC_INLINE static inline __attribute__((always_inline))
#endif

/** Serial interface structure to be used for authentication */
typedef struct {
	int (*read_reg_auth)(uint8_t reg, uint8_t *buf, uint32_t len);
	int (*write_reg_auth)(uint8_t reg, const uint8_t *buf, uint32_t len);
	void (*sleep_us)(uint32_t us);
} inv_serif_auth_t;

/** @brief Execute authentication routine.
 *  @param[in] s  Serial interface structure required for authentication routine.
 *  @return       0 on success, negative value on error.
 */
STATIC_INLINE int inv_imu_authenticate_device(inv_serif_auth_t *s);

/*
 * PRIVATE CODE
 */

/* Secure Authentication parameters */
#define IV_SIZE_BYTES       4
#define HMAC_KEY_SIZE_BYTES 12

/* Addresses of direct access registers */
#define DREG_MCLK_RDY      0x00
#define DREG_ACCEL_DATA_X1 0x0b
#define DREG_GYRO_DATA_X1  0x11
#define DREG_PWR_MGMT0     0x1f
#define DREG_GYRO_CONFIG0  0x20
#define DREG_ACCEL_CONFIG0 0x21
#define DREG_APEX_CONFIG0  0x25
#define DREG_APEX_CONFIG1  0x26
#define DREG_FIFO_CONFIG1  0x28
#define DREG_APEX_DATA3    0x34
#define DREG_INTF_CONFIG0  0x35
#define DREG_BLK_SEL_W     0x79
#define DREG_MADDR_W       0x7a
#define DREG_M_W           0x7b
#define DREG_BLK_SEL_R     0x7c
#define DREG_MADDR_R       0x7d
#define DREG_M_R           0x7e
#define DREG_WHO_AM_I      0x75

/* Addresses of indirect access registers */
#define DMP_CONFIG1_MREG1 0x002c

static uint8_t dmp_image[] = {
#include "dmp3Default_xian_secauth.txt"
};

/* 
 * Contains registers value that will be modified during the procedure.
 */
typedef struct {
	/* Direct access registers */
	uint8_t pwr_mgmt0;
	uint8_t gyro_config0;
	uint8_t accel_config0;
	uint8_t apex_config0;
	uint8_t apex_config1;
	uint8_t fifo_config1;
	uint8_t intf_config0;

	/* Indirect access registers */
	uint8_t dmp_config1_mreg1;
} device_settings_t;

/* Initialize IMU for device authentication */
STATIC_INLINE int initialize_imu(inv_serif_auth_t *s);

/* Generate 4 Bytes long IV with random data (noise in sensor data) */
STATIC_INLINE int generate_4bytes_iv(inv_serif_auth_t *s, uint8_t iv[IV_SIZE_BYTES]);

/* Load DMP secure authentication image in DMP SRAM and set start address */
STATIC_INLINE int load_dmp_sram_code(inv_serif_auth_t *s, const uint32_t addr, const uint32_t size,
                                     const uint8_t *dmp_prog);

/* Runs HMAC-CRC32 algorithm on EDMP */
STATIC_INLINE int run_secure_auth_on_dmp(inv_serif_auth_t *s, uint8_t iv[IV_SIZE_BYTES],
                                         uint8_t cipher_out[IV_SIZE_BYTES]);

/* Runs HMAC-CRC32 algorithm on host */
STATIC_INLINE int run_hmac_crc32(uint8_t key[HMAC_KEY_SIZE_BYTES], uint8_t iv[IV_SIZE_BYTES],
                                 uint8_t cipher_out[IV_SIZE_BYTES]);

/* CRC32B implementation without lookup table */
STATIC_INLINE int crc32b(uint8_t *message, uint8_t input_len, uint8_t data[IV_SIZE_BYTES]);

/* Reads MCLK registers and memories */
STATIC_INLINE int read_mclk_memory(inv_serif_auth_t *s, uint32_t addr, uint32_t size, uint8_t *buf);

/* Writes MCLK registers and memories */
STATIC_INLINE int write_mclk_memory(inv_serif_auth_t *s, uint32_t addr, uint32_t size,
                                    const uint8_t *buf);

/* Saves registers value to re-apply after executing the routine */
STATIC_INLINE int save_settings(inv_serif_auth_t *s, device_settings_t *settings);

/* Restores registers value */
STATIC_INLINE int recover_settings(inv_serif_auth_t *s, device_settings_t *settings);

STATIC_INLINE int initialize_imu(inv_serif_auth_t *s)
{
	int     status = 0;
	uint8_t data;

	/* Set data registers endianness to big endian */
	status |= s->read_reg_auth(DREG_INTF_CONFIG0, &data, 1);
	data |= 0x30;
	status |= s->write_reg_auth(DREG_INTF_CONFIG0, &data, 1);

	/* Disable FIFO (by setting bypass mode) */
	data = 0x01;
	status |= s->write_reg_auth(DREG_FIFO_CONFIG1, &data, 1);

	/* Set Accel and Gyro FSR to lowest available and ODR to 50 Hz */
	data = 0x6A; /* FSR = 2 g, ODR = 50 Hz */
	status |= s->write_reg_auth(DREG_ACCEL_CONFIG0, &data, 1);
	data = 0x6A; /* FSR = 250 dps, ODR = 50 Hz */
	status |= s->write_reg_auth(DREG_GYRO_CONFIG0, &data, 1);

	return status;
}

STATIC_INLINE int generate_4bytes_iv(inv_serif_auth_t *s, uint8_t iv[IV_SIZE_BYTES])
{
	int     status = 0;
	uint8_t accel_data[6];
	uint8_t gyro_data[6];
	uint8_t data;

	/* Enable accel and gyro */
	data = 0x1F; /* accel_mode = LN, gyro_mode = LN */
	status |= s->write_reg_auth(DREG_PWR_MGMT0, &data, 1);

	/* Wait for sensor to be ready (gyro startup time is 70 ms + margin) */
	s->sleep_us(100000);

	/* Read accel and gyro data */
	status |= s->read_reg_auth(DREG_ACCEL_DATA_X1, &accel_data[0], 6);
	status |= s->read_reg_auth(DREG_GYRO_DATA_X1, &gyro_data[0], 6);

	/* Fill in IV */
	iv[0] = accel_data[1]; /* ACC X LSB */
	iv[1] = gyro_data[1]; /* GYR X LSB */
	iv[2] = gyro_data[3]; /* GYR Y LSB */
	iv[3] = gyro_data[5]; /* GYR Z LSB */

	/* Stop accel and gyro. Keep idle off for mclk */
	data = 0x10; /* accel_mode = LN, gyro_mode = LN */
	status |= s->write_reg_auth(DREG_PWR_MGMT0, &data, 1);

	return status;
}

STATIC_INLINE int read_mclk_memory(inv_serif_auth_t *s, uint32_t addr, uint32_t size, uint8_t *buf)
{
	uint8_t  bank   = (addr & 0xFF00) >> 8;
	uint8_t  offset = (addr & 0xFF);
	uint32_t i;

	s->write_reg_auth(DREG_BLK_SEL_R, &bank, 1);
	s->sleep_us(4); /* wait 16 MCLK (4MHz) clock cycles */
	s->write_reg_auth(DREG_MADDR_R, &offset, 1);
	s->sleep_us(4);

	for (i = offset; i < size + offset; i++) {
		if (0 == (i % 256)) {
			uint8_t data = 0;

			bank = ((addr + i) & 0xFF00) >> 8;
			s->write_reg_auth(DREG_BLK_SEL_R, &bank, 1);
			s->write_reg_auth(DREG_MADDR_R, &data, 1);
			s->sleep_us(4);
		}

		s->read_reg_auth(DREG_M_R, &buf[i - offset], 1);
		s->sleep_us(4);
	}

	bank = 0;
	s->write_reg_auth(DREG_BLK_SEL_R, &bank, 1);

	return 0;
}

STATIC_INLINE int write_mclk_memory(inv_serif_auth_t *s, uint32_t addr, uint32_t size,
                                    const uint8_t *buf)
{
	uint8_t  bank   = (addr & 0xFF00) >> 8;
	uint8_t  offset = (addr & 0xFF);
	uint32_t i;

	s->write_reg_auth(DREG_BLK_SEL_W, &bank, 1);
	s->sleep_us(4); /* wait 16 MCLK (4MHz) clock cycles */
	s->write_reg_auth(DREG_MADDR_W, &offset, 1);
	s->sleep_us(4);

	for (i = offset; i < size + offset; i++) {
		if (0 == (i % 256)) {
			uint8_t data = 0;

			bank = ((addr + i) & 0xFF00) >> 8;
			s->write_reg_auth(DREG_BLK_SEL_W, &bank, 1);
			s->sleep_us(4);
			s->write_reg_auth(DREG_MADDR_W, &data, 1);
			s->sleep_us(4);
		}

		s->write_reg_auth(DREG_M_W, &buf[i - offset], 1);
		s->sleep_us(4);
	}

	bank = 0;
	s->write_reg_auth(DREG_BLK_SEL_W, &bank, 1);

	return 0;
}

STATIC_INLINE int load_dmp_sram_code(inv_serif_auth_t *s, const uint32_t addr, const uint32_t size,
                                     const uint8_t *dmp_prog)
{
	int status = 0;

	status |= write_mclk_memory(s, addr, size, dmp_prog);

	if (!status) {
		uint8_t data;

		/* Set DMP code start address.
		 * Start address is hardcoded to ram address 160. 
		 * But HW multiply value in DMP_CONFIG1_MREG1 by 32.
 		 */
		data = (160 / 32);
		status |= write_mclk_memory(s, DMP_CONFIG1_MREG1, 1, &data);
	}

	return status;
}

STATIC_INLINE int run_secure_auth_on_dmp(inv_serif_auth_t *s, uint8_t iv[IV_SIZE_BYTES],
                                         uint8_t cipher_out[IV_SIZE_BYTES])
{
	int     status = 0;
	int     i;
	uint8_t data;

	/* Copy IV into DMP image. IV is copied at offset 0 in dmp_image */
	for (i = 0; i < IV_SIZE_BYTES; i++)
		dmp_image[i] = iv[i];

	/* Load DMP secure authentication image in DMP SRAM and set start address */
	status |= load_dmp_sram_code(s, 0x5000, sizeof(dmp_image) / sizeof(dmp_image[0]), dmp_image);

	/* Start DMP Secure Authentication process:
	 *  - inihibit accel data copy to avoid poluting SRAM
	 *  - enable one APEX feature
	 *  - enable Accel to trig DMP execution
	 */
	data = 0x10;
	status |= s->write_reg_auth(DREG_APEX_CONFIG0, &data, 1);
	data = 0x8;
	status |= s->write_reg_auth(DREG_APEX_CONFIG1, &data, 1);
	data = 0x13;
	status |= s->write_reg_auth(DREG_PWR_MGMT0, &data, 1);

	/* wait to make sure dmp_idle = 0 [firmware feature starts once dmp_idle goes high-to-low] */
	while (1) {
		s->read_reg_auth(DREG_APEX_DATA3, &data, 1);

		if ((data & 0x4) == 0)
			break;

		s->sleep_us(5);
	}

	/* wait to make sure dmp_idle = 1 [dmp_idle low-to-high indicates that firmware feature 
	 * complete for one sample/dmp-odr-cycle]
	 */
	while (1) {
		s->read_reg_auth(DREG_APEX_DATA3, &data, 1);

		if ((data & 0x4) != 0)
			break;

		s->sleep_us(5);
	}

	data = 0x10; /* stop accel */
	status |= s->write_reg_auth(DREG_PWR_MGMT0, &data, 1);

	/* Read cipher output from EDMP */
	status |= read_mclk_memory(s, 0x5000, 4, cipher_out);

	/* Stop Secure Authentication process */
	data = 0x0;
	status |= s->write_reg_auth(DREG_APEX_CONFIG1, &data, 1);

	/* Reset SRAM
	 * Make sure reset procedure has finished by reading back mem_reset_en bit
	 */
	data = 0x1;
	status |= s->write_reg_auth(DREG_APEX_CONFIG0, &data, 1);
	s->sleep_us(1000);

	do {
		s->sleep_us(10);
		status |= s->read_reg_auth(DREG_APEX_CONFIG0, &data, 1);
	} while ((data & 0x1) && !status);

	return status;
}

STATIC_INLINE void memcpy32(uint8_t *dst, uint32_t *src, int len)
{
	for (int i = 0; i < len; i += 4) {
		dst[i * 4 + 3] = ((*src) >> 24) & 0xFF;
		dst[i * 4 + 2] = ((*src) >> 16) & 0xFF;
		dst[i * 4 + 1] = ((*src) >> 8) & 0xFF;
		dst[i * 4] = (*src) & 0xFF;
	}
}

STATIC_INLINE int run_hmac_crc32(uint8_t key[HMAC_KEY_SIZE_BYTES], uint8_t iv[IV_SIZE_BYTES],
                                 uint8_t cipher_out[IV_SIZE_BYTES])
{
	int      status = 0;
	int      i;
	uint32_t ipad = 0x36363636;
	uint32_t K0_ipad_BE;
	uint32_t opad = 0x5C5C5C5C;
	uint32_t K0_opad_BE;
	uint32_t crc32_BE;
	uint8_t  to_hash[HMAC_KEY_SIZE_BYTES];

	/* Key is longer CRC32 block size (4B) so let's hash the key using CRC32 */
	status |= crc32b(key, HMAC_KEY_SIZE_BYTES, cipher_out);

	/* process K0 ^ ipad and K0 ^opad */
	crc32_BE = (((uint32_t)cipher_out[3]) << 24) + (((uint32_t)cipher_out[2]) << 16) +
	           (((uint32_t)cipher_out[1]) << 8) + cipher_out[0];
	K0_ipad_BE = crc32_BE ^ ipad;
	K0_opad_BE = crc32_BE ^ opad;

	/* process CRC32(K0_ipad | input_msg) */
	memcpy32(to_hash, &K0_ipad_BE, IV_SIZE_BYTES);
	memcpy(to_hash + IV_SIZE_BYTES, iv, IV_SIZE_BYTES);
	status |= crc32b(to_hash, IV_SIZE_BYTES + IV_SIZE_BYTES, cipher_out);

	/* process HMAC = CRC32(K0_opad | CRC32(K0_ipad | input_msg)) */
	memcpy32(to_hash, &K0_opad_BE, IV_SIZE_BYTES);
	memcpy(to_hash + IV_SIZE_BYTES, cipher_out, IV_SIZE_BYTES);
	status |= crc32b(to_hash, IV_SIZE_BYTES + IV_SIZE_BYTES, cipher_out);

	/* Swap cipher to populate `cipher_out` */
	for (i = 0; i < IV_SIZE_BYTES; i++)
		cipher_out[i] = cipher_out[i];

	return status;
}

STATIC_INLINE int crc32b(uint8_t *message, uint8_t input_len, uint8_t data[IV_SIZE_BYTES])
{
	/* 
	 * This is a basic CRC-32 calculation with some optimization but no
	 * table lookup. The byte reversal is avoided by shifting the crc reg
	 * right instead of left and by using a reversed 32-bit word to represent
	 * the polynomial. 
	 */
	int      status = 0;
	int      i, j;
	uint32_t byte, crc, mask;
	uint32_t output;

	crc = 0xFFFFFFFF;
	for (i = 0; i < input_len; i++) {
		byte = message[i];
		crc  = crc ^ byte;
		for (j = 0; j < 8; j++) {
			mask = -(crc & 1);
			crc  = (crc >> 1) ^ (0xEDB88320 & mask);
		}
	}
	output = ~crc;

	data[0] = (uint8_t)((output >> 24) & 0xff);
	data[1] = (uint8_t)((output >> 16) & 0xff);
	data[2] = (uint8_t)((output >> 8) & 0xff);
	data[3] = (uint8_t)((output)&0xff);

	return status;
}

STATIC_INLINE int save_settings(inv_serif_auth_t *s, device_settings_t *settings)
{
	int     status = 0;
	uint8_t data;

	/* Direct access registers */
	status |= s->read_reg_auth(DREG_PWR_MGMT0, &settings->pwr_mgmt0, 1);
	status |= s->read_reg_auth(DREG_GYRO_CONFIG0, &settings->gyro_config0, 1);
	status |= s->read_reg_auth(DREG_ACCEL_CONFIG0, &settings->accel_config0, 1);
	status |= s->read_reg_auth(DREG_APEX_CONFIG0, &settings->apex_config0, 1);
	status |= s->read_reg_auth(DREG_APEX_CONFIG1, &settings->apex_config1, 1);
	status |= s->read_reg_auth(DREG_FIFO_CONFIG1, &settings->fifo_config1, 1);
	status |= s->read_reg_auth(DREG_INTF_CONFIG0, &settings->intf_config0, 1);

	if (status)
		return status;

	/* Force MCLK on now PWR_MGMT0 is saved. Keep MCLK on until end of secure authentication. */
	status |= s->read_reg_auth(DREG_PWR_MGMT0, &data, 1);
	data |= 0x10;
	status |= s->write_reg_auth(DREG_PWR_MGMT0, &data, 1);

	if (status)
		return status;

	/* Check if MCLK is ready */
	do {
		status = s->read_reg_auth(DREG_MCLK_RDY, &data, 1);
	} while ((status != 0) || !(data & 0x8));

	/* Now MCLK is ready, we can use indirect access registers */
	status |= read_mclk_memory(s, DMP_CONFIG1_MREG1, 1, &settings->dmp_config1_mreg1);

	return status;
}

STATIC_INLINE int recover_settings(inv_serif_auth_t *s, device_settings_t *settings)
{
	int status = 0;

	/* Indirect access registers (first as we still have MCLK forced on) */
	status |= write_mclk_memory(s, DMP_CONFIG1_MREG1, 1, &settings->dmp_config1_mreg1);

	/* Direct access registers */
	status |= s->write_reg_auth(DREG_PWR_MGMT0, &settings->pwr_mgmt0, 1);
	status |= s->write_reg_auth(DREG_GYRO_CONFIG0, &settings->gyro_config0, 1);
	status |= s->write_reg_auth(DREG_ACCEL_CONFIG0, &settings->accel_config0, 1);
	status |= s->write_reg_auth(DREG_APEX_CONFIG0, &settings->apex_config0, 1);
	status |= s->write_reg_auth(DREG_APEX_CONFIG1, &settings->apex_config1, 1);
	status |= s->write_reg_auth(DREG_FIFO_CONFIG1, &settings->fifo_config1, 1);
	status |= s->write_reg_auth(DREG_INTF_CONFIG0, &settings->intf_config0, 1);

	return status;
}

/*
 * Runs secure authentication procedure
 */
STATIC_INLINE int inv_imu_authenticate_device(inv_serif_auth_t *s)
{
	int               status = 0;
	device_settings_t settings;
	uint8_t           iv[IV_SIZE_BYTES]          = { 0 };
	uint8_t           cipher_imu[IV_SIZE_BYTES]  = { 0 };
	uint8_t           cipher_host[IV_SIZE_BYTES] = { 0 };
	uint8_t *         key = &dmp_image[16]; /* use pointer on key in dmp_image */

	/* Save registers values for those we need to modify during the procedure */
	status |= save_settings(s, &settings);

	/* Prepare IMU for secure authentication */
	status |= initialize_imu(s);

	/* Generate a random 4-byte IV */
	status |= generate_4bytes_iv(s, iv);

	/* Execute HMAC-CRC32 on DMP */
	status |= run_secure_auth_on_dmp(s, iv, cipher_imu);

	/* Execute HMAC-CRC32 on host software */
	status |= run_hmac_crc32(key, iv, cipher_host);

	/* Compare result between IMU and host routines */
	if (memcmp(cipher_host, cipher_imu, IV_SIZE_BYTES))
		status = -1; /* Produce error if it doesn't match */

	/* Restore registers values */
	status |= recover_settings(s, &settings);

	return status;
}

#ifdef __cplusplus
}
#endif

#endif /* _INV_IMU_AUTH_H_ */

/** @} */
