/*
 * TIMER_Cfg.h
 *
 * Created: 3/10/2023 5:58:18 PM
 *  Author: Sarah
 */ 


#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_


#define TIMR0_MODE			MODE_CTC

#define MODE_NORMAL			0
#define MODE_CTC			1
#define MODE_FAST_PWM		2
#define MODE_PHASE_CORRECT	3


#define TIMR0_PRESCALER	TIMR0_enuPrescaler_8

#if TIMR0_MODE==MODE_CTC
	#define OCR0_VALUE	250
#endif

#define TIMR0_OV_INT_ENABLE		TIMR0_OV_INT_OFF
#define TIMR0_OV_INT_ON		1
#define TIMR0_OV_INT_OFF	0


#define TIMR0_COMP_MATCH_INT_ENABLE		TIMR0_COMP_MATCH_INT_ON
#define TIMR0_COMP_MATCH_INT_ON		1
#define TIMR0_COMP_MATCH_INT_OFF	0


extern TMR0Config_t TMR0Config;

#endif /* TIMER_CFG_H_ */