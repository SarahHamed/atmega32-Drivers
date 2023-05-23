/*
 * KEYPAD_Cfg.h
 *
 * Created: 2/1/2023 5:02:48 PM
 *  Author: Sarah
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "../../LIB/STD_TYPES.h"

#define ROW_MAX 	4
#define COL_MAX		4

#define KPD_COL1	DIO_enuPin12

typedef struct {
	u8 DIO_PinNumber;
}KPD_tstrPinCfg;

extern const KPD_tstrPinCfg KPD_strPinCfg[8];



#endif /* KEYPAD_CFG_H_ */