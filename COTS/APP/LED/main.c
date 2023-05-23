/*
 * DIO.c
 *
 * Created: 1/13/2023 4:20:48 PM
 * Author : Sarah
 */ 

//#include <avr/io.h>

#define F_CPU 1000000UL
#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/LED/LED.h"
#include "util/delay.h"


int main(void)
{
	//DIO_enuInit();
	
    while (1) 
    {
		for(u8 i=0;i<8;i++)
		{
			for(u8 j=0;j<8;j++)
			{
				
				if(i==j)
					LED_enuLedON(j);
				else
					LED_enuLedOFF(j);
			}
			_delay_ms(1000);
		}
		
		for(s8 i=7;i>=0;i--)
		{
			for(s8 j=7;j>=0;j--)
			{
				
				if(i==j)
				LED_enuLedON(j);
				else
				LED_enuLedOFF(j);
			}
			_delay_ms(1000);
		}
		
    }
}

