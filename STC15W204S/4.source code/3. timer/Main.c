#include "stc15f104e.h"

#include <string.h>


unsigned int idata guiTimer1S = 30;
//unsigned int idata guiTimer1S = 85937;
sbit LED3 = P3 ^ 3;


void timer0int() interrupt 1
{
       EA = 0;
	   TH0 = 0xFA;
	   TL0 = 0x00;
	   
   	   guiTimer1S--;
	   if (0 == guiTimer1S){
	       guiTimer1S = 4000;
		   LED3 = ~LED3;
	   }
	   
	   
	   EA = 1;
}

void init_timer0(){
		
		AUXR = 0x80; //timer 0   1T    mode 
		//TMOD = 0x02;  // internal  timer   ,    8 bit 
		TMOD = 0x01;
		//TH0 = TL0 = 0x00;
		
		TH0 = 0xFA;
		TL0 = 0x00;

		TR0 = 1; 
		ET0 = 1;
		EA  = 1;
		



}

void main(){

    LED3 = 1;
    init_timer0();
	while(1);
}
