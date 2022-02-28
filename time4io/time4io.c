#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h" 

int getsw( void ){
    int SW = ((PORTD>>8) & 0x000f);     //shifting bits so that value 11-8 (SW4, SW3, SW2, SW1) is masked and returned
    return SW; 
}
int getbtns(void){
    int BTN = ((PORTD>>5) & 0x0007);     //shifting bits so that value 8-5 (BTN4,BTN3,BTN2) is masked and returned
    return BTN;
}