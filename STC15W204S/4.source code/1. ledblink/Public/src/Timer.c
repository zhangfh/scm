#include "../../config.h"
#include "../inc/Timer.h"

// AT89S51中断
// 中断描述				中断号				中断入口地址			 
// 外部中断0(INT0)		0					0003H
// 定时/计数器0(T1)		1					000BH
// 外部中断1(INT1)		2					0013H
// 定时/计数器1(T1)		3	 				001BH
// 串行口中断(RI/TI)	4  					0023H
// AT89S52特有中断
// 定时/计数器2(T2)		5					002BH

void timer0_initial()
{
	// 定时器0工作于模式2
	TMOD &= 0xF0;
	TMOD |= TMOD_TIMER0_MODE_2;

	TH0 = TIME0_INITIAL; 
	TL0 = 0xFF;	
	
	// 打开总中断
	EA = 1;		
	ET0 = 1;

	// 启动定时器0
	TR0 = 1;
}

#if 0
void timer1_initial()
{
	// 定时器1工作于模式2
	TMOD &= 0x0F;
	TMOD |= TMOD_TIMER1_MODE_2;

	// 167us
	TH1 = 0x66; 
	TL1 = 0xFF;	
	
	// 打开总中断
	EA = 1;		
	ET1 = 1;

	// 启动定时器1
	TR1= 1;
}
#endif