/* simon.h
   Header file for the game Simon Says.
   This file written 2022 by MK Gludkowska
   Some parts are original code written by Axel Isaksson
*/

/* Declare display-related functions from simonsays.c */
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);

/* Declare game-related functions from simonsays.c */
char * itoaconv( int num );;
void quicksleep(int cyc);

/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing a square */
extern const uint8_t const square[128];
/* Declare bitmap array containing a simon-pointed square */
extern const uint8_t const simon_square[128];
/* Declare bitmap array containing heart */
extern const uint8_t const heart[128];
/* Declare bitmap array containing little heart */
extern const uint8_t const lil_heart[8];
/* Declare text buffer for display output */
extern char textbuffer[4][16];
/*extern char lil_textbuffer[3][12]; */

/* Declare functions */
/* void delay(int);
void time2string( char *, int ); */

int getbtns(void);
int getsw(void);
void enable_interrupt(void);
