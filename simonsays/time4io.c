#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h" 

volatile int* led_port = (volatile int*) 0xbf886110;

int getsw( void ){
    int SW = ((PORTD>>9) & 0x0007);     //  shifting bits so that value 11-8 (SW4, SW3, SW2, SW1) is masked and returned
    return SW;  
}
                           //  4-2-1
int getbtns(void){
    int BTN = ((PORTD>>5) & 0x0007);    // shifting bits so that value 8-5 (BTN4,BTN3,BTN2) is masked and returned
    while (((PORTD>>5) & 0x0007) != 0)
        delay(10);

    return BTN;
}

void setleds(int value){
    *led_port = value & 0xff;
}