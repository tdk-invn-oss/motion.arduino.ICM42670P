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

volatile uint8_t irq_received = 0;

void irq_handler(void) {
  irq_received = 1;
}


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
  // Accel ODR = 50 Hz and APEX Pedometer enabled
  IMU.startPedometer(2,irq_handler);

}

void loop() {
  // Wait for interrupt to read data Pedometer status
  if(irq_received) {
    uint32_t step_count=0;
    float step_cadence=0;
    const char* activity;
    irq_received = 0;
    IMU.getPedometer(step_count,step_cadence,activity);
    Serial.print("Step count:");
    Serial.println(step_count);
    Serial.print("Step cadence:");
    Serial.println(step_cadence);
    Serial.print("activity:");
    Serial.println(activity);
  }
}
