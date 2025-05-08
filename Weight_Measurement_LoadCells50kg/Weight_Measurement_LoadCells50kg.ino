#include "HX711.h"

#define LOADCELL_DOUT_PIN  9
#define LOADCELL_SCK_PIN  8

HX711 scale;

float calibration_factor = 195;
int stepCount = 0;
int avg = 0;
float weightThreshold = 60; // Adjust this value based on the minimum weight change considered as a step
bool stepDetected = false;

unsigned long previousMillis = 0;
const unsigned long interval = 30000; // Interval to reset step count (e.g., 30000 ms = 0.5 minute)

void setup() {
  Serial.begin(115200);
  //pinMode(ledPin, OUTPUT);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  
  //long zero_factor = scale.read_average();
  //Serial.println(zero_factor);
}

void loop() {
  scale.set_scale(calibration_factor);
  Serial.print(scale.get_units(), 1);
  Serial.println();

  //if (scale.get_units() >= weightThreshold && !stepDetected) {
    //stepCount++;
    //stepDetected = true;
    //Serial.print("Step Count: ");
    //Serial.println(stepCount);
  //}
  //else {
    //stepDetected = false;
  //}

  //unsigned long currentMillis = millis();
  //if (currentMillis - previousMillis >= interval) {
    //previousMillis = currentMillis;
    //stepCount = 0;
    //Serial.println("Step Count Reset to Zero");
  //}
delay(100);
}