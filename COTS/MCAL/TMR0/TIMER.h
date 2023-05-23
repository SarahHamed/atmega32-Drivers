/*
 * TIMER.h
 *
 * Created: 3/10/2023 5:57:56 PM
 *  Author: Sarah
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../LIB/STD_TYPES.h"
#define F_CPU 8000000
#define TIMR0_RESOLUTION	8

typedef struct  
{
	u8 Mode;
	u8 Prescalar;
	u8 Preload;
	u8 CompMatchValue;
	u8 OverFlowIntEn;
	u8 CompMatchIntEn;
}TMR0Config_t;

typedef enum
{
	TMR0_Ok,
	TMR0_Nok,
	TMR0_NullPtr
}TMR0_enuErrorStatus;

#define PRESCALER_CLR_MASK	0b11111000
	
typedef enum
{
	TIMR0_enuPrescalerNone=0b00000001,
	TIMR0_enuPrescaler_8=0b00000010,
	TIMR0_enuPrescaler_64=0b00000011,
	TIMR0_enuPrescaler_256=0b00000100,
	TIMR0_enuPrescaler_1024=0b00000101,
}TIMR0_tenuPresacaler;

typedef void (*TMR0cbf_t)(void);

void TMR0_vidInitPreCompile(void);
void TMR0_vidInitPostCompile(TMR0Config_t TIMR0Config);
/* Set required time */
TMR0_enuErrorStatus TMR0_enuSetTickTimeMS(u16 Copy_u16TickTime, u8 *Add_pu8TovCountValue,u8 *Add_pu8TovPreloadValue);	//eh momkn ykon l err hena?
TMR0_enuErrorStatus TMR0_enuStart(void);
TMR0_enuErrorStatus TMR0_enuRegisterCallback(TMR0cbf_t TMR0_pvCallBackFunc);
void __vector_10(void)__attribute__((signal));


#endif /* TIMER_H_ */