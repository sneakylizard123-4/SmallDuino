#include <Arduino.h>

int ledPin = 13; // choose the pin for the LED
bool ledState = LOW; // ledState used to set the LED
unsigned long previousMillisLed = 0;
long OnTimeLed = 250;
long OffTimeLed = 750;

int indPin = 12; // choose the pin for an indicator
bool indState = LOW; // ledState used to set the LED
unsigned long previousMillisInd = 0;
long OnTimeInd = 100;
long OffTimeInd = 400;

//remove soon
unsigned long interval = 500;  // interval at which to blink (milliseconds)

// define functions

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); // declare the LED pin as an OUTPUT
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  unsigned int randomValue = random(60); // generate a random number between 0 and 99
  Serial.print("LEDState: ");
  Serial.print(ledState);
  Serial.print(", ");

  Serial.print("IndicatorState: ");
  Serial.print(indState);
  Serial.print(", ");

  Serial.print("RandomValue: ");
  Serial.print(randomValue);
  Serial.print('\t');
  Serial.print(", ");

  Serial.print("CurrentMillis: ");
  Serial.print(currentMillis);
  Serial.print(", ");

  Serial.print("PreviousMillisLed: ");
  Serial.println(previousMillisLed);

  //update led state based on random value
  if(currentMillis - previousMillisLed > randomValue) {
    previousMillisLed = currentMillis;
      if(ledState == LOW) {
        digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
        ledState = HIGH;
      } else {
        digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW  
        ledState = LOW;
      }
    
    digitalWrite(ledPin, ledState);
  }

  //update indicator state every 500ms
  if((indState == HIGH) && (currentMillis - previousMillisInd >= OnTimeInd))
  {
    indState = LOW;  // Turn it off
    previousMillisInd = currentMillis;  // Remember the time
    digitalWrite(indPin, indState);  // Update the actual LED
  }
  else if ((indState == LOW) && (currentMillis - previousMillisInd >= OffTimeInd))
  {
    indState = HIGH;  // turn it on
    previousMillisInd = currentMillis;   // Remember the time
    digitalWrite(indPin, indState);	  // Update the actual LED
  }
}
