/*
 * LCD_Cfg.h
 *
 * Created: 2/10/2023 2:41:58 PM
 *  Author: Sarah
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#define LCD_RS	DIO_enuPin8
#define LCD_RW	DIO_enuPin9
#define LCD_EN	DIO_enuPin10

#define LCD_Data_Port		DIO_PORTA
#define LCD_Control_Port	DIO_PORTB

#define Anode		DIO_enuPin11
#define Kathode		DIO_enuPin12


/*

Function Set: (0011NFXX)
N:0 (1 Line)
N:1 (2 Lines)

F:0 (5*8)
F:0 (5*11)

Display ON/OFF CONTROL: (00001DCB)

(D):Display (C):Cursor (B):Blink Cursor
1 ON
0 OFF

*/

#define LCD_FunctionalSet_Mask	0b00111000
#define LCD_DisplayOnOff_Mask	0b00001100
#define LCD_DisplayClear_Mask	0b00000001

#define First_Line	0
#define Second_Line	1


#endif /* LCD_CFG_H_ */