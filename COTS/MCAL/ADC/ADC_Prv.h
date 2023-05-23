/*
 * ADC_Prv.h
 *
 * Created: 2/8/2023 10:05:02 PM
 *  Author: Sarah
 */ 


#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define	ADMUX	*((volatile u8*)0x27)
#define	ADCSRA	*((volatile u8*)0x26)
#define	ADCL	*((volatile u8*)0x24)
#define	ADCH	*((volatile u8*)0x25)
#define	SFIOR	*((volatile u8*)0x50)


#define ADMUX_REFS0	6
#define	ADMUX_ADLAR	5
#define	ADCSRA_ADEN	7
#define	ADCSRA_ADATE	5
#define ADCSRA_ADIF	4
#define ADCSRA_ADIE 3
#define	ADCSRA_ADSC	6



#define SFIOR_ADTS2	7
#define SFIOR_ADTS1	6
#define SFIOR_ADTS0	5

#endif /* ADC_PRV_H_ */