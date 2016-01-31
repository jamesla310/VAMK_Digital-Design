#include "switches.h"

int switches[8] = {A0, A1, A2, A3, A4, A5, A6, A7};
int sensitivity = 50;

void switches_init(int sensitivity)
{
  int cnt;
  for (cnt = 0; cnt < NUMKEY; cnt++)
    pinMode(switches[cnt], INPUT);  

  sensitivity = sensitivity;
}

int scan_input(void)
{
  int cnt;
  for (cnt = 0; cnt < NUMKEY; cnt++)
  {
    if (analogRead(switches[cnt]) < sensitivity)
    {
      return cnt;
    }
  }
  return -1;
}


void scan_input_debug(void)
{
  int cnt;
  for (cnt = 0; cnt < NUMKEY; cnt++)
  {
    Serial.print(analogRead(switches[cnt]));
    Serial.print('\t');
  }
  Serial.println();
}
