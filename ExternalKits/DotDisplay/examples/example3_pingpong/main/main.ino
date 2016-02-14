/* ping pong game 
  Son La - e1300509@edu.vamk.fi
*/

#include "dot_display.h"

#define DELAY 30 // Inverse of speed
#define SCREEN_WIDTH  10 // Width of screen
#define SCREEN_HEIGHT 7 // Height of screen
#define BALL_WIDTH  1 // Ball dimension
#define EDGE_WIDTH 2 // Bar dimension

/* Convention */
#define LEFT_RIGHT 0 
#define RIGHT_LEFT 1
#define UP_DOWN 0
#define DOWN_UP 1


// Struct for drawing point 
struct Point
{
  uint8_t x;
  uint8_t y;
};


// Run once
void setup() {
  dot_display_init();
}


// Variables declaration
Point ball[1] = {Point{0,0}}; // Ball frame
Point edge[2] = {Point{0,0}, Point{0,1}}; // Bar frame

int tik_tok = 0; // Time
int ball_dx=1,ball_dy = 0; // Shift of ball frame
int dirx = 0, diry = 0; // Direction of ball
int edge_dy = 0;// Shift of bar frame



// Repeat running
void loop() {

  if (++tik_tok == DELAY)  // Print the same frame for DELAY times, then update new positions
  {
    tik_tok = 0;

    
    // Left edge and Right edge bounce
    if (ball_dx == 1 && dirx == RIGHT_LEFT) 
      dirx = LEFT_RIGHT;
  
    if (ball_dx == SCREEN_WIDTH-BALL_WIDTH && dirx == LEFT_RIGHT)
      dirx = RIGHT_LEFT;
  
    // Top edge and bottom edge bounce
    if (ball_dy == 0 && diry == DOWN_UP)
      diry = UP_DOWN;
  
    if (ball_dy == SCREEN_HEIGHT-BALL_WIDTH && diry == UP_DOWN)
      diry = DOWN_UP;  
  

    // New positions
    if (dirx == LEFT_RIGHT)
      ball_dx++;
    else
      ball_dx--;
  
    if (diry == UP_DOWN)
      ball_dy++;
    else  
      ball_dy--;
  }


  // Print ball
  for (auto num0 : ball)
    {
        blink_point(num0.x + ball_dx, num0.y + ball_dy,1);

    }

  // Get new position for bar
  edge_dy = ball_dy ;

  // Print bar
  for (auto e:edge)
    blink_point(e.x, e.y+edge_dy,1);
      
    
}

