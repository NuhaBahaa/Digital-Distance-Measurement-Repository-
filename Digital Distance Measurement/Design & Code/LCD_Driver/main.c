/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */

#include "types.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "Delay_Config.h"
#include "Delay.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"




int main(void)
{
	u8 CustomChar[4][8]={{7,4,31,4,4,4,4,4},{0,0,0,2,0,1,1,31},{0,0,0,0,0,21,21,31},{0,0,0,0,0,8,8,15}};
	DIO_VoidInit();
	LCD_voidInit();
	u8* Arr[2]={{"Anas"},{"Ebrahim"}};
	//LCD_voidWriteFloat(2.5);
	//LCD_u8GoToXY(10,0);
	//LCD_u8WriteString(Arr[0]);
	LCD_u8WriteCustomChar(CustomChar, (sizeof(CustomChar)/(sizeof(u8)*8)),16,0);
	/*LCD_u8GoToXY(2,1);

	Delay_ms(1500);
	LCD_u8Control(LCD_ShiftStrRight);
	Delay_ms(1500);
	LCD_u8Control(LCD_ShiftCursorRight);
	Delay_ms(1500);
	LCD_u8Control(LCD_ShiftStrLeft);
	Delay_ms(1500);
	LCD_u8Control(LCD_ShiftCursorLeft);
	Delay_ms(1500);
	LCD_u8GoToXY(5,0);
		LCD_u8WriteString("Hello");
	//LCD_u8WriteString("!");
	//LCD_voidWriteCommand(0b00010100);
	/*LCD_u8Control(LCD_TurnOff);
	Delay_ms(1500);
	LCD_u8WriteString("Test");
	LCD_u8Control(LCD_TurnOn);
	LCD_u8Control(LCD_TurnCursorOff);
	Delay_ms(1500);
	LCD_u8Control(LCD_SetCursorHome);
	LCD_u8Control(LCD_CursorIncrement);
	LCD_u8Control(LCD_TurnBlinkOn);
	Delay_ms(1500);
	LCD_u8WriteString("Belf");*/
	while(1)
	{


	}



}

