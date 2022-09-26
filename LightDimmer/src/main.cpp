#include <Arduino.h>
// I, Robert Zaranek, 001161598 certify that this material is my original work.
// No other person's work has been used without due acknowledgement.

bool isLedOn = false;
bool wasButtonPrevPressed = false;

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
  // configure pin D5 as an analog input - this is the pushbutton
  pinMode(D5, INPUT_PULLUP);
  // configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);
  // set default PWM range
  analogWriteRange(1023);
}

void loop() {
  int iButton;
  int iVal;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  // read the push button input...
  iButton = digitalRead(D5);

  // button toggle for LED logic
  if (iButton == 0 && !wasButtonPrevPressed)
  {
    wasButtonPrevPressed = true;
    isLedOn = !isLedOn;
  }
  else if (iButton == 1) {
    wasButtonPrevPressed = false;
  }
  
  if (isLedOn)
  {
    analogWrite(D4, iVal);
  }
  else {
    analogWrite(D4, 1023);
  }
}