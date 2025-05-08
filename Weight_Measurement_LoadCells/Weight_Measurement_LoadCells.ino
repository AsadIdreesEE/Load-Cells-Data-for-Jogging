#include "HX711.h"

#define LOADCELL_DOUT_PIN  9
#define LOADCELL_SCK_PIN  8
//int ref_value = 10;
//const int ledPin = 7;

HX711 scale;

float calibration_factor = 195;

void setup() {
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
}

void loop() {

  scale.set_scale(calibration_factor);
  Serial.print(scale.get_units(), 1);
  Serial.println();
delay(100);
}
