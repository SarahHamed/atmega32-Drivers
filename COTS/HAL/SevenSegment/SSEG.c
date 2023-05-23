/*
 * SSEG.c
 *
 * Created: 1/20/2023 2:55:02 PM
 *  Author: Sarah
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Cfg.h"
#include "SSEG.h"
#include "SSEG_Cfg.h"

/*
u8 SSEG_LookUpTable[10]={
	0b10000001,
	0b11001111,
	0b10010010,
	0b10000110,
	0b11001100,
	0b10100100,
	0b10100000,
	0b10001111,
	0b10000000,
	0b10000100,
};
*/
// g-f-e-d-c-b-a-comm


SSEG_tenuErrorStatus_t SSEG_enuDisplayNum(DIO_tenuPortValue Cpy_enuPortNumber, u8 Cpy_number)
{
	SSEG_tenuErrorStatus_t Loc_enuErrorStatus= DIO_enuOK;
	Loc_enuErrorStatus=DIO_enuSetPortValue(Cpy_enuPortNumber , SSEG_LookUpTable[Cpy_number]);
	return Loc_enuErrorStatus;
}