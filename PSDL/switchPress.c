#include <p18f4520.h>
#include <stdio.h>
#define direction TRISB
void msdelay(unsigned int val);

void main(){
    OSCCON = 0x72;
    direction = 0;
    PORTB = 0;

    while(1){
    PORTB = 0xFF;
    msdelay(1000);
     PORTB = 0x00;
    msdelay(1000);
    }
}

void msdelay(unsigned int  val){
    unsigned int i,j;
    for(i=0; i<val; i++)
            for(j=0; j<165; j++);
}
