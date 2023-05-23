/*
 * LCD.c
 *
 * Created: 2/10/2023 2:23:23 PM
 *  Author: Sarah
 */ 
#define F_CPU	1000000

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Cfg.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#include "util/delay.h"


LCD_enuErrorStatus LCD_enuSendCommand(u8 Copy_u8Command)
{
	/*	Rs=0 (Command)/Data	*/
	DIO_enuClearPin(LCD_RS);
	
	/*	RW=0 (Write)/Read	*/
	DIO_enuClearPin(LCD_RW);
	
	/*	Command(D0->D7)		*/
	DIO_enuSetPortValue(LCD_Data_Port,Copy_u8Command);
	
	/*	Enable Pulse	*/
	DIO_enuSetPin(LCD_EN);
	_delay_ms(20);	//should it  be more or less
	DIO_enuClearPin(LCD_EN);
	
	return LCD_enuOK;
}



LCD_enuErrorStatus LCD_enuSendData(u8 Copy_u8Data)
{
	/*	Rs=1 Command/(Data)	*/
	DIO_enuSetPin(LCD_RS);
	
	/*	RW=0 (Write)/Read	*/
	DIO_enuClearPin(LCD_RW);
	
	/*	Command(D0->D7)		*/
	DIO_enuSetPortValue(LCD_Data_Port,Copy_u8Data);
	
	/*	Enable Pulse	*/
	DIO_enuSetPin(LCD_EN);
	_delay_ms(2);	//should it  be more or less?
	DIO_enuClearPin(LCD_EN);
	
	return LCD_enuOK;
}

void  LCD_vidInit()
{
	LCD_enuSendCommand(LCD_FunctionalSet_Mask);
	_delay_ms(2);
	LCD_enuSendCommand(LCD_DisplayOnOff_Mask);
	_delay_ms(2);
	LCD_enuSendCommand(LCD_DisplayClear_Mask);
	_delay_ms(2);
}

LCD_enuErrorStatus LCD_enuGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Loc_u8location;
	LCD_enuErrorStatus Loc_enuErrStatus=LCD_enuOK;
	
	if(Copy_u8XPos==First_Line)
		Loc_u8location=Copy_u8YPos;
	else if(Copy_u8XPos==Second_Line)
		Loc_u8location=BaseAddrLine2+Copy_u8YPos;
	
	Loc_enuErrStatus=LCD_enuSendCommand(DDRAM_SetAddInstCode+Loc_u8location);
	
	return Loc_enuErrStatus;
}

LCD_enuErrorStatus LCD_enuWriteSpecialPattern(u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	LCD_enuErrorStatus Loc_enuErrStatus=LCD_enuOK;
	
	/* Get Address in CGRAM */
	u8 Loc_u8Address=Copy_u8BlockNum*8;
	
	/*Move Address Counter to CGRAM*/
	Loc_enuErrStatus=LCD_enuSendCommand(Loc_u8Address+CGRAM_SetAddInstCode);
	
	/* Write The Pattern */
	for(u8 i=0;i<CGRAM_BlockSize;i++)
	{
		Loc_enuErrStatus=LCD_enuSendData(Add_pu8Pattern[i]);
	}
	
	/*Move AC To DDRAM*/
	Loc_enuErrStatus=LCD_enuGotoXY(Copy_u8XPos,Copy_u8YPos);
	
	/*Display (Blocks (0-7) Will get the value from CGRAM) */
	Loc_enuErrStatus=LCD_enuSendData(Copy_u8BlockNum);
	
	return	Loc_enuErrStatus;
}