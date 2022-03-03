/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

extern int seed;

int rand(){
  seed = seed * 1103515245 + 12345;
  
  return (unsigned int)(seed/65536) % 3 + 1;
}

/*void *memcpy(void *dest, const void *src, size_t n)
{   
  size_t i;
  for (i = 0; i < n; i++)
  {
    ((char*)dest)[i] = ((char*)src)[i];
  }
}
*/

char text_next[] = "NEXT";
volatile int* setleds = (volatile int*) 0xbf886110;

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{ 
  volatile int* trisE = (volatile int*) 0xbf886100;
  *trisE = (*trisE & ~(0xff)) | (~(0xff));

  TRISD = TRISD & 0x0EF0; //0x0EF0
  return;
}

int flipped_switch(){
  int flipped = getsw();
  switch(flipped){
    case 8: return 1;
    case 4: return 2;
    case 2: return 3;
    case 1: return 4;
    default: return 0;
  }
}

int pressed_button(){
  int btn = getbtns();
  switch(btn){
    case 4: return 1;
    case 2: return 2;
    case 1: return 3;
    default: return 0;
  }
}

#define SEQUENCE_LEN 100 // 100 cause of the memory limitation

/* This function is called repetitively from the main program */
void labwork( void ){

  int i;

  int list[SEQUENCE_LEN]; // = {1,2,3,1,3,1,2,2,1,2,1,3,1,2};

  for (i = 0; i < SEQUENCE_LEN; i++)
    list[i] = rand();

  int level = 1;
  int j;
  int end_of_game = 0;
  int difficulty = flipped_switch();

  for(i=0;i < SEQUENCE_LEN;i++){
 
    display_string(0, "LVL:");
    display_string(2, itoaconv(level));
    delay(100);
    display_update();
    delay(100);

    for(j=0;j<=i;j++){
      show_sequence_item(list[j], difficulty);
    }

    for(j = 0;j<=i;j++){
      int pressed = 0;
      while(pressed == 0){
        pressed = pressed_button();
        delay(10);
      }

      if (pressed != list[j]) {
        display_image(0,dead1);
        //display_string(3,"DEAD  DEAD  DEAD");
        delay(1000);
        display_update();
        delay(1000);
        // here display: OUGHHHH!!!! YOU ARE WRONG!
        end_of_game = 1;
        break;
      }
    }

    level++;

    if (end_of_game == 1){
      level = 0;
      break;
    }

    if (end_of_game == 1){
      end_of_game = 0;
      main();
    }
 


    display_image(32, black_square);
    display_image(64, black_square);
    display_image(96, black_square);
    delay( 200 );
    display_update();
    display_string(3, "YOUR TURN!");
    delay( 100 );
    display_update();
  }
  
  display_update();
}
