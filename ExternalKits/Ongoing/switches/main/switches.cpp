#include "switches.h"

int switches[8] = {SW0, SW1, SW2, SW3, SW4, SW5, SW6, SW7};
int sensitivity = 50;

void switches_init()
{
  int cnt;
  analogReference(DEFAULT);
  for (cnt = 0; cnt < NUMKEY; cnt++)
  {
    pinMode(switches[cnt], INPUT);
  } 
  
}

int scan_input(void)
{
  int cnt;
  for (cnt = 0; cnt < NUMKEY; cnt++)
  {
    digitalWrite(switches[cnt],HIGH);
    if (digitalRead(switches[cnt]) == LOW)
      return cnt;
  }
  return -1;
}


void scan_input_debug(void)
{
  int cnt;
  for (cnt = 0; cnt < NUMKEY; cnt++)
  {
    digitalWrite(switches[cnt],HIGH);
    
    Serial.print(digitalRead(switches[cnt]));
    Serial.print('\t');
   
  }
  Serial.println();
}

