#ifndef DOT_DISPLAY_H
#define DOT_DISPLAY_H

#include <Arduino.h>

#define B_0 31  
#define B_1 33
#define B_2 35
#define B_3 37  

#define RC1 30
#define RC2 32
#define RC3 34
#define RC4 36
#define RC5 38
#define RC6 40 
#define RC7 42


#define Q1 "0000"
#define Q2 "0001"
#define Q3 "0010"
#define Q4 "0011"
#define Q5 "0100"
#define Q6 "0101"
#define Q7 "0110"
#define Q8 "0111"
#define Q9 "1000"
#define Q10 "1001"


/* Functions prototype*/
/* Wrapper for .c files, work around for ARDUINO IDE */
#ifdef __cfiles
extern "C" {
#endif

/* Functions to use */
void dot_display_init();
void draw_point(uint8_t x, uint8_t y);
void blink_point(uint8_t x, uint8_t y, uint16_t delay_time);
void clear_point(uint8_t x, uint8_t y);

/* Helpers */
void setQ(char const *Q_val);


#ifdef __cfiles
}
#endif


#endif
