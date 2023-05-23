/*
 * ADC.h
 *
 * Created: 2/8/2023 8:55:46 PM
 *  Author: Sarah
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../LIB/STD_TYPES.h"

typedef enum 
{
	ADC_OK,
	ADC_NOK
}ADC_tenuErrorStatus;


 
 
typedef enum 
{
	ADC_enuFreeRunning=0b000000000,
	ADC_enuAnalogComparator=0b00100000,
	ADC_enuExternalInterruptRequest0=0b01000000,
	ADC_enuTimerCounter0CompareMatch=0b01100000,
	ADC_enuTimerCounter0Overflow=0b10000000,
	ADC_enuTimerCounter1CompareMatchB=0b10100000,
	ADC_enuTimerCounter1Overflow=0b11000000,
	ADC_enuTimerCounter1CaptureEvent=0b11100000
}ADC_tenuAutoTriggerSource; 
 

typedef enum 
{
	ADC_enuChannel0=0b00000,
	ADC_enuChannel1=0b00001,
	ADC_enuChannel2=0b00010,
	ADC_enuChannel3=0b00011,
	ADC_enuChannel4=0b00100,
	ADC_enuChannel5=0b00101,
	ADC_enuChannel6=0b00110,
	ADC_enuChannel7=0b00111,
}ADC_tenuChannelNumber;

ADC_tenuErrorStatus ADC_enuInit();
ADC_tenuErrorStatus ADC_enuGetADCValue(ADC_tenuChannelNumber cpy_u8ChannelNumber,u16 * Add_pu16ADCValue);
ADC_tenuErrorStatus ADC_enuStartAutoTrigger(ADC_tenuChannelNumber cpy_u8ChannelNumber , ADC_tenuAutoTriggerSource cpy_u8triggerSource);
ADC_tenuErrorStatus ADC_enuGetADCValueAutoTrigger(u16 *Add_pu16ADCValue);
void __vector_16(void) __attribute__((signal));

#endif /* ADC_H_ */