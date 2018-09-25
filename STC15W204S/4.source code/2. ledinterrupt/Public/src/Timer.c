#include "../../config.h"
#include "../inc/Timer.h"

// AT89S51�ж�
// �ж�����				�жϺ�				�ж���ڵ�ַ			 
// �ⲿ�ж�0(INT0)		0					0003H
// ��ʱ/������0(T1)		1					000BH
// �ⲿ�ж�1(INT1)		2					0013H
// ��ʱ/������1(T1)		3	 				001BH
// ���п��ж�(RI/TI)	4  					0023H
// AT89S52�����ж�
// ��ʱ/������2(T2)		5					002BH

void timer0_initial()
{
	// ��ʱ��0������ģʽ2
	TMOD &= 0xF0;
	TMOD |= TMOD_TIMER0_MODE_2;

	TH0 = TIME0_INITIAL; 
	TL0 = 0xFF;	
	
	// �����ж�
	EA = 1;		
	ET0 = 1;

	// ������ʱ��0
	TR0 = 1;
}

#if 0
void timer1_initial()
{
	// ��ʱ��1������ģʽ2
	TMOD &= 0x0F;
	TMOD |= TMOD_TIMER1_MODE_2;

	// 167us
	TH1 = 0x66; 
	TL1 = 0xFF;	
	
	// �����ж�
	EA = 1;		
	ET1 = 1;

	// ������ʱ��1
	TR1= 1;
}
#endif