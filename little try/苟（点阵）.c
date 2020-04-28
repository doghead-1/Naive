
#include "reg51.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "intrins.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;
u8 ledNum;

//--定义使用的IO口--//
sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

u8 ledx[]={0x48,0x70,0xD6,0x5A,0x5C,0xD2,0x5F,0x40};
u8 ledy[]={0x02,0xFA,0x4B,0x3A,0x5A,0x6B,0x0E,0x12};

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，i=1时，大约延时10us
*******************************************************************************/
void delay(u16 i)
{
	while(i--);
	
}

void led1(u8 dat1)
{
	P0=dat1;
}

/*******************************************************************************
* 函 数 名         : Hc595SendByte(u8 dat)
* 函数功能		   : 想74H595发送一个字节的数据
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Hc595SendByte(u8 dat)
{
	u8 a;

	SRCLK = 1;
	RCLK = 1;

	for(a=0;a<8;a++)		 //发送8位数
	{
		SER = dat >> 7;		 //从最高位开始发送
		dat <<= 1;

		SRCLK = 0;			 //发送时序
		_nop_();
		_nop_();
		SRCLK = 1;	
	}
	RCLK = 0;
	_nop_();
	_nop_();
	RCLK = 1;
}


/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	u8 a=0x7F;
	u8 i=0;	  
	//led1(0x12);
	while(1)
	{
		for(i=0;i<8;i++)
		{
			Hc595SendByte(ledx[i]);
			led1(a);
			a = _cror_(a, 1);
			//delay(1000000);
			//delay(1000000);
			//delay(1000000);
			//delay(1000000);
			delay(1);
		}
	}		
}