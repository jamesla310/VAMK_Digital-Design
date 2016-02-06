#include "rs232.h"

/* Src: https://www.arduino.cc/en/Tutorial/ArduinoSoftwareRS232 */

/*
 * Function initalizes RX and TX pins of ARDUINO
 */
void rs232_init()
{

  pinMode(ARDUINO_RX_PIN,INPUT);
  pinMode(ARDUINO_TX_PIN,OUTPUT);
}

/*
 * void write_char(int data)
 * parameter:
 *  int data: character to be send. E.g.: 'A', 'e', 1, ,3, ...
 *
 * Funtion sends a character with "9600/8n1" setting
 */
   
void write_char(int data)
{
  byte mask;
  //startbit
  digitalWrite(ARDUINO_TX_PIN,LOW);
  delayMicroseconds(bit9600Delay);

  //data 
  for (mask = 0x01; mask>0; mask <<= 1) {
    /* 
     * Check bit 1 or 0 to send out. E.g.: 
     * data & mask
     * 1010 & 0001 = 0 -> send LOW
     */
        
    if (data & mask){
     digitalWrite(ARDUINO_TX_PIN,HIGH); // send 1
    }
    else{
     digitalWrite(ARDUINO_TX_PIN,LOW); // send 0
    }
    delayMicroseconds(bit9600Delay);
  }
  
  //stop bit
  digitalWrite(ARDUINO_TX_PIN, HIGH);
  delayMicroseconds(bit9600Delay);
}

/*
 * write_string(char const * data)
 * parameter: 
 *  cons * data: Or string data (terminated with '\0') will be sent
 * Function sends a string with "9600/8n1" setting
 */
void write_string(char const * data)
{
  int i = 0;
  char c;

  // Read char in string until end of string
  while ((c = *(data + i++)) != '\0') write_char(c);  
}

/*
 * int read_char()
 *  return:
 *    int: integer value of readed character (ASCII)
 * Function reads received character and returns an integer value (ASCII)
 */
int read_char()
{
  byte val = 0;
  
  while (digitalRead(ARDUINO_RX_PIN)); //wait for start bit

  // Start reading data
  if (digitalRead(ARDUINO_RX_PIN) == LOW) {
    delayMicroseconds(halfBit9600Delay);
    for (int offset = 0; offset < 8; offset++) {
     delayMicroseconds(bit9600Delay);
     val |= digitalRead(ARDUINO_RX_PIN) << offset;
     
    }
    //wait for stop bit + extra
    delayMicroseconds(bit9600Delay); 
    delayMicroseconds(bit9600Delay);
    return val;
  }
}
