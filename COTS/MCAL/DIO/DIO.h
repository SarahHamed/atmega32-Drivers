#ifndef DIO_H
#define DIO_H

#include "../../LIB/STD_TYPES.h"

typedef enum
{
	DIO_enuOK=0,
	DIO_enuNotOK,
	DIO_enuNullPtr,
	DIO_InvalidPortNum,
	DIO_InvalidPinNum,
	DIO_enuInvalidVal
	
}DIO_tenuErrorStatus_t;



typedef enum
{
	DIO_enuPin0=0,
	DIO_enuPin1,
	DIO_enuPin2,
	DIO_enuPin3,
	DIO_enuPin4,
	DIO_enuPin5,
	DIO_enuPin6,
	DIO_enuPin7,
	DIO_enuPin8,
	DIO_enuPin9,
	DIO_enuPin10,
	DIO_enuPin11,
	DIO_enuPin12,
	DIO_enuPin13,
	DIO_enuPin14,
	DIO_enuPin15,
	DIO_enuPin16,
	DIO_enuPin17,
	DIO_enuPin18,
	DIO_enuPin19,
	DIO_enuPin20,
	DIO_enuPin21,
	DIO_enuPin22,
	DIO_enuPin23,
	DIO_enuPin24,
	DIO_enuPin25,
	DIO_enuPin26,
	DIO_enuPin27,
	DIO_enuPin28,
	DIO_enuPin29,
	DIO_enuPin30,
	DIO_enuPin31,
	DIO_enuNumberOfPins
	
}DIO_tenuPins;

typedef enum
{
	DIO_enuLow=0,
	DIO_enuHigh
}DIO_tenuPinValue;


typedef enum
{
	DIO_enuInput=0,
	DIO_enuOutput
}DIO_tenuPinDirection;


/*******************************************/
/* DIO Init Function*/
/* Input:void*/
/* Output: DIO_tenuErrorStatus_t to report error*/
/*********************************************/
DIO_tenuErrorStatus_t DIO_enuInit(void);

/*
DIO SetPin Function
Input: Pin Number (Range from 0-31)
Output: DIO_tenuErrorStatus_t to report error
*/
DIO_tenuErrorStatus_t DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber);

/*
DIO ClearPin Function
Input: Pin Number (Range from 0-31)
Output: DIO_tenuErrorStatus_t to report error
*/
DIO_tenuErrorStatus_t DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber);


/*
DIO GetPin Function
Input: Pin Number (Range from 0-31)
Output: DIO_tenuErrorStatus_t to report error
*/
DIO_tenuErrorStatus_t DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber, u8 * Add_pu8PinValue);

#endif /*DIO_H (Dda l interface)*/
