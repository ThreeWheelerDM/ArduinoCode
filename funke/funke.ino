#include <Arduino.h>
#include "Wire.h"
const int joystickXPin = A0; //joystickYPin = A1;
int dataWrite;

void setup() {
pinMode(joystickXPin, INPUT);
//pinMode(joystickYPin, INPUT);
 Wire.begin(); // join i2c bus 
 Serial.begin(115200);
}

void loop() {
dataWrite = analogRead(joystickXPin);
//dataWrite[1] = analogRead(joystickYPin);
Wire.beginTransmission(4);
Wire.write(dataWrite);
Wire.endTransmission(); // stop transmitting
Serial.write("send data");
delay(10);



}


