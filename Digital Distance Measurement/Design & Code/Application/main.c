/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#include "Types.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "UltraSonic_interface.h"
#include "S4MDelay.h"
#include "LCD_interface.h"
#include "stdlib.h"
#include "Delay.h"

void main(void) {
	u16 Read = 0;
	u8 Local_arr1[20];
	DIO_voidInit();
	UltraSonic_voidInit();

	u64 counter = 0;
	u8 i = 0;
	//Timer1_voidInit();
	LCD_voidInit();
	__asm__("SEI");
//	LCD_voidWriteString("lol");

	while (1) {
			LCD_voidWrite_Command(0x80);
			LCD_voidWriteString("Distance = ");
			itoa(Read, Local_arr1, 10);
			DIO_U8WritePortVal(1, Read);
			LCD_voidWriteString(Local_arr1);

		UltraSoinc_U8ReadDistance(&Read);
	//	Timer1_voidWriteReg(0);
	//	Timer1_Stop();
	//	LCD_voidWrite_Command((0x80 | 0xC0));
//		itoa(counter, Local_arr1, 10);
//		LCD_voidWriteString(Local_arr1);
	//	counter++;
		for (i = 0; i <= 30; i++) {
			Delay_ms(5);
		}
		LCD_voidWrite_Command(0x01);

//		LCD_voidWriteString("lol");

	}

}
