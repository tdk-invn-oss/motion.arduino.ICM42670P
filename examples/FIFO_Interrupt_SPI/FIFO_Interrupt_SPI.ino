#include "ICM42670P.h"

// Instantiate an ICM42670P with SPI interface and CS on pin 8
ICM42670P IMU(SPI,8);

uint8_t irq_received = 0;

void irq_handler(void) {
  irq_received = 1;
}

void event_cb(inv_imu_sensor_event_t *evt) {
  // Format data for Serial Plotter
  if(IMU.isAccelDataValid(evt)&&IMU.isGyroDataValid(evt)) {
    Serial.print("AccelX:");
    Serial.println(evt->accel[0]);
    Serial.print("AccelY:");
    Serial.println(evt->accel[1]);
    Serial.print("AccelZ:");
    Serial.println(evt->accel[2]);
    Serial.print("GyroX:");
    Serial.println(evt->gyro[0]);
    Serial.print("GyroY:");
    Serial.println(evt->gyro[1]);
    Serial.print("GyroZ:");
    Serial.println(evt->gyro[2]);
    Serial.print("Temperature:");
    Serial.println(evt->temperature);
  }
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
  // Enable interrupt on pin 2, Fifo watermark=10
  IMU.enableFifoInterrupt(2,irq_handler,10);
  // Accel ODR = 100 Hz and Full Scale Range = 16G
  IMU.startAccel(100,16);
  // Gyro ODR = 100 Hz and Full Scale Range = 2000 dps
  IMU.startGyro(100,2000);
}

void loop() {
  // Wait for interrupt to read data from fifo
  if(irq_received) {
      irq_received = 0;
      IMU.getDataFromFifo(event_cb);
  }
}
