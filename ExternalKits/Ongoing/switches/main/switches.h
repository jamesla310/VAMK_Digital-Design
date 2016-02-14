#ifndef SWITCHES_H
#define SWITCHES_H

#include <Arduino.h>
#include <HardwareSerial.h>

#define SW0 8
#define SW1 9
#define SW2 10 
#define SW3 11
#define SW4 12
#define SW5 13
#define SW6 14
#define SW7 15

#define NUMKEY 8

/* Functions prototype*/
/* Wrapper for .c files */
#ifdef __cfiles
extern "C" {
#endif

void switches_init();
int scan_input(void);
void scan_input_debug(void);

#ifdef __cfiles
}
#endif


#endif

