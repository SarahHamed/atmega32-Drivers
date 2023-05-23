/*
 * KEYPAD.c
 *
 * Created: 2/1/2023 5:02:06 PM
 *  Author: Sarah
 */ 
#include "KEYPAD.h"
#include "KEYPAD_Cfg.h"
#include "../../HAL/SWITCH/Switch.h"
#include "../../HAL/SWITCH/Switch_Cfg.h"
#include "../../MCAL/DIO/DIO.h"

void KEYPAD_GetKey(u8* ptr_pressedPin)
{
	u8 KPD_PinState=0;
	KPD_tenuErrorStatus_t errState=KPD_enuOK;
	
	for(u8 i=0;i<ROW_MAX;i++)
	{
		DIO_enuClearPin(KPD_strPinCfg[i+ROW_MAX].DIO_PinNumber);
		
		for(u8 j=0;j<COL_MAX;j++)
		{
			errState = SWITCH_enuGETSwitchValue( KPD_strPinCfg[j].DIO_PinNumber , &KPD_PinState);
			if (errState == KPD_enuOK && KPD_PinState == Active_State)
			{
				*ptr_pressedPin=i*ROW_MAX+j;
			}
		}
		DIO_enuSetPin(KPD_strPinCfg[i+ROW_MAX].DIO_PinNumber);
		
	}
}