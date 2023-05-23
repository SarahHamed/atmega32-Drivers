
#include "../../LIB/BIT_MATH.h"
#include "DIO.h"
#include "DIO_Prv.h"
//#include <avr/io.h>

#include "DIO_Cfg.h"
#include "DIO_Prv.h"


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//23/8 =2 (port)
//23%8 =7 (pin)



DIO_tenuErrorStatus_t DIO_enuInit(void)
{
	u8 i;
	u8 Loc_u8PortNumber= 0;
	u8 Loc_u8PinNumber= 0;
	for(i=0;i<DIO_enuNumberOfPins;i++)
	{
		Loc_u8PortNumber = i/8;
		Loc_u8PinNumber = i%8;
		
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				if(DIO_strPinCfg[i].DIO_PinDirection==DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRA,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTA,Loc_u8PinNumber);
					}
				}
			break;
			case(DIO_PORTB):
				if(DIO_strPinCfg[i].DIO_PinDirection==DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRB,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRB,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTA,Loc_u8PinNumber);
					}
				}
			break;
			case(DIO_PORTC):
				if(DIO_strPinCfg[i].DIO_PinDirection==DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRC,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRC,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTA,Loc_u8PinNumber);
					}
				}
			break;
			case(DIO_PORTD):
				if(DIO_strPinCfg[i].DIO_PinDirection==DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRD,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRD,Loc_u8PinNumber);
					
					//Check if pull up
					if(DIO_strPinCfg[i].DIO_InputStatus==DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTA,Loc_u8PinNumber);
					}
				}
			break;
		}
	}
	return DIO_enuOK;
}



DIO_tenuErrorStatus_t DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber)
{
	
	DIO_tenuErrorStatus_t Loc_enuErrorStatus= DIO_enuOK;
	u8 Loc_u8PortNumber = Cpy_enuPinNumber/8;
	u8 Loc_u8PinNumber = Cpy_enuPinNumber%8;
	
	if(Loc_u8PortNumber>3)
	{
		Loc_enuErrorStatus=DIO_InvalidPortNum;
	}
	else if(Loc_u8PinNumber>7)
	{
		Loc_enuErrorStatus=DIO_InvalidPinNum;
	} 
	else
	{
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				SET_BIT(PORTA,Loc_u8PinNumber);
				
				break;
			case(DIO_PORTB):
				SET_BIT(PORTB,Loc_u8PinNumber);
				break;
			case(DIO_PORTC):
				SET_BIT(PORTC,Loc_u8PinNumber);
				break;
			case(DIO_PORTD):
				SET_BIT(PORTD,Loc_u8PinNumber);
				break;
		}
	}
	return Loc_enuErrorStatus;
}

DIO_tenuErrorStatus_t DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber)
{
	DIO_tenuErrorStatus_t Loc_enuErrorStatus= DIO_enuOK;
	u8 Loc_u8PortNumber = Cpy_enuPinNumber/8;
	u8 Loc_u8PinNumber = Cpy_enuPinNumber%8;
	
	if(Loc_u8PortNumber>3)
	{
		Loc_enuErrorStatus=DIO_InvalidPortNum;
	}
	else if(Loc_u8PinNumber>7)
	{
		Loc_enuErrorStatus=DIO_InvalidPinNum;
	}
	else
	{
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
			CLR_BIT(PORTA,Loc_u8PinNumber);
			break;
			case(DIO_PORTB):
			CLR_BIT(PORTB,Loc_u8PinNumber);
			break;
			case(DIO_PORTC):
			CLR_BIT(PORTC,Loc_u8PinNumber);
			break;
			case(DIO_PORTD):
			CLR_BIT(PORTD,Loc_u8PinNumber);
			break;
		}
	}
	return Loc_enuErrorStatus;
}


DIO_tenuErrorStatus_t DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber, u8 * Add_pu8PinValue)
{
	DIO_tenuErrorStatus_t Loc_enuErrorStatus= DIO_enuOK;
	u8 Loc_u8PortNumber = Cpy_enuPinNumber/8;
	u8 Loc_u8PinNumber = Cpy_enuPinNumber%8;
	
	if(Loc_u8PortNumber>3)
	{
		Loc_enuErrorStatus=DIO_InvalidPortNum;
	}
	else if(Loc_u8PinNumber>7)
	{
		Loc_enuErrorStatus=DIO_InvalidPinNum;
	}
	else if(Add_pu8PinValue==NULL)
	{
		Loc_enuErrorStatus=DIO_enuNullPtr;
	}
	else
	{
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
			*Add_pu8PinValue=GET_BIT(PINA,Loc_u8PinNumber);
			break;
			case(DIO_PORTB):
			*Add_pu8PinValue=GET_BIT(PINB,Loc_u8PinNumber);
			break;
			case(DIO_PORTC):
			*Add_pu8PinValue=GET_BIT(PINC,Loc_u8PinNumber);
			break;
			case(DIO_PORTD):
			*Add_pu8PinValue=GET_BIT(PIND,Loc_u8PinNumber);
			break;
		}
	}
	return Loc_enuErrorStatus;
}


DIO_tenuErrorStatus_t DIO_enuSetPinDirection(DIO_tenuPins Cpy_enuPinNumber , DIO_tenuPinDirection Cpy_enuPinDir)
{
	DIO_tenuErrorStatus_t Loc_enuErrorStatus= DIO_enuOK;
	u8 Loc_u8PortNumber = Cpy_enuPinNumber/8;
	u8 Loc_u8PinNumber = Cpy_enuPinNumber%8;
	
	if(Loc_u8PortNumber>3)
	{
		Loc_enuErrorStatus=DIO_InvalidPortNum;
	}
	else if(Loc_u8PinNumber>7)
	{
		Loc_enuErrorStatus=DIO_InvalidPinNum;
	}
	else if(Cpy_enuPinDir !=DIO_enuInput && Cpy_enuPinDir !=DIO_enuOutput)
	{
		Loc_enuErrorStatus=DIO_enuInvalidVal;
	}
	else
	{
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				if(Cpy_enuPinDir == DIO_enuInput)
					CLR_BIT(DDRA,Loc_u8PinNumber);
				else if(Cpy_enuPinDir == DIO_enuOutput)
					SET_BIT(DDRA,Loc_u8PinNumber);
				break;
			case(DIO_PORTB):
				if(Cpy_enuPinDir == DIO_enuInput)
					CLR_BIT(DDRB,Loc_u8PinNumber);
				else if(Cpy_enuPinDir == DIO_enuOutput)
					SET_BIT(DDRB,Loc_u8PinNumber);
				break;
			case(DIO_PORTC):
				if(Cpy_enuPinDir == DIO_enuInput)
					CLR_BIT(DDRC,Loc_u8PinNumber);
				else if(Cpy_enuPinDir == DIO_enuOutput)
					SET_BIT(DDRC,Loc_u8PinNumber);
				break;
			case(DIO_PORTD):
				if(Cpy_enuPinDir == DIO_enuInput)
					CLR_BIT(DDRD,Loc_u8PinNumber);
				else if(Cpy_enuPinDir == DIO_enuOutput)
					SET_BIT(DDRD,Loc_u8PinNumber);
				break;
		}
	}
	
	
	return Loc_enuErrorStatus;
}