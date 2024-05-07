#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

void main(void){
  int dividend,divisor,quotient;
  int result,i;
  dividend = 0x0E;
  divisor = 0x04;
  result = dividend;
  quotient  = 0;
  while(1){
	if(divisor == 0)
		result = 0;
else if(result < divisor)
		break;
else{
	result = result – divisor;
	quotient = quotient + 1;
}
}
TRISA = 0;
PORTA = result;
TRISB = 0;
PORTB = quotient;
TRISC = 0;
PORTC = divided / divisor;
}
