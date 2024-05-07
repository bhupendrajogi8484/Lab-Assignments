#include<pic18f4550.h>
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF

#define LCD_DATA PORTD
#define ctrl PORTB
#define RS PORTBbits.RB0
#define RW PORTBbits.RB1
#define EN PORTBbits.RB2

void init_LCD(void);
void cmd(unsigned char command);
void data(unsigned char data);
void LCD_writestring(char *str);
void delay(unsigned int time);

void main(void){
	char var1[] = "WELCOME";
	char var2[] = "To SE-IT";
	ADCON1 = 0x0F;
	TRISD = 0x00;
	TRISB = 0x00;
	init_LCD();
	delay(50);
   LCD_writestring(var1);
	delay(150);
	cmd(0xC0);
	LCD_writestring(var2);

	while(1);
}
void init_LCD(void){
	cmd(0x38);
	delay(15);
	cmd(0X01);
	delay(15);
	cmd(0X0C);
	delay(15);
	cmd(0X80);
	delay(15);
}
void cmd(unsigned char command){
	LCD_DATA = command;
	RS = 0;
	RW = 0;
	EN = 1;
	delay(15);
	EN = 0;
}
void data(unsigned char data){
	LCD_DATA = data;
	RS = 1;
	RW = 0;
	EN = 1;
	delay(15);
	EN = 0;
}
void delay(unsigned int time){
	int i,j;
	for(i=0 ;i<time; i++)
    	for(j=0; j<=710; j++);
}
void LCD_writestring(char *str){
	int i = 0;
	while(str[i] != '\0'){
    	data(str[i]);
    	delay(15);
    	i++;
	}
}
