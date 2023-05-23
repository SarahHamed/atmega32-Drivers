/*
 * SSEG.h
 *
 * Created: 1/20/2023 2:55:22 PM
 *  Author: Sarah
 */ 


#ifndef SSEG_H_
#define SSEG_H_


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"


typedef enum
{
	SSEG_enuOK=0,
	SSEG_enuNotOK,
}SSEG_tenuErrorStatus_t;


SSEG_tenuErrorStatus_t SSEG_enuDisplayNum(DIO_tenuPortValue Cpy_enuPortNumber, u8 Cpy_number);

#endif /* SSEG_H_ */