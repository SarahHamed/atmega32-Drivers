/*
 * TIMER_Prv.h
 *
 * Created: 3/10/2023 5:58:37 PM
 *  Author: Sarah
 */ 


#ifndef TIMER_PRV_H_
#define TIMER_PRV_H_


#define TCCR0	*((volatile u8*)0x53)
#define TCNT0	*((volatile u8*)0x52)
#define OCR0	*((volatile u8*)0x5C)
#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)



#define TCCR0_CS00	0
#define TCCR0_CS01	1
#define TCCR0_CS02	2
#define TCCR0_WGM01	3
#define TCCR0_COM00	4
#define TCCR0_COM01	5
#define TCCR0_WGM00	6
#define TCCR0_FOC0	7


#define TIMSK_TOIE0	0
#define TIMSK_OCIE0	1

#define TIFR_TOV0	0
#define TIFR_OCF0	1


#endif /* TIMER_PRV_H_ */

