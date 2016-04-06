/*
 * main.c
 *
 *  Created on: Apr 2, 2016
 *      Author: aya osama
 */


#include "Types.h"
#include "DIO_interface.h"
#include "Buzzer_Interface.h"
#include "UltraSonic_interface.h"
#include "LCD_Interface.h"


int main(void)
{

	u16 Local_u16DistanceVal=0;
	DIO_voidInit();
	LCD_voidInit();
	UltraSonic_voidInit();
	LCD_u8Control(LCD_TurnOn);

	while(1)
	{
		UltraSoinc_U8ReadDistance(&Local_u16DistanceVal);
		if(Local_u16DistanceVal<=Max_u16ReadingVal)
		{
			LCD_u8WriteString(&Local_u16DistanceVal);
		}
		else
		{
			Buzzer_voidRun();
		}
	}
}
