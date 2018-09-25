#include "stc15f104e.h"

#include <string.h>
#include "public/inc/RS-232.h"
#include "public/inc/timer.h"
#include "public/inc/delay.h"  


sbit LED3 = P3 ^ 3;


void main(void) 
{

    LED3 = 0;


	while(1) 
	{ 
		LED3 = ~LED3;

		delay_ms(1000);	
	} //end of while
}


