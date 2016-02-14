/*
 * Author: Son La
 * Contact: e1300509@edu.vamk.fi
 * Comments: 
 *  Devices: ARDUINO Mega2560 and Näppäimistölevy
 *  Contains pin mapping and function prototypes
 */


#ifndef KEYPAD_H
#define KEYPAD_H

#include <Arduino.h>
#include <HardwareSerial.h>

// Col 1 : 1 2 3 A
// Col 2 : 4 5 6 B
// Col 3 : 7 8 9 C
// Col 4 : * 0 # D

// Row 1 : 1 4 7 *
// Row 2 : 2 5 8 0 
// Row 3 : 3 6 9 #
// Row 4 : A B C D

/* Pin mapping */
#define COL1 A0 
#define COL2 A1
#define COL3 A2
#define COL4 A3

#define ROW1 A5
#define ROW2 A6
#define ROW3 A7
#define ROW4 A4



/* Functions prototype*/
/* Wrapper for .c files, work around for ARDUINO IDE */
#ifdef __cfiles
extern "C" {
#endif

void keypad_init(int sensitivity);
char scan_input(void);
void scan_input_debug(void);

#ifdef __cfiles
}
#endif

#endif

