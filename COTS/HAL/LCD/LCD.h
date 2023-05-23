/*
 * LCD.h
 *
 * Created: 2/10/2023 2:23:09 PM
 *  Author: Sarah
 */ 


#ifndef LCD_H_
#define LCD_H_

#define BaseAddrLine2	0x40
#define DDRAM_SetAddInstCode	128
#define CGRAM_SetAddInstCode	64
#define CGRAM_BlockSize	8

typedef enum
{
	LCD_enuOK,
	LCD_enuNOK
}LCD_enuErrorStatus;


void  LCD_vidInit();
LCD_enuErrorStatus LCD_enuSendData(u8 Copy_u8Data);
LCD_enuErrorStatus LCD_enuSendCommand(u8 Copy_u8Command);

LCD_enuErrorStatus LCD_enuGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
LCD_enuErrorStatus LCD_enuWriteSpecialPattern(u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos);

LCD_enuErrorStatus LCD_enuWriteString(char* Add_pchString);
LCD_enuErrorStatus LCD_enuWriteNumber(u16 Copy_u16Number);


#endif /* LCD_H_ */