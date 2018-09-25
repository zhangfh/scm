#include "stc15f104e.h"

#include <string.h>
#include "public/inc/RS-232.h"
#include "public/inc/timer.h"
#include "public/inc/delay.h" 

sbit LED3 = P3 ^ 3;
sbit  Press_KEY = P3 ^ 2 ;

char get_key_status()
{
   	char key_value = 0	;

	key_value =   Press_KEY	   ;

	if (key_value == 1) {

	    return  0;
	}else{
	    return 1;
	}
}

void EX0init(void)
{
       //page 550
       IT0 = 0;   //指定外部中断0下降沿触发，INT0 (P3.2)		,   
       //page 547
	   EX0 = 1;   //使能外部中断
 	   //page 547
       EA = 1;    //开总中断
}

//page 545 
void Ex0_ISR(void)  interrupt 0
{
    char key_value = 0	;
	key_value = get_key_status();

	EX0 = 0;

	if (key_value == 1) {
	   //key press
		 LED3 = 1;
		 delay_ms(1000);	
	} else {
		 LED3 = 0;
		 delay_ms(1000);	
    }

	EX0 = 1;

}


void main(void) 
{
    /*
	char key_value = 0	;

	key_value =   Press_KEY	   ;

    
    LED3 = 0;

	if (key_value == 1)		  //key is  not  pressed
	{
	     LED3 = 1;
    }else{
	     LED3 = 0;
	}
    */
	LED3 = 0;
    EX0init();
	while(1){
	}

}

