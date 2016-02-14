// Turnon LED when button is pressed

#include "switches.h"

void setup() {
  switches_init();
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*
  if (scan_input() != -1)
    digitalWrite(13,HIGH);
  else
    digitalWrite(13,LOW);
    */
    scan_input_debug();
  delay(300);
}
