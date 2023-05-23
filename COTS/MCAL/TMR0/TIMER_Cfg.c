/*
 * TIMER_Cfg.c
 *
 * Created: 3/10/2023 8:11:17 PM
 *  Author: Sarah
 */ 

#include "TIMER.h"
#include "TIMER_Cfg.h"

TMR0Config_t TMR0Config=
{
	.Mode=MODE_NORMAL,
	.Prescalar=TIMR0_enuPrescalerNone
};