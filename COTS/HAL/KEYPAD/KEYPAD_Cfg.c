/*
 * KEYPAD_Cfg.c
 *
 * Created: 2/1/2023 10:15:04 PM
 *  Author: Sarah
 */ 

#include "../../MCAL/DIO/DIO.h"
#include "KEYPAD_Cfg.h"

const KPD_tstrPinCfg KPD_strPinCfg[8]={
	{DIO_enuPin8},
	{DIO_enuPin9},
	{DIO_enuPin10},
	{DIO_enuPin11},
	{DIO_enuPin12},
	{DIO_enuPin13},
	{DIO_enuPin14},
	{DIO_enuPin15}
};