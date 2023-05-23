/*
 * KEYPAD.h
 *
 * Created: 2/1/2023 5:02:26 PM
 *  Author: Sarah
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../LIB/STD_TYPES.h"
typedef enum
{
	KPD_enuOK=0,
	KPD_enuNotOK,
}KPD_tenuErrorStatus_t;

void KEYPAD_GetKey(u8* ptr_pressedPin);


#endif /* KEYPAD_H_ */