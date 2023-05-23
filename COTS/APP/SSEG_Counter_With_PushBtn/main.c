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
#include "../HAL/SWITCH/Switch.h"

#include "util/delay.h"


int main(void)
{
	DIO_enuInit();
	u8 switchStateInc=DIO_enuHigh;
	u8 switchStateDec=DIO_enuHigh;
	SWITCH_tenuErrorStatus_t errState=SWITCH_enuOK;
	s8 numberOfClicks=0;
	
	while (1)
	{
		switchStateInc=DIO_enuHigh;
		switchStateDec=DIO_enuHigh;
		//_delay_ms(100);
		errState=SWITCH_enuGETSwitchValue(8,&switchStateInc);
		errState=SWITCH_enuGETSwitchValue(9,&switchStateDec);
		
		
		if (errState == SWITCH_enuOK && switchStateInc == DIO_enuLow)
		{
			SSEG_enuDisplayNum(SSEG_PORT_1, (numberOfClicks%10));
			SSEG_enuDisplayNum(SSEG_PORT_2, (numberOfClicks/10));
			if(numberOfClicks<100)
			numberOfClicks++;
		}
		else if (errState == SWITCH_enuOK && switchStateDec == DIO_enuLow)
		{
			if(numberOfClicks>0)
			numberOfClicks--;
			SSEG_enuDisplayNum(SSEG_PORT_1, (numberOfClicks%10));
			SSEG_enuDisplayNum(SSEG_PORT_2, (numberOfClicks/10));
			
		}
		
	}
}


