#include "HX711.h"

#define LOADCELL_DOUT_PIN  A4
#define LOADCELL_SCK_PIN  A5

const int ledPin = 4;       // LED connected to digital pin 13
const int knockSensor = A0;  // the piezo is connected to analog pin 0
const int threshold = 50;   // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;  // variable to store the value read from the sensor pin
int ledState = LOW;     // variable used to store the last LED status, to toggle the light

HX711 scale;

float calibration_factor = -195050; //-7050 worked for my 440lb max scale setup

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as as OUTPUT
  Serial.begin(9600);  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
}

void loop() {
sensorReading = analogRead(knockSensor);
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  Serial.print(scale.get_units(), 1);
  Serial.println(sensorReading);
   if (sensorReading >= threshold) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    Serial.println("Knock!");
    Serial.println();
   }
delay (500);
}
