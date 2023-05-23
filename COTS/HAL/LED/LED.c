#include "LED.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_MATH.h"
#include "LED_Cfg.h"


LED_enuErrorStatus LED_enuLedON(u8 LED_number)
{
	if(LED_number > DIO_enuNumberOfPins)
	{
		return LED_enuInvalidVal;
	}
	else
	{
		DIO_enuSetPinDirection(LED_number,DIO_enuOutput);
		DIO_enuSetPin(LED_number);
	}
	return LED_enuNotOK;
}

LED_enuErrorStatus LED_enuLedOFF(u8 LED_number)
{
	if(LED_number > DIO_enuNumberOfPins)
	{
		return LED_enuInvalidVal;
	}
	else
	{
		DIO_enuSetPinDirection(LED_number,DIO_enuInput);
		DIO_enuSetPin(LED_number);
	}
		
	return LED_enuOK;
} 