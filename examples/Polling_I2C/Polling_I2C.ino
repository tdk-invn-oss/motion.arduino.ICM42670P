/*
 *
 * Copyright (c) [2022] by InvenSense, Inc.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include "ICM42670P.h"

// Instantiate an ICM42670 with LSB address set to 0
ICM42670 IMU(Wire,0);

void setup() {
  int ret;
  Serial.begin(115200);
  while(!Serial) {}

  // Initializing the ICM42670
  ret = IMU.begin();
  if (ret != 0) {
    Serial.print("ICM42670 initialization failed: ");
    Serial.println(ret);
    while(1);
  }
  // Accel ODR = 100 Hz and Full Scale Range = 16G
  IMU.startAccel(100,16);
  // Gyro ODR = 100 Hz and Full Scale Range = 2000 dps
  IMU.startGyro(100,2000);
  // Wait IMU to start
  delay(100);
}

void loop() {

  inv_imu_sensor_event_t imu_event;

  // Get last event
  IMU.getDataFromRegisters(imu_event);

  // Format data for Serial Plotter
  Serial.print("AccelX:");
  Serial.println(imu_event.accel[0]);
  Serial.print("AccelY:");
  Serial.println(imu_event.accel[1]);
  Serial.print("AccelZ:");
  Serial.println(imu_event.accel[2]);
  Serial.print("GyroX:");
  Serial.println(imu_event.gyro[0]);
  Serial.print("GyroY:");
  Serial.println(imu_event.gyro[1]);
  Serial.print("GyroZ:");
  Serial.println(imu_event.gyro[2]);
  Serial.print("Temperature:");
  Serial.println(imu_event.temperature);

  // Run @ ODR 100Hz
  delay(10);
}
