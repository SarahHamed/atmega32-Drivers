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
#include "../../HAL/SWITCH/Switch.h"
#include "util/delay.h"


int main(void)
{
	DIO_enuInit();
	u8 switchStateInc=DIO_enuHigh;
	u8 switchStateDec=DIO_enuHigh;
	SWITCH_tenuErrorStatus_t errState=SWITCH_enuOK;
	s8 numberOfClicks=0;
	//_delay_ms(1000);
    while (1) 
    {
		switchStateInc=DIO_enuHigh;
		switchStateDec=DIO_enuHigh;
		//_delay_ms(100);
		errState=SWITCH_enuGETSwitchValue(8,&switchStateInc);
		errState=SWITCH_enuGETSwitchValue(9,&switchStateDec);
		
		
		if (errState == SWITCH_enuOK && switchStateInc == DIO_enuLow)
		{
			
			LED_enuLedON(numberOfClicks);
			if(numberOfClicks<8)
				numberOfClicks++;
		}
		else if (errState == SWITCH_enuOK && switchStateDec == DIO_enuLow)
		{
			if(numberOfClicks>0)
				numberOfClicks--;
			LED_enuLedOFF(numberOfClicks);
			
		}
			
		
    }
}

