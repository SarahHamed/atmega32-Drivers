/*
 * EXTI.h
 *
 * Created: 1/27/2023 10:10:19 AM
 *  Author: Sarah
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

typedef enum
{
	EXTI_enuOK=0,
	EXTI_enuNotOK
}EXTI_tenuErrorStatus_t;

typedef void (*EXTICallBackFn_t)(void);

void EXTI0_AssignCBF(EXTICallBackFn_t CBF);
void EXTI1_AssignCBF(EXTICallBackFn_t CBF);
void EXTI2_AssignCBF(EXTICallBackFn_t CBF);

//void EXTI_AssignCBF(EXTICallBackFn_t CBF);

void EXTI_enuEnableINT0(void);
void EXTI_enuEnableINT1(void);
void EXTI_enuEnableINT2(void);

void EXTI0_enuInit();
void EXTI1_enuInit();
void EXTI2_enuInit();


#endif /* EXTI_H_ */