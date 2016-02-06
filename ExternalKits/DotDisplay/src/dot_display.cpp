#include "dot_display.h"


uint8_t B_arr[4] = {B_0, B_1, B_2, B_3};
uint8_t RC_arr[7]= {RC1, RC2, RC3, RC4, RC5, RC6, RC7};
char Q_array[10][5] = {Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10};


/*
 *  void dot_display_init():
 *   	Function configures pins directions.
 */ 
void dot_display_init()
{
  // Pins initialization
  for (auto B_val : B_arr) pinMode(B_val, OUTPUT);
  for (auto RC_val : RC_arr) pinMode(RC_val, OUTPUT); 
}


/*
 *void setQ(char const *Q_val)
 *      Select column of point to print. To select column, B3-B2-B1-B0 is assigned to predefined char array. Read the docs/dot.pdf for more information.
 *  Params:
 * - char const *Q_val: Q value setting string
 */
void setQ(char const *Q_val)
{
  char B_val[4] {Q_val[3], Q_val[2], Q_val[1], Q_val[0]};

  for (auto i = 0; i < 4; i ++)
  {
    digitalWrite(B_arr[i], B_val[i] - '0');
  }  
}

/*
 * void draw_point(uint8_t x, uint8_t y)
 *  Params:
 *  - x,y coordinate
 */
void draw_point(uint8_t x, uint8_t y)
{
  if (x < 10 || y < 7) // top-left = (0,0), bottom_right = (9,6)
  {
    setQ(Q_array[x]);
    digitalWrite(RC_arr[y], HIGH);
  }
}

/*
 * void blink_point(uint8_t x, uint8_t y, uint16_t delay_time)
 *  Params:
 *   - x,y coordinate
 *   - delatime: time before clearing the point
 */
void blink_point(uint8_t x, uint8_t y, uint16_t delay_time)
{
  if (x < 10 || y < 7) // top-left = (0,0), bottom_right = (9,6)
  {
    setQ(Q_array[x]);
    digitalWrite(RC_arr[y], HIGH);
    delay(delay_time);
    digitalWrite(RC_arr[y], LOW);
  }
}

/*
 *  void clear_point(uint8_t x, uint8_t y)
 *   Params: 
 *    - x,y coordinate
 */
void clear_point(uint8_t x, uint8_t y)
{
  if (x < 10 || y < 7) // top-left = (0,0), bottom_right = (9,6)
  {
    setQ(Q_array[x]);
    digitalWrite(RC_arr[y], LOW);
  }
}

