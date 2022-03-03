/* 
   This file written/modified 2022 by Marta K Gludkowska and David Holmertz
	For the course Datorteknik at KTH 
*/

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for the game */

char text_intro[] = "Simon says, u do.";
char text_press_to_play[] = "Press to play.";
char text_setdif[] = "Set difficulty";
int seed = 0;
int switch_flipped = 0;
int lives = 0;
int level = 0;
int high_score = 0;
int initialize_leds = 1;

int main(void) {
	SYSKEY = 0xAA996655;  /* Unlock OSCCON, step 1 */
	SYSKEY = 0x556699AA;  /* Unlock OSCCON, step 2 */
	while(OSCCON & (1 << 21)); /* Wait until PBDIV ready */
	OSCCONCLR = 0x180000; /* clear PBDIV bit <0,1> */
	while(OSCCON & (1 << 21));  /* Wait until PBDIV ready */
	SYSKEY = 0x0;  /* Lock OSCCON */
	
	/* Set up output pins */
	AD1PCFG = 0xFFFF;
	ODCE = 0x0;
	TRISECLR = 0xFF;
	PORTE = 0x0;
	
	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;
	
	/* Set up input pins */
	TRISDSET = (1 << 8);
	TRISFSET = (1 << 1);
	
	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	/* SPI2STAT bit SPIROV = 0; */
	SPI2STATCLR = 0x40;
	/* SPI2CON bit CKP = 1; */
    SPI2CONSET = 0x40;
	/* SPI2CON bit MSTEN = 1; */
	SPI2CONSET = 0x20;
	/* SPI2CON bit ON = 1; */
	SPI2CONSET = 0x8000;
	
	display_init();

	labinit(); /* Initializations */

	while (1) {
		lives = 1;
		level = 1;

		for(initialize_leds = 1; initialize_leds <= 256; initialize_leds *= 2){
			setleds(initialize_leds - 1);
			delay(50);
		}

		clear_display();
		display_string(0, text_intro);
		display_string(1, text_setdif);
		display_string(3, text_press_to_play);
		delay(150);
		display_update();

		while(getbtns() == 0) {
			seed++;
		}
	
		switch_flipped = flipped_switch();

		clear_display();
	
		while(lives >= 0) {
   		labwork(); /* Game loop*/
		}

   	display_image(32,dead1);
   	display_image(64,dead2);
   	
   	int i;
   	for(i = 0; i < 10; i++){
   		setleds(0xff);
   		delay(50);
   		setleds(0x00);
   		delay(50);	
   	}
   	
   	display_update();
   	clear_display();

   	if (level > high_score)
   		high_score = level;

   	display_string(0, "Score:");
   	display_string(1, itoaconv(level));
   	display_string(2, "High score:");
   	display_string(3, itoaconv(high_score));
   	delay(100);
   	display_update();
   	delay(1500);
	}	
	
	return 0;
}
