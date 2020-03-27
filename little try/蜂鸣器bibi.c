#include "reg52.h"
sbit bibi=P2^5;
typedef unsigned int u16;
void delay(u16 i)
{
	while(i--);	
}
void main()
{
	int i=0;
	
	while(1)
	{i=0;	 
	while(i<1000)
	{
	     bibi=~bibi;
		 delay(50);
		 	i=i+1;
	}
	delay(9999999);
	}

}