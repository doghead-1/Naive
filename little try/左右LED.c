#include "reg52.h" //此文件中定义了单片机的一些特殊功能

#include<intrins.h>		//因为要用到左右移函数，所以加入这个头文件

typedef unsigned int u16; //对数据类型进行声明定义
typedef unsigned char u8;

u8 KeyValue;

sbit k1=P3^1; //定义P31 口是k1
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;
#define led P2

void delay(u16 i)
{
while(i--);
}

int keypros()
{

if(k1==0) //检测按键K1 是否按下
{
delay(1000); //消除抖动一般大约10ms
if(k1==0) //再次判断按键是否按下
{
KeyValue=1; //led 状态取反
}
while(!k1);
 //检测按键是否松开
}

if(k2==0) //检测按键K1 是否按下
{
delay(1000); //消除抖动一般大约10ms
if(k2==0) //再次判断按键是否按下
{
KeyValue=2; //led 状态取反
}
while(!k2);
 //检测按键是否松开
}

}

void main()
{

led=~0x7F;
while(1)
{
keypros(); //按键处理函数
	
	
	 //大约延时450ms	
	if(KeyValue==1)
	{

			led=_crol_(led,1);
			delay(1000);
			
			}
			delay(100);
			//KeyValue=0;
		if(KeyValue==2)
	{

			led=_cror_(led,1);
			delay(1000);
			
			}
			delay(100);
			KeyValue=0;
}
}