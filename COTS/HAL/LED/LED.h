#ifndef LED_H
#define LED_H


#include "../../LIB/STD_TYPES.h"
#include "LED_Cfg.h"

#define Active_High	DIO_INPUT_PULL_DOWN
#define Active_Low	DIO_INPUT_PULL_UP


typedef enum
{
	LED_enuOK=0,
	LED_enuNotOK,
	LED_enuInvalidVal
}LED_enuErrorStatus;


LED_enuErrorStatus LED_enuLedON(u8 LED_number);
LED_enuErrorStatus LED_enuLedOFF(u8 LED_number);

#endif


