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

/*
  MicroROS_Publisher
  
  This example aims to use MicroROS Arduino environment.
  Arduino library: micro_ros_arduino
  It publishes IMU accelerometer and gyroscope data from ICM42670 to microROS
  Agent.
  
  To get the data at 100Hz, please modify the serial interface speed in 
  micro_ros_arduino library: src\default_transport.cpp
  
  Update the baudrate parameter in `c Serial.begin()` API. 
  For example to 1Mbaud/s.
  ```c
    bool arduino_transport_open(struct uxrCustomTransport * transport)
    {
      Serial.begin(1000000);
      return true;
    }
  ```
*/
#include <micro_ros_arduino.h>

#include "ICM42670P.h"

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <sensor_msgs/msg/imu.h>

rcl_publisher_t publisher;
sensor_msgs__msg__Imu imu_msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){while(1);}}

// Define Accel Full Scale Range = 16G
#define ACCEL_FS 16
// Define Gyro Full Scale Range = 2000 dps
#define GYRO_FS 2000

// Instantiate an ICM42670 with LSB address set to 0
ICM42670 IMU(Wire,0);

extern "C" int clock_gettime(clockid_t unused, struct timespec *tp);

volatile uint8_t irq_received = 0;

void irq_handler(void) {
  irq_received = 1;
}

float_t convert_accel(int16_t raw, uint16_t fs) {
 return (float)raw * fs / INT16_MAX;
}

float_t convert_gyro(int16_t raw, uint16_t fs) {
 return ((float)raw * fs * PI) / (INT16_MAX * 180);
}

void event_cb(inv_imu_sensor_event_t *evt) {
  if(IMU.isAccelDataValid(evt)&&IMU.isGyroDataValid(evt)) {

    struct timespec tv = {0};

    clock_gettime(0, &tv);

    imu_msg.header.stamp.nanosec = tv.tv_nsec;
    imu_msg.header.stamp.sec = tv.tv_sec;

    imu_msg.linear_acceleration.x = convert_accel(evt->accel[0], ACCEL_FS);
    imu_msg.linear_acceleration.y = convert_accel(evt->accel[1], ACCEL_FS);
    imu_msg.linear_acceleration.z = convert_accel(evt->accel[2], ACCEL_FS);
    imu_msg.angular_velocity.x = convert_gyro(evt->gyro[0], GYRO_FS);
    imu_msg.angular_velocity.y = convert_gyro(evt->gyro[1], GYRO_FS);
    imu_msg.angular_velocity.z = convert_gyro(evt->gyro[2], GYRO_FS);

    rcl_publish(&publisher, &imu_msg, NULL);
  }
}

void setup() {
  set_microros_transports();
  delay(2000);

  // Initializing the ICM42670
  RCCHECK(IMU.begin());

  // Enable interrupt on pin 2, Fifo watermark=1
  IMU.enableFifoInterrupt(2,irq_handler,1);
  // Accel ODR = 100 Hz and Full Scale Range = 16G
  IMU.startAccel(100,ACCEL_FS);
  // Gyro ODR = 100 Hz and Full Scale Range = 2000 dps
  IMU.startGyro(100,GYRO_FS);

  // Wait IMU to start
  delay(100);

  allocator = rcl_get_default_allocator();
  // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  
  // create node
  RCCHECK(rclc_node_init_default(&node, "IMU_node", "", &support));
  
  // create publisher
  RCCHECK(rclc_publisher_init_default(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Imu),
    "IMU_publisher"));

  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
}

void loop() {
  if(irq_received) {
    irq_received = 0;
    IMU.getDataFromFifo(event_cb);
  }
}
