 #include "../../config.h"
#include "../inc/RS-232.h"

// AT89S51中断
// 中断描述				中断号				中断入口地址			 
// 外部中断0(INT0)		0					0003H
// 定时/计数器0(T1)		1					000BH
// 外部中断1(INT1)		2					0013H
// 定时/计数器1(T1)		3	 				001BH
// 串行口中断(RI/TI)	4  					0023H
// AT89S52特有中断
// 定时/计数器2(T2)		5					002BH

void uart_initial(void)
{
	// SCON: 模式1, 8-bit UART, 使能接收  
	SCON = SCON_UART_MODE_1 | SCON_UART_REN_ENABLE;

	// 波特率加倍
	PCON |= PCON_UART_SMOD_ENABLE;
	
	// 定时器1工作于模式2
	TMOD |= TMOD_TIMER1_MODE_2;

	// 波特率9600初值
	TH1 = 0xFA; 
	TL1 = 0xFF;
    //AUXR |= 0x40;

	TI = 0;
	// 启动定时器1
	TR1 = 1;

	// 打开总中断
	EA = 1; 

	// 打开串口中断
	ES = 1;	
} 