/*
 * GlobalAndExtInterrupt.c
 *
 * Created: 1/27/2023 9:50:50 AM
 * Author : Sarah
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>


#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/GIE/GIE.h"
#include "../HAL/LED/LED.h"
#include "../HAL/SSEG/SSEG.h"
#include "../HAL/SSEG/SSEG_Cfg.h"

int number=0;

void showIncNumber(void)
{
	if(number<9)
		number++;
	SSEG_enuDisplayNum(SSEG_PORT_1, number);
}

void showDecNumber(void)
{
	if(number>0)
		number--;
	SSEG_enuDisplayNum(SSEG_PORT_1, number);
}

void LED0_Toggle(void)
{
	static u8 i=0;
	if(i)
	LED_enuLedOFF(0);
	else
	LED_enuLedON(0);
	i^=1;
	_delay_ms(50);
}
void LED1_Toggle(void)
{
	static u8 i=0;
	if(i)
	LED_enuLedOFF(1);
	else
	LED_enuLedON(1);
	i^=1;
	_delay_ms(50);
}
void LED2_Toggle(void)
{
	static u8 i=0;
	if(i)
	LED_enuLedOFF(8);
	else
	LED_enuLedON(8);
	i^=1;
	_delay_ms(50);
}


int main(void)
{
	/*	(INT0-->PD2) - (INT1--->PD3) - (INT2--->PB2)  */
	DIO_enuInit();
	
	EXTI0_AssignCBF(showIncNumber);
	EXTI1_AssignCBF(showDecNumber);
	EXTI2_AssignCBF(LED2_Toggle);
	
	EXTI_enuEnableINT0();
	EXTI0_enuInit();
	
	EXTI_enuEnableINT1();
	EXTI1_enuInit();
	
	GIE_vidEnable();
	
	EXTI_enuEnableINT2();
	EXTI2_enuInit();
	
    while (1);
	
}

