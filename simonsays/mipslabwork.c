/* 
  This file written/modified 2022 by Marta K Gludkowska and David Holmertz
  For the course Datorteknik at KTH 
*/

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

extern int seed;
extern int switch_flipped;
extern int lives;
extern int level;

int rand(){
  seed = seed * 1103515245 + 12345;
  
  return (unsigned int)(seed/65536) % 3 + 1;
}

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

int pressed_button(){
  int btn = getbtns();
  switch(btn){
    case 4: return 1;
    case 2: return 2;
    case 1: return 3;
    default: return 0;
  }
}

void show_lives(){
  int ledvalue = 0;
  switch(lives){
    case 1: 
      ledvalue = 1;
      break;
    case 2: 
      ledvalue = 3;
      break;
    case 3: 
      ledvalue = 7;
      break;
    case 4: 
      ledvalue = 15;
      break;
    case 5: 
      ledvalue = 31;
      break;
    case 6: 
      ledvalue = 63;
      break;
    case 7: 
      ledvalue = 127;
      break;
    case 8: 
      ledvalue = 255;
      break;
  }
  setleds(ledvalue);
}

#define SEQUENCE_LEN 100 // 100 cause of the memory limitation

/* This function is called repetitively from the main program */
void labwork( void ){

  int i;

  int list[SEQUENCE_LEN]; // = {1,2,3,1,3,1,2,2,1,2,1,3,1,2};

  for (i = 0; i < SEQUENCE_LEN; i++)
    list[i] = rand();

  int j;

  clear_display();
  show_lives();

  for(i=0;i < SEQUENCE_LEN;){
    int life_lost = 0;
 
    display_string(0, "LVL:");
    display_string(2, itoaconv(level));
    delay(100);
    display_update();
    delay(100);

    for(j=0;j<=i;j++){
      show_sequence_item(list[j], switch_flipped);
    }
    
    display_string(3, "YOUR TURN!");
    delay( 200 );
    display_update();
    delay( 200 );
    clear_display();

    for(j = 0;j<=i;j++){
      int pressed = 0;
      int switched = 0;

      while(pressed == 0){
        pressed = pressed_button();
        delay(10);
      }

      if (pressed != list[j]) {
        lives--;
        life_lost = 1;
        clear_display();
        break;
      }
    }

    if (lives < 0){
      break;
    }

    show_lives(lives);

    if (life_lost == 0) { 
      display_image(96, heart);
      delay(200);
      display_update();
      delay(100);   
      level++;
      i++;
    }
  }
  
  display_update();
}
