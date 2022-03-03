/* 
   This file written/modified 2022 by Marta K Gludkowska and David Holmertz
   For the course Datorteknik at KTH 
*/

// Graphics

extern const uint8_t const font[128*8];
extern const uint8_t const black_square[128];
extern const uint8_t const square[128];
extern const uint8_t const simon_square[128];
extern const uint8_t const heart[128];
extern const uint8_t const dead1[128];
extern const uint8_t const dead2[128];
extern char textbuffer[4][16];

/* Declare display-related functions from mipslabfunc.c */
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
void clear_display(void);
uint8_t spi_send_recv(uint8_t data);

/* Declare game-related functions from mipslabfunc.c */
char * itoaconv( int num );
void labwork(void);
void quicksleep(int cyc);

/* Declare display_debug */
void display_debug( volatile int * const addr );

/* Written as part of i/o lab: getbtns, getsw, enable_interrupt */
int getbtns(void);
int getsw(void);
void setleds(int);
void enable_interrupt(void);