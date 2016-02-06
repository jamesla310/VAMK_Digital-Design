#ifndef SWITCHES_H
#define SWITCHES_H

#include <Arduino.h>
#include <HardwareSerial.h>

#define SW0 A0
#define SW1 A1
#define SW2 A2 
#define SW3 A3
#define SW4 A4
#define SW5 A5
#define SW6 A6
#define SW7 A7

#define NUMKEY 8

/* Functions prototype*/
/* Wrapper for .c files */
#ifdef __cfiles
extern "C" {
#endif

void switches_init(int sensitivity);
int scan_input(void);
void scan_input_debug(void);

#ifdef __cfiles
}
#endif


#endif
