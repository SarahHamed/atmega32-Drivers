/*
 * ADC_Cfg.h
 *
 * Created: 2/8/2023 8:56:17 PM
 *  Author: Sarah
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define ADC_SOURCE_SELECT_MASK	0b00111111
#define ADC_ADCH_RIGHT_ADJ_MASK	0b00000011
#define ADC_CHANNEL_SELECT_MASK	0b11100000
#define ADC_AUTOTRIGGER_MASK	0b00011111

#define ADC_REF_SOURCE_SELECTION  ADC_AVCC
#define ADC_AREF  (0b00)
#define ADC_AVCC  (0b01)
#define ADC_NTERNAL_256 (0b11)



#define ADC_ENABLE ADC_ON
#define ADC_ON	1
#define ADC_OFF	0

#define ADC_AUTO_TRIGGER_ENABLE		ADC_AUTO_TRIGGER_ON
#define ADC_AUTO_TRIGGER_ON		1
#define ADC_AUTO_TRIGGER_OFF	0

#define ADC_INT_ENABLE		ADC_INT_ON
#define ADC_INT_ON	1
#define ADC_INT_OFF	0

#define ADC_PRESCALAR_SELECT_MASK	0b11111100
#define ADC_PRESCALAR_SELECTION	ADC_PRESCALAR_DIV_2

#define ADC_PRESCALAR_DIV_2		0b001		
#define ADC_PRESCALAR_DIV_4		0b010	
#define ADC_PRESCALAR_DIV_8		0b011	
#define ADC_PRESCALAR_DIV_16	0b100	
#define ADC_PRESCALAR_DIV_32	0b101	
#define ADC_PRESCALAR_DIV_64	0b110	
#define ADC_PRESCALAR_DIV_128	0b111

#define ADC_ADJUST_RESULT	ADC_RIGHT_ADJUST
#define ADC_LEFT_ADJUST		1
#define ADC_RIGHT_ADJUST	0



#endif /* ADC_CFG_H_ */