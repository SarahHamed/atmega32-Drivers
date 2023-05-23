/*
 * TIMER.c
 *
 * Created: 3/10/2023 5:57:17 PM
 *  Author: Sarah
 */ 

#include "../../LIB/BIT_MATH.h"
//#include "../../LIB/STD_TYPES.h"
#include "TIMER.h"
#include "TIMER_Prv.h"
#include "TIMER_Cfg.h"
#include "math.h"

static TMR0cbf_t TMR0_pvCallBackFunc;

void TMR0_vidInitPreCompile(void)
{
	/*SET TIMR0 MODE*/
	#if TIMR0_MODE == MODE_NORMAL
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
			
	#elif TIMR0_MODE == MODE_CTC
		CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
					
	#elif TIMR0_MODE == MODE_FAST_PWM	
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
			
	#elif TIMR0_MODE == MODE_PHASE_CORRECT
		SET_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
			
	#endif
	
	
	/* SET Compare Match VALUE In Case of CTC */
	#if TIMR0_MODE==MODE_CTC
		OCR0=OCR0_VALUE;
	#endif
	
	/*Enable OverFlow Interrupt If Selected*/
	#if TIMR0_OV_INT_ENABLE
		SET_BIT(TIMSK,TIMSK_TOIE0);
	#endif
	
	/*Enable Compare Match Interrupt If Selected*/
	#if TIMR0_COMP_MATCH_INT_ENABLE ==TIMR0_COMP_MATCH_INT_ON
		SET_BIT(TIMSK,TIMSK_OCIE0);
	#endif
	
}


void TMR0_vidInitPostCompile(TMR0Config_t TMR0Config)
{
	/*SET TIMR0 MODE*/
	switch(TMR0Config.Mode)
	{
		case MODE_NORMAL:
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;
		case MODE_CTC:
		CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
		case MODE_FAST_PWM:
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
		case MODE_PHASE_CORRECT:
		SET_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;
		
	}
	
	/* SET Compare Match VALUE In Case of CTC */
	if(TMR0Config.Mode == MODE_CTC) 
	{
		OCR0=TMR0Config.CompMatchValue;	
	}
	
	/*Enable OverFlow Interrupt If Selected*/
	if(TMR0Config.OverFlowIntEn)
	{
		SET_BIT(TIMSK,TIMSK_TOIE0);	
	}
	
	
	
	/*Enable Compare Match Interrupt If Selected*/
	if(TMR0Config.CompMatchIntEn)
	{
		SET_BIT(TIMSK,TIMSK_OCIE0);
	}
	
	
	/* SET CLOCK PRESECALER*/
	u8 Loc_TCCR0_Copy =TCCR0;
	Loc_TCCR0_Copy &= PRESCALER_CLR_MASK;
	Loc_TCCR0_Copy = TMR0Config.Prescalar;
}

//required ---> TCCN0 and Preload Value
TMR0_enuErrorStatus TMR0_enuSetTickTimeMS(u16 Copy_u16TickTime, u8 *Add_pu8TovCountValue,u8 *Add_pu8TovPreloadValue)
{
	TMR0_enuErrorStatus	Loc_enuErrStatus=TMR0_Ok;
		
	f64 Tov_Counts;
	f64 Preload_Val;
	f64 preload_time_frac;
	f64 res;
	f64 T_Clk=(TIMR0_PRESCALER/F_CPU);	//Tick Time
	f64 Tov=pow(2,TIMR0_RESOLUTION)*T_Clk;
	  
	if(Copy_u16TickTime > Tov)
	{
		res= Copy_u16TickTime / (double)pow(2,TIMR0_RESOLUTION);
		preload_time_frac = modf(res, &Tov_Counts);
		Preload_Val=pow(2,TIMR0_RESOLUTION)*(1-preload_time_frac);
		*Add_pu8TovCountValue=Tov_Counts;
		*Add_pu8TovPreloadValue=Preload_Val;
	}
	else if(Copy_u16TickTime < Tov)
	{
		//preload = Required Time / Tick time
		*Add_pu8TovPreloadValue= Copy_u16TickTime*T_Clk;
	}
	else if(Copy_u16TickTime == Tov)
	{
		//preload = Required Time / Tick time
		*Add_pu8TovPreloadValue= Copy_u16TickTime;
	}
	//TCNT0=Add_pu8TovPreloadValue;
	
	return Loc_enuErrStatus;
}


TMR0_enuErrorStatus TMR0_enuStart(void)
{
	TMR0_enuErrorStatus	Loc_enuErrStatus=TMR0_Ok;
	
	if(TIMR0_PRESCALER > TIMR0_enuPrescaler_1024)
		Loc_enuErrStatus=TMR0_Nok;
		
	if(Loc_enuErrStatus==TMR0_Ok)
	{
		/* SET CLOCK PRESECALER*/
		u8 Loc_TCCR0_Copy =TCCR0;
		Loc_TCCR0_Copy &= PRESCALER_CLR_MASK;
		Loc_TCCR0_Copy = TIMR0_PRESCALER;
		TCCR0=Loc_TCCR0_Copy;
		
	}
	
	return Loc_enuErrStatus;
}



TMR0_enuErrorStatus TMR0_enuRegisterCallback(TMR0cbf_t copy_pvCallBackFunc)
{
	TMR0_enuErrorStatus	Loc_enuErrStatus=TMR0_Ok;
	
	if(copy_pvCallBackFunc != NULL)
	{
		TMR0_pvCallBackFunc=copy_pvCallBackFunc;
	}
	else
	{
		Loc_enuErrStatus=TMR0_NullPtr;
	}
	return Loc_enuErrStatus;
}

/*11 TIMER0 COMP Timer/Counter0 Compare Match*/
void __vector_10(void)
{
	if(TMR0_pvCallBackFunc != NULL)
	{
		TMR0_pvCallBackFunc();
	}
}