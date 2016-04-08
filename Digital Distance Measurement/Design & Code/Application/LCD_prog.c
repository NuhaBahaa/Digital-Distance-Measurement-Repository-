/*
 * LCD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#include "Types.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "Delay.h"
#include "Delay_config.h"

void LCD_voidWriteString(u8* Copy_U8PtrToVal) {
	u8 Local_U8LoopCounter = 0;
	while (Copy_U8PtrToVal[Local_U8LoopCounter] != 0) {
		DIO_U8WritePortVal(LCD_DATAPORT, Copy_U8PtrToVal[Local_U8LoopCounter]);
		DIO_U8WritePinVal(LCD_RS, DIO_U8HIGH);
		DIO_U8WritePinVal(LCD_RW, DIO_U8LOW);
		DIO_U8WritePinVal(LCD_E, DIO_U8HIGH);
		Delay_ms(1);
		DIO_U8WritePinVal(LCD_E, DIO_U8LOW);
		Local_U8LoopCounter++;
	}
}

void LCD_voidStoreData(u8 Copy_U8Addr, u8* Copy_U8PtrToVal) {
	u8 Local_InitialAdd = 0b01000000, Local_U8Counter;
	Local_InitialAdd |= Copy_U8Addr;
	LCD_voidWrite_Command(Local_InitialAdd);
	for (Local_U8Counter = 0; Local_U8Counter < 8; Local_U8Counter++) {
		LCD_voidWrite_Data(Copy_U8PtrToVal[Local_U8Counter]);
	}
	LCD_voidWrite_Command(0x80);
}

void LCD_voidWrite_Command(u8 Copy_U8Command) {

	DIO_U8WritePortVal(LCD_DATAPORT, Copy_U8Command);
	DIO_U8WritePinVal(LCD_RS, DIO_U8LOW);
	DIO_U8WritePinVal(LCD_RW, DIO_U8LOW);
	DIO_U8WritePinVal(LCD_E, DIO_U8HIGH);
	Delay_ms(1);
	DIO_U8WritePinVal(LCD_E, DIO_U8LOW);
}

void LCD_voidWrite_Data(u8 Copy_U8Data) {
	DIO_U8WritePortVal(LCD_DATAPORT, Copy_U8Data);
	DIO_U8WritePinVal(LCD_RS, DIO_U8HIGH);
	DIO_U8WritePinVal(LCD_RW, DIO_U8LOW);
	DIO_U8WritePinVal(LCD_E, DIO_U8HIGH);
	Delay_ms(1);
	DIO_U8WritePinVal(LCD_E, DIO_U8LOW);
	//DIO_U8WritePinVal(LCD_RS, DIO_U8LOW);
}

void LCD_voidInit(void) {
	u8 Local_U8Counter = 21;
	while (Local_U8Counter > 0) {
		Delay_ms(1);
		Local_U8Counter--;
	}

	LCD_voidWrite_Command(0x30);
	Delay_ms(5);
	LCD_voidWrite_Command(0x30);

	Delay_ms(1);
	LCD_voidWrite_Command(0x30);

	LCD_voidWrite_Command(0b00111000);
	LCD_voidWrite_Command(0b0000110);
	LCD_voidWrite_Command(0b00001100);
}
