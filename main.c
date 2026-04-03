#include <at89c51RC2.h>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

#define SPEED   1000
#define P0	0
#define L1	1
#define L1_	2
#define L2	3
#define L2_	4
#define L3	5
#define L4	6
#define L4_	7
#define L5	8
#define L5_	9
#define L6	10
#define L6_	11
#define L7	12
#define M1	13
#define M1_	14
#define M2	15
#define M2_	16
#define M3	17
#define M4	18
#define M4_	19
#define M5	20
#define M5_	21
#define M6	22
#define M6_	23
#define M7	24
#define H1	25
#define H1_	26
#define H2	27
#define H2_	28
#define H3	29
#define H4	30
#define H4_	31
#define H5	32
#define H5_	33
#define H6	34
#define H6_	35
#define H7	36


unsigned int FreqTable[]={
	0,
63777, 63872, 63969, 64054, 64140, 64216, 64291, 64360, 64426, 64489, 64547, 64607, 
64655, 64704, 64751, 64795, 64837, 64876, 64913, 64948, 64981, 65012, 65042, 65070,
65095, 65120, 65144, 65166, 65186, 65206, 65225, 65242, 65259, 65274, 65289, 65303,
};

unsigned char code Music[]={
//来自天堂的魔鬼
	//夜里做了美丽的噩梦
	//1
M6,2,
M6,2,
M6,1,
H1,1,
M6,1,
H1,1,
H5,2,
H1,2,
H1,2+1,
H2,1,
//2
H3,2,
H3,2,	
H3,1,
H4,1,
H3,1,	
H4,1,
H3,2,
H2,2,
H2,2,
H1,1,
M7,1,
//3
M6,2,
M2,2,
M6,1,
H1,1,
M1,1,
H1,1,
H5,2,
H1,2,
H1,2+1,
H2,1,
//4
H3,1,
H3,1,
H3,2,
H3,2,
H2,1,
H1,1,
M7,4,
H1,2,
H2,2,
//5
H3,2,
H3,2,
H3,2,
H1,2,
H4,2,
H4,2,
H4,2,
H1,2,
//6
M4,1,
M5,1,
M5,2,
M3,1,
M4,1,
M3,1,
M4,1,
M3,2,
M2,2,
M2,2,
M1,1,
M7,1,
//7
M6,2,
M6,2,
M6,1,
M1,1,
M6,1,
M1,1,
M5,2,
M1,2,
M1,2,
M2,1,





	0xFF
};

unsigned char FreqSelect,MusicSelect;

void main()
{
	
	Timer0_Init();
	while(1)
	
	{	
		if(Music[MusicSelect]!=0xFF)//如果不等于终止符，才执行下面的操作
		{		
			FreqSelect=Music[MusicSelect];
			MusicSelect++;
		Delay(SPEED/4*Music[MusicSelect]);
		MusicSelect++;
		TR0=0;
		Delay(5);
		TR0=1;

		}
		else
		{
			TR0=0;
			while(1);//如果是中止就死循环
		}
	}
	
}

void Timer0_Routine() interrupt 1
	{
		if(FreqTable[FreqSelect])
		{	
		TL0 = FreqTable[FreqSelect]%256;		//设置定时初值
		TH0 = FreqTable[FreqSelect]/256;		//设置定时初值
		Buzzer=!Buzzer;

		}

}


