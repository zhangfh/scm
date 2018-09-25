 #include "../../config.h"
#include "../inc/RS-232.h"

// AT89S51�ж�
// �ж�����				�жϺ�				�ж���ڵ�ַ			 
// �ⲿ�ж�0(INT0)		0					0003H
// ��ʱ/������0(T1)		1					000BH
// �ⲿ�ж�1(INT1)		2					0013H
// ��ʱ/������1(T1)		3	 				001BH
// ���п��ж�(RI/TI)	4  					0023H
// AT89S52�����ж�
// ��ʱ/������2(T2)		5					002BH

void uart_initial(void)
{
	// SCON: ģʽ1, 8-bit UART, ʹ�ܽ���  
	SCON = SCON_UART_MODE_1 | SCON_UART_REN_ENABLE;

	// �����ʼӱ�
	PCON |= PCON_UART_SMOD_ENABLE;
	
	// ��ʱ��1������ģʽ2
	TMOD |= TMOD_TIMER1_MODE_2;

	// ������9600��ֵ
	TH1 = 0xFA; 
	TL1 = 0xFF;
    //AUXR |= 0x40;

	TI = 0;
	// ������ʱ��1
	TR1 = 1;

	// �����ж�
	EA = 1; 

	// �򿪴����ж�
	ES = 1;	
} 