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

int mytime = 0x5957;
int counter = 0;
int light_switch = 0;
char textstring[] = "text, more text, and even more text!";
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

  //volatile int* trisD = (volatile int*) 0xbf8860C0;
  //*trisD = (*trisD | 0x07f0);
  TRISD = TRISD & 0x0EF0; //0x0EF0
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  delay( 1000 );
  
  if(light_switch = 0){
    *setleds = 0x0000;
    light_switch = 1;
  }else if(light_switch = 1){
    *setleds = 0xffff;
    light_switch = 0;
  }
  

  tick( &mytime );
  //*setleds = (*setleds & (~0xff)) | (counter & 0x00ff);
  counter++;
  display_image(96, icon);

  if( getbtns() != 0 ){
    if( getbtns() & 1 ) mytime = (mytime & ~0xf0) | ( getsw() << 4 );
    if( getbtns() & 2 ) mytime = (mytime & ~0xf00) | ( getsw() << 8 );
    if( getbtns() & 4 ) mytime = (mytime & ~0xf000) | ( getsw() << 12 );
  }

  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  /*
  int buttons = getbtns();
  int switches = getsw();
    if (buttons != 0)
    {
       int switches = getsw() << 4;
    }
  int leds = switches | buttons;

  *setleds = leds;
  */
}

/*
  Lampor kräver 8 bitar = 128 i decimalform = 2 HEXdecimaltal
  0 -> 15 = 0 -> F
*/