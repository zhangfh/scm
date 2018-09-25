#include "reg51.h"

typedef unsigned char   BYTE;
typedef unsigned int    WORD;

#define FOSC  	11074000L

#define T1MS (65536 - FOSC/1000)

unsigned int idata guiTimer1S = 500;

sfr AUXR  = 0x8e;   //Auxiliar register

sbit LED3 = P3 ^ 3;


void timer0int() interrupt 1
{
       EA = 0;
	   TL0 = T1MS;
	   TH0 = T1MS>>8;
	   
   	   guiTimer1S--;
	   if (0 == guiTimer1S){

	       guiTimer1S = 500;
		   LED3 = ~LED3;
	   }
	   
	   
	   EA = 1;
}

void init_timer0(){
		
		AUXR |= 0x80; //timer 0   1T    mode 
		TMOD = 0x00; //mode 0 
 
		TL0 = T1MS;
		TH0 = T1MS>>8;

		TR0 = 1; 
		ET0 = 1;
		EA  = 1;
		
}

void main(){

    LED3 = 1;
    init_timer0();
	while(1);
}