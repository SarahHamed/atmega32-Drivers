/*
 * Switch.c
 *
 * Created: 1/19/2023 2:56:04 AM
 *  Author: Sarah
 */ 

#define F_CPU 1000000UL

#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_MATH.h"
#include "Switch.h"
#include "Switch_Cfg.h"
#include "util/delay.h"




SWITCH_tenuErrorStatus_t SWITCH_enuGETSwitchValue(u8 switchNumber, u8 *switchState)
{
	DIO_tenuErrorStatus_t Loc_enuErrorStatus= SWITCH_enuOK;
	DIO_tenuPinValue pinState=SWITCH_NotPressed;
	u8 u8_numberOfChecks=0;
	
	do 
	{
		Loc_enuErrorStatus=DIO_enuGetPin(switchNumber, &pinState);
		_delay_ms(10);
		u8_numberOfChecks++;
	} while (pinState == Active_State);
	
	if(u8_numberOfChecks>5)
		*switchState = SWITCH_Pressed;
	else
		*switchState = SWITCH_NotPressed;
		
	return	Loc_enuErrorStatus;
}