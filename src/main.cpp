#include <Arduino.h>

int ledPin = 13; // choose the pin for the LED

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); // declare the LED pin as an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  int randomValue = random(100); // generate a random number between 0 and 99
  if (randomValue < 50) {
    digitalWrite(ledPin, HIGH); // turn the LED on
  } else {
    digitalWrite(ledPin, LOW); // turn the LED off
  }
}
