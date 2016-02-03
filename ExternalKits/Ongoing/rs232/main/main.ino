#include "keypad.h"
#include "rs232.h"

void setup() {
  keypad_init(100);
  Serial.begin(9600);
  

  rs232_init();
  write_string("Hello World!\r\n");
}

void loop()
{
  
    char c = scan_input();
    if (c != '\0')
    {
      Serial.print(c);
      write_char(c);
    }    
    
    delay(200);
}



