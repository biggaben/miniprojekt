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

char text_look[] = "LOOK";
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

/* This function is called repetitively from the main program */
void labwork( void )
{
  
  display_string(0, (char*)time );
  display_image(32, square);
  display_image(64, square);
  display_image(96, square);
  delay( 1000 );
  
  display_update();

}
