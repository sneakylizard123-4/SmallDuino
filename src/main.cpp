#include <Arduino.h>

int ledPin = 13; // choose the pin for the LED

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); // declare the LED pin as an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  int randomValue = random(50); // generate a random number between 0 and 99
  digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(randomValue); // wait for a random time
  digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW
  delay(randomValue); // wait for a random time
}
