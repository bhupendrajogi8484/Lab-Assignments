#include <stdio.h>
#include <stdlib.h>
#include <p18f4520.h>

void delay(unsigned int itime);

#pragma config osc = HS
#pragma config PWRT = OFF
#pragma config WDT = OFF
#pragma config DEBUG = OFF
#pragma config LVP = OFF


void main(void){
  TRISD = 0;
{ while(1){
	PORTD = 0x00;
	delay(100);
	PORTD = 0xFF;
	delay(100);
  }
}
}

void delay(unsigned int itime){
  int i,j;
  for(i=0; i <= itime; i++)
  for(j=0; j<=1275; j++);
}
