/*
 * s7SegTest.c
 *
 * Created: 1/20/2023 2:50:47 PM
 * Author : Sarah
 */ 

//#include <avr/io.h>
#define F_CPU 1000000
#include "../HAL/SevenSegment/SSEG.h"
#include "../HAL/SevenSegment/SSEG_Cfg.h"


#include "util/delay.h"



int main(void)
{
	DIO_enuInit();
	
    while (1) 
    {
		for(u8 i=0;i<10;i++)
		{
			SSEG_enuDisplayNum(SSEG_PORT_1, i);
			
			for(u8 j=0;j<10;j++){
				
				SSEG_enuDisplayNum(SSEG_PORT_2, j);
				
				_delay_ms(1000);
			}
			
		}
		
    }
	
}

