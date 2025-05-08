#include "HX711.h"

#define LOADCELL1_DOUT_PIN  3
#define LOADCELL1_SCK_PIN  2
#define LOADCELL2_DOUT_PIN  5
#define LOADCELL2_SCK_PIN  4
#define LOADCELL3_DOUT_PIN  7
#define LOADCELL3_SCK_PIN  6
#define LOADCELL4_DOUT_PIN  9
#define LOADCELL4_SCK_PIN  8
#define LOADCELL5_DOUT_PIN  11
#define LOADCELL5_SCK_PIN  10

HX711 scale1;
HX711 scale2;
HX711 scale3;
HX711 scale4;
HX711 scale5;

float calibration_factor = 1950;

int stepCount = 0;
int avg = 0;
float weightThreshold = 1000; // Adjust this value based on the minimum weight change considered as a step
bool stepDetected = false;

unsigned long previousMillis = 0;
const unsigned long interval = 30000; // Interval to reset step count (e.g., 30000 ms = 0.5 minute)

void setup() {
  Serial.begin(115200);
  
  scale1.begin(LOADCELL1_DOUT_PIN, LOADCELL1_SCK_PIN);
  scale2.begin(LOADCELL2_DOUT_PIN, LOADCELL2_SCK_PIN);
  scale3.begin(LOADCELL3_DOUT_PIN, LOADCELL3_SCK_PIN);
  scale4.begin(LOADCELL4_DOUT_PIN, LOADCELL4_SCK_PIN);
  scale5.begin(LOADCELL5_DOUT_PIN, LOADCELL5_SCK_PIN);
  
  scale1.set_scale();
  scale2.set_scale();
  scale3.set_scale();
  scale4.set_scale();
  scale5.set_scale();

  scale1.tare(); //Reset the scale to 0
  scale2.tare(); //Reset the scale to 0
  scale3.tare(); //Reset the scale to 0
  scale4.tare(); //Reset the scale to 0
  scale5.tare(); //Reset the scale to 0
 
}

void loop() {

  scale1.set_scale(calibration_factor); //Adjust to this calibration factor
  scale1.get_units();
  //Serial.print("  ");

  scale2.set_scale(calibration_factor); //Adjust to this calibration factor
  scale2.get_units();
  //Serial.print("  ");

  scale3.set_scale(calibration_factor); //Adjust to this calibration factor
  scale3.get_units();
  //Serial.print("  ");

  scale4.set_scale(calibration_factor); //Adjust to this calibration factor
  scale4.get_units();
  //Serial.print("  ");

  scale5.set_scale(calibration_factor); //Adjust to this calibration factor
  scale5.get_units();
  //Serial.println();

  avg = ((scale1.get_units() + scale2.get_units() + scale3.get_units() + scale4.get_units() + scale5.get_units())/5);
  Serial.println(avg);
  //if (avg >= weightThreshold && !stepDetected) {
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
}
