/*
 * Author: Son La
 * Contact: e1300509@edu.vamk.fi
 * Comments: 
 *  Devices: ARDUINO Mega2560 and Näppäimistölevy
 */

#include "keypad.h"

char col_letter[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

int sensitivity = 100;


/*
  keypad_init() initilize pin mode and pin mapping, set sensitivity
  arguments: 
   sensitivity: sensitivity threshold (0 ~ 350)  

 */
void keypad_init(int sensitivity)
{
  pinMode(COL1, OUTPUT); // Col 1 : 1 2 3 A
  pinMode(COL2, OUTPUT); // Col 2 : 4 5 6 B
  pinMode(COL3, OUTPUT); // Col 3 : 7 8 9 C
  pinMode(COL4, OUTPUT); // Col 4 : * 0 # D

  pinMode(ROW1, INPUT); // Row 1 : 1 4 7 *
  pinMode(ROW2, INPUT); // Row 2 : 2 5 8 0
  pinMode(ROW3, INPUT); // Row 3 : 3 6 9 #
  pinMode(ROW4, INPUT); // Row 4 : A B C D

  analogWrite(ROW1, 0);
  analogWrite(ROW2, 0);
  analogWrite(ROW3, 0);
  analogWrite(ROW4, 0);

  sensitivity = sensitivity;
}


/*
  scan_input() scan all rows and columns and return pressed character or '\0'
  arguments: 
  returns:
   char: pressed character: '1', '2', '3', 'A', ... or '\0' if no key is pressed
 */
char scan_input(void)
{
  int col[4] = {COL1, COL2, COL3, COL4};
  int row[4] = {ROW1, ROW2, ROW3, ROW4};

  int cnt1, cnt2;
  for (cnt1 = 0; cnt1 < 4; cnt1++)
  {
    /*
        Select column to scan
        col 1: 1 0 0 0
        col 2: 0 1 0 0
        col 3: 0 0 1 0
        col 4: 0 0 0 1
    */
    digitalWrite(col[cnt1 % 4], HIGH);
    digitalWrite(col[(cnt1 + 1) % 4], LOW);
    digitalWrite(col[(cnt1 + 2) % 4], LOW);
    digitalWrite(col[(cnt1 + 3) % 4], LOW);

    /* Select row to scan*/
    for (cnt2 = 0; cnt2 < 4; cnt2++)
    {
      /*
         Turn
         E.g.: Scan row 1 -> cnt2 = 0 -> SET 1%4=1=Row2; 2%4=2=Row3; 3%4=3=Row4 equal '0'
      */
      analogWrite(row[(cnt2 + 1) % 4], 0);
      analogWrite(row[(cnt2 + 2) % 4], 0);
      analogWrite(row[(cnt2 + 3) % 4], 0);

      if (analogRead(row[cnt2]) > sensitivity)
      {
        return col_letter[cnt1][cnt2];
      }
    }
  }
  return '\0';
}


/*
  scan_input_debug() scan all rows and columns and print keypad layout of the device with raw pressing value to Serial monitor of ARDUINO IDE
  arguments: 
  returns:
 */
void scan_input_debug(void)
{
  int col[4] = {COL1, COL2, COL3, COL4};
  int row[4] = {ROW1, ROW2, ROW3, ROW4};
  
  for (int cnt1 = 0; cnt1 < 4; cnt1++)
  {
    /*
        Select column to scan
        col 1: 1 0 0 0
        col 2: 0 1 0 0
        col 3: 0 0 1 0
        col 4: 0 0 0 1
    */
    digitalWrite(col[cnt1 % 4], HIGH);
    digitalWrite(col[(cnt1 + 1) % 4], LOW);
    digitalWrite(col[(cnt1 + 2) % 4], LOW);
    digitalWrite(col[(cnt1 + 3) % 4], LOW);


    /* Select row to scan*/
    /* Select row to scan*/
    for (int cnt2 = 0; cnt2 < 4; cnt2++)
    {
      /*
         Turn
         E.g.: Scan row 1 -> cnt2 = 0 -> SET 1%4=1=Row2; 2%4=2=Row3; 3%4=3=Row4 equal '0'
      */
      analogWrite(row[(cnt2 + 1) % 4], 0);
      analogWrite(row[(cnt2 + 2) % 4], 0);
      analogWrite(row[(cnt2 + 3) % 4], 0);

      Serial.print(analogRead(row[cnt2]));
      Serial.print('\t');
    }   

    Serial.println();

  }
}
