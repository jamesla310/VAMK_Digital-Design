#ifndef RS232_H
#define RS232_H

#include <Arduino.h>


#define bit9600Delay 100  
#define halfBit9600Delay 50

#define ARDUINO_RX_PIN 50
#define ARDUINO_TX_PIN 52

/* Functions prototype*/
/* Wrapper for .c files */
#ifdef __cfiles
extern "C" {
#endif

void rs232_init();
void write_char(int data);
void write_string(char const * data);
int read_char();

#ifdef __cfiles
}
#endif

#endif
