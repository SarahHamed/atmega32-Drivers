/*
 * ADC.c
 *
 * Created: 2/8/2023 8:56:53 PM
 *  Author: Sarah
 */ 
#define F_CPU	1000000
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_Prv.h"
#include "ADC_Cfg.h"
#include "ADC.h"
#include "../../MCAL/DIO/DIO.h"
#include  "../../HAL/LED/LED.h"
#include "../../HAL/SSEG/SSEG.h"
#include "../../HAL/SSEG/SSEG_Cfg.h"
#include "util/delay.h"

ADC_tenuErrorStatus ADC_enuInit()
{
	/*ADC Reference AVCC*/
	ADMUX&=ADC_SOURCE_SELECT_MASK;
	ADMUX|=(ADC_REF_SOURCE_SELECTION<<ADMUX_REFS0);
	
	/*	ADC ENABLE DISABLE Auto Trigger */
	#if(ADC_AUTO_TRIGGER_ENABLE	== ADC_AUTO_TRIGGER_ON)
		SET_BIT(ADCSRA,ADCSRA_ADATE);
	#endif
	
	/* Enable Disable Interrupt */
	#if( ADC_INT_ENABLE	== ADC_INT_ON)
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	#endif
	
	/* ADC Prescalar Selection */
	ADCSRA&=ADC_PRESCALAR_SELECT_MASK;
	ADCSRA|=ADC_PRESCALAR_SELECTION;
	
	/*	(Left)/Right Adjust */
	#if (ADC_ADJUST_RESULT==ADC_LEFT_ADJUST)
		SET_BIT(ADMUX,ADMUX_ADLAR);
	#elif (ADC_ADJUST_RESULT==ADC_RIGHT_ADJUST)
		CLR_BIT(ADMUX,ADMUX_ADLAR);
	#endif
	
	/*	Enable ADC */
	#if (ADC_ENABLE==ADC_ON)
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	#else
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
	#endif	
	
	return	ADC_OK;
}


ADC_tenuErrorStatus ADC_enuGetADCValue(ADC_tenuChannelNumber cpy_u8ChannelNumber,u16 *Add_pu16ADCValue)
{
	u16 TimeOut=10000;
	
	/*Set Channel*/
	ADMUX &=ADC_CHANNEL_SELECT_MASK;
	ADMUX |=cpy_u8ChannelNumber;
	
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Wait until conversion is done*/
	while (!GET_BIT(ADCSRA,ADCSRA_ADIF))
	{
		//TimeOut--;
	}
	
	/*Read Data*/
	#if (ADC_ADJUST_RESULT==ADC_LEFT_ADJUST)
		*Add_pu16ADCValue= ADCH ;
	#else
		*Add_pu16ADCValue= ADCL| ((ADCH & ADC_ADCH_RIGHT_ADJ_MASK)<<8);
	#endif

	return	ADC_OK;
}

ADC_tenuErrorStatus ADC_enuStartAutoTrigger(ADC_tenuChannelNumber cpy_u8ChannelNumber , ADC_tenuAutoTriggerSource cpy_u8triggerSource)
{
	/*Set Channel*/
	ADMUX &=ADC_CHANNEL_SELECT_MASK;
	ADMUX |=cpy_u8ChannelNumber;
	
	/* Mode: FreeRuning */
	SFIOR&=ADC_AUTOTRIGGER_MASK;
	SFIOR|=cpy_u8triggerSource;
	
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
return	ADC_OK;
}

void __vector_16(void)
{
	/*
	static u8 i=0;
	if(i%2)
		LED_enuLedON(LED1_PIN,Active_High);	
	else
		LED_enuLedOFF(LED1_PIN,Active_High);
	i++;
	*/
	
	u16 data;
	#if (ADC_ADJUST_RESULT==ADC_LEFT_ADJUST)
	data= ADCH ;
	#else
	data= ADCL| ((ADCH & ADC_ADCH_RIGHT_ADJ_MASK)<<8);
	#endif

	//u8 value=(data/1024.0)*10;
	//char Temperature[10];
	float celsius;
	celsius = (data*4.88);
	celsius = (celsius/10.00);
	int val=celsius;
	//sprintf(Temperature,"%d%cC  ", (int)celsius, 0xdf);/* convert integer value to ASCII string */
	_delay_ms(1000);
	SSEG_enuDisplayNum(SSEG_PORT_1, val%10);
	SSEG_enuDisplayNum(SSEG_PORT_2, val/10);
}


ADC_tenuErrorStatus ADC_enuGetADCValueAutoTrigger(u16 *Add_pu16ADCValue)
{
	u16 TimeOut=10000;
	
	/*Wait until conversion is done*/
	while (!GET_BIT(ADCSRA,ADCSRA_ADIF))
	{
		//TimeOut--;
	}
	
	/*Read Data*/
	#if (ADC_ADJUST_RESULT==ADC_LEFT_ADJUST)
	*Add_pu16ADCValue= ADCH ;
	#else
	*Add_pu16ADCValue= ADCL| ((ADCH & ADC_ADCH_RIGHT_ADJ_MASK)<<8);
	#endif

	return	ADC_OK;
}
