/* mipslabdata.c
   This file compiled 2015 by F Lundevall
   from original code written by Axel Isaksson

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

char textbuffer[4][16];

const uint8_t const font[] = {
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
};

const uint8_t const icon[] = {
	/*
	255, 255, 255, 255, 255, 255, 127, 187,
	68, 95, 170, 93, 163, 215, 175, 95,
	175, 95, 175, 95, 223, 111, 175, 247,
	59, 237, 242, 254, 171, 254, 1, 255,
	255, 255, 15, 211, 109, 58, 253, 8,
	178, 77, 58, 199, 122, 197, 242, 173,
	242, 237, 186, 215, 40, 215, 41, 214,
	64,64,64,64,64,64,64,64,
	64,64,64,64,64,64,64,64,
	64,64,64,64,64,64,64,64,
	64,64,64,64,64,64,64,64,
	120,120,120,120,120,120,120,120,
	120,120,120,120,120,120,120,120,
	120,120,120,120,120,120,120,120,
	120,120,120,120,120,120,120,120,
	120,120,120,120,120,120,120,120,
	*/
	/*
	0,0,0,0,0,0,0,0,
	128,64,32,16,8,4,2,1,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	127,127,127,127,127,127,127,127,
	*/

	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
};


	/*
	35, 175, 91, 212, 63, 234, 149, 111,
	171, 84, 253, 252, 254, 253, 126, 184,
	195, 52, 201, 22, 225, 27, 196, 19,
	165, 74, 36, 146, 72, 162, 85, 8,
	226, 25, 166, 80, 167, 216, 167, 88,
	106, 149, 161, 95, 135, 91, 175, 87,
	142, 123, 134, 127, 134, 121, 134, 121,
	132, 59, 192, 27, 164, 74, 177, 70,
	184, 69, 186, 69, 254, 80, 175, 217,
	*/

const uint8_t const display_startup[] = {
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
	255,207,147,147,159,147,147,207,
};
