/*
 * EXTI_Prv.h
 *
 * Created: 1/27/2023 10:14:40 AM
 *  Author: Sarah
 */ 


#ifndef EXTI_PRV_H_
#define EXTI_PRV_H_


#define MCUCR	*((volatile u8*)0x55)
#define MCUCSR	*((volatile u8*)0x54)
#define GICR	*((volatile u8*)0x5B)
#define GIFR	*((volatile u8*)0x5A)



#define	MCUCR_ISC00	0
#define	MCUCR_ISC01	1
#define	MCUCR_ISC10	2
#define	MCUCR_ISC11	3

#define MCUCSR_ISC2	6

#define	GICR_INT0	6
#define	GICR_INT1	7
#define	GICR_INT2	5

#endif /* EXTI_PRV_H_ */