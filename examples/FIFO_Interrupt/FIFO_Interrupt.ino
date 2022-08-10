#include "ICM42670P.h"

// Instantiate an ICM42670P with SPI interface and CS on pin 8
ICM42670P IMU(SPI,8);


void event_cb(inv_imu_sensor_event_t *evt)
{
  // Format data for Serial Plotter
  Serial.print(evt->accel[0]);
  Serial.print(",");
  Serial.print(evt->accel[1]);
  Serial.print(",");
  Serial.print(evt->accel[2]);
  Serial.print(",");
  Serial.print(evt->gyro[0]);
  Serial.print(",");
  Serial.print(evt->gyro[1]);
  Serial.print(",");
  Serial.print(evt->gyro[2]);
  Serial.print(",");
  Serial.println(evt->temperature);
}

void setup() {
  int ret;
  Serial.begin(115200);
  while(!Serial) {}

  // Initializing the ICM42670P
  ret = IMU.begin();
  if (ret != 0) {
    Serial.print("ICM42670P initialization failed: ");
    Serial.println(ret);
    while(1);
  }
  // Enable interrupt on pin 2, Fifo watermark=1
  IMU.enableFifoInterrupt(2,event_cb);
  // Accel ODR = 100 Hz and Full Scale Range = 16G
  IMU.startAccel(100,16);
  // Gyro ODR = 100 Hz and Full Scale Range = 2000 dps
  IMU.startGyro(100,2000);
  // Plotter axis
  Serial.println("AccelX,AccelY,AccelZ,GyroX,GyroY,GyroZ,Temperature");
}

void loop() {
 // Do nothing
}
