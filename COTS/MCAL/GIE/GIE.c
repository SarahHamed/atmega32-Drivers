/*
 * GIE.c
 *
 * Created: 1/27/2023 9:57:50 AM
 *  Author: Sarah
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GIE_Prv.h"
#include "GIE.h"

void GIE_vidEnable(void)
{
	SET_BIT(SREG,GIE_BIT);
}

void GIE_vidDisable(void)
{
	CLR_BIT(SREG,GIE_BIT);
}