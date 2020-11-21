#include <Arduino.h>
#include "Wire.h"
const int joystickXPin = A0, joystickYPin = A1;
int dataWrite[2];

void setup() {
pinMode(joystickXPin, INPUT);
pinMode(joystickYPin, INPUT);
 Wire.begin(); // join i2c bus 
}

void loop() {
dataWrite[0] = analogRead(joystickXPin);
dataWrite[1] = analogRead(joystickYPin);
Wire.beginTransmission(4);
Wire.write(dataWrite);
Wire.endTransmission(); // stop transmitting
delay(10);



}


        