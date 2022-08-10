/*
 *
 * ------------------------------------------------------------------------------------------------------------
 * Copyright (c) 2022 InvenSense, Inc All rights reserved.
 *
 * This software, related documentation and any modifications thereto (collectively "Software") is subject
 * to InvenSense, Inc and its licencors' intellectual property rights under U.S. and international copyright
 * and other intellectual property rights laws.
 *
 * InvenSense, Inc and its licencors retain all intellectual property and proprietary rights in and to the Software
 * and any use, reproduction, disclosure or distribution of the Software without an express license agreement
 * from InvenSense, Inc is strictly prohibited.
 *
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, IN NO EVENT SHALL
 * InvenSense, Inc BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTUOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THE SOFTWARE.
 *
 * ------------------------------------------------------------------------------------------------------------
 */
 
#ifndef ICM42670P_H
#define ICM42670P_H

#include "Arduino.h"
#include "SPI.h"
#include "Wire.h"

extern "C" {
#include "imu/inv_imu_driver.h"
#undef ICM42670P
}

// This defines the handler called when retrieving a sample from the FIFO
typedef void (*sensor_event_cb)(inv_imu_sensor_event_t *event);

class ICM42670P {
  public:
    ICM42670P(TwoWire &i2c,bool address_lsb);
    ICM42670P(SPIClass &spi,uint8_t chip_select_id);
    int begin();
    int startAccel(uint16_t odr, uint16_t fsr);
    int startGyro(uint16_t odr, uint16_t fsr);
    getDataFromRegisters(inv_imu_sensor_event_t* evt);
    enableFifoInterrupt(uint8_t intpin, sensor_event_cb event_cb);
  protected:
    struct inv_imu_device icm_driver;
    ACCEL_CONFIG0_ODR_t accel_freq_to_param(uint16_t accel_freq_hz);
    gyro_freq_to_param(uint16_t gyro_freq_hz);
    ACCEL_CONFIG0_FS_SEL_t accel_fsr_g_to_param(uint16_t accel_fsr_g);
    GYRO_CONFIG0_FS_SEL_t gyro_fsr_dps_to_param(uint16_t gyro_fsr_dps);
};

#endif // ICM42670P_H
