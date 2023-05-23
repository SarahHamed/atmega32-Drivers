/*
 * EXTI.c
 *
 * Created: 1/27/2023 10:10:43 AM
 *  Author: Sarah
 */ 

#include "../DIO/DIO.h"
#include "EXTI_Prv.h"
#include "EXTI_Cfg.h"
#include "../GIE/GIE_Prv.h"
#include "../GIE/GIE_Cfg.h"
#include "EXTI.h"
#include <avr/interrupt.h>



EXTICallBackFn_t ApplicationCBF0;
EXTICallBackFn_t ApplicationCBF1;
EXTICallBackFn_t ApplicationCBF2;


void EXTI_enuEnableINT2()
{
	SET_BIT(GICR,GICR_INT2);
}
	
void EXTI_enuEnableINT1()
{
	SET_BIT(GICR,GICR_INT1);
}

void EXTI_enuEnableINT0()
{
	SET_BIT(GICR,GICR_INT0);
}


void EXTI0_enuInit()
{
	
	#if		INT0_MODE==INT0_MODE_FALLING_EDGE
			MCUCR|=INT0_MODE_FALLING_EDGE;
	#elif	INT0_MODE==INT0_MODE_RISING_EDGE
			MCUCR|=INT0_MODE_RISING_EDGE;
	#elif	INT0_MODE==INT0_MODE_ON_CHANGE
			MCUCR|=INT0_MODE_ON_CHANGE;
	#else
			MCUCR|=INT0_MODE_LOW_LEVEL;
	#endif
		
}



void EXTI1_enuInit()
{
	
	#if		INT1_MODE==INT1_MODE_FALLING_EDGE
			MCUCR|=(INT1_MODE_FALLING_EDGE<<MCUCR_ISC10);
	#elif	INT1_MODE==INT1_MODE_RISING_EDGE
			MCUCR|=(INT1_MODE_RISING_EDGE<<MCUCR_ISC10);
	#elif	INT1_MODE==INT1_MODE_ON_CHANGE
			MCUCR|=(INT1_MODE_ON_CHANGE<<MCUCR_ISC10);
	#else
			MCUCR|=(INT1_MODE_LOW_LEVEL<<MCUCR_ISC10);
	#endif
	
}


void EXTI2_enuInit()
{
	
	#if		INT2_MODE==INT2_MODE_FALLING_EDGE
			CLR_BIT(MCUCR,MCUCSR_ISC2);
	#elif	INT2_MODE==INT2_MODE_RISING_EDGE
			SET_BIT(MCUCR,MCUCSR_ISC2);
	#endif
	
}

void EXTI0_AssignCBF(EXTICallBackFn_t CBF)
{
	ApplicationCBF0 = CBF;
}

void EXTI1_AssignCBF(EXTICallBackFn_t CBF)
{
	ApplicationCBF1 = CBF;
}

void EXTI2_AssignCBF(EXTICallBackFn_t CBF)
{
	ApplicationCBF2 = CBF;
}

ISR(INT0_vect)
{
	ApplicationCBF0();
}

ISR(INT1_vect)
{
	ApplicationCBF1();
}

ISR(INT2_vect)
{
	ApplicationCBF2();
}