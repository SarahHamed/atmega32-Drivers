/*
 * Switch.h
 *
 * Created: 1/19/2023 2:46:57 AM
 *  Author: Sarah
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "../../LIB/STD_TYPES.h"

typedef enum
{
	SWITCH_enuOK=0,
	SWITCH_enuNotOK,
	SWITCH_enuNullPtr,
	SWITCH_InvalidPortNum,
	SWITCH_InvalidPinNum,
	SWITCH_enuInvalidVal
	
}SWITCH_tenuErrorStatus_t;


#define SWITCH_ON	1
#define SWITCH_OFF	0

SWITCH_tenuErrorStatus_t SWITCH_enuGETSwitchValue(u8 switchNumber, u8 *switchState);


#endif /* SWITCH_H_ */