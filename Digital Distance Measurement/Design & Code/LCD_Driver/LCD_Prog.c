/*
 * LCD_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */
#include "types.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "Delay.h"
#include "Delay_Config.h"
#include "util.h"

#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "stdlib.h"

extern void LCD_voidInit(void)
{
	Delay_ms(20);
	LCD_voidWriteCommand(0b00110000);
	Delay_ms(5);
	LCD_voidWriteCommand(0b00110000);
	Delay_ms(1);
	LCD_voidWriteCommand(0b00110000);


	LCD_voidWriteCommand(LCD_CursorInitDir);
	LCD_voidWriteCommand(LCD_DisplayControl);
	LCD_voidWriteCommand(FunctionSet);



}


extern void LCD_voidWriteCommand(u8 LCD_u8CopyCommand)
{
	DIO_u8WritePortVal(LCD_DataPort,LCD_u8CopyCommand);
	DIO_u8WritePinVal(LCD_RSPin,LCD_u8CommandMode);

	DIO_u8WritePinVal(LCD_RWPin,LCD_u8Write);

	DIO_u8WritePinVal(LCD_EnablePin,LCD_u8Enable);
	Delay_ms(1);

	DIO_u8WritePinVal(LCD_EnablePin,LCD_u8Disable);


}

extern void LCD_voidWriteData(u8 LCD_u8CopyData)
{
	DIO_u8WritePortVal(LCD_DataPort,LCD_u8CopyData);
	DIO_u8WritePinVal(LCD_RSPin,LCD_u8DataMode);
	DIO_u8WritePinVal(LCD_RWPin,LCD_u8Write);
	DIO_u8WritePinVal(LCD_EnablePin,LCD_u8Enable);
	Delay_ms(1);
	DIO_u8WritePinVal(LCD_EnablePin,LCD_u8Disable);

}


extern u8 LCD_u8WriteCustomChar(u8 LCD_u8CopyCharArr[][8],u8 LCD_u8CopyCharCount,u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 Local_u8FunState=u8Error;
	u8 Local_u8LoopCounter;
	u8 LCD_u8CopyByteCount=LCD_u8CopyCharCount*8;
	if(LCD_u8CopyCharCount<=8)
	{
		Local_u8FunState=u8OK;
	LCD_voidWriteCommand(SetCGRAMAddress);
	for(Local_u8LoopCounter=0;Local_u8LoopCounter<LCD_u8CopyByteCount;Local_u8LoopCounter++)
	{
		LCD_voidWriteData(LCD_u8CopyCharArr[0][Local_u8LoopCounter]);

	}

	//LCD_voidWriteCommand(SetDDRAMAddress);
	LCD_u8GoToXY(Copy_u8X-LCD_u8CopyCharCount,Copy_u8Y);
	for(Local_u8LoopCounter=LCD_u8CopyCharCount;Local_u8LoopCounter>0;Local_u8LoopCounter--)
		{
			LCD_voidWriteData(Local_u8LoopCounter-1);
		}
	}
	else
	{
		Local_u8FunState=u8Error;
	}

	return Local_u8FunState;
}


extern u8 LCD_u8WriteString(u8* LCD_u8CopyString)
{
	u8 Local_u8FunState=u8Error;
	u8 Local_LoopCounter=0;
	while((LCD_u8CopyString[Local_LoopCounter]!='\0')&&(Local_LoopCounter<16))
	{
		LCD_voidWriteData(LCD_u8CopyString[Local_LoopCounter]);
		Local_LoopCounter++;
	}

	if(Local_LoopCounter==16)
	{
		Local_u8FunState=u8Error;
	}
	else
	{
		Local_u8FunState=u8OK;
	}

	return Local_u8FunState;
}

extern u8 LCD_u8Control(u8 Copy_u8Command)
{
	u8 Local_u8FunState=u8Error;
		switch(Copy_u8Command)
		{
		case LCD_CursorIncrement:
		{
			LCD_voidWriteCommand(LCD_CursorIncrement);
			Local_u8FunState=u8OK;
			break;
		}

		case LCD_CursorDecrement:
		{
			LCD_voidWriteCommand(LCD_CursorDecrement);
			Local_u8FunState=u8OK;
			break;

		}
		case LCD_Clear:
		{
			LCD_voidWriteCommand(LCD_Clear);
			Delay_ms(6);
			Local_u8FunState=u8OK;
			break;
		}

		case LCD_SetCursorHome:
		{
			LCD_voidWriteCommand(LCD_SetCursorHome);
			Delay_ms(6);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_TurnOn:
		{
			LCD_voidWriteCommand(0b00001110);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_TurnOff:
		{
			LCD_voidWriteCommand(0b00001010);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_TurnCursorOn:
		{
			LCD_voidWriteCommand(0b00001110);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_TurnCursorOff:
		{
			LCD_voidWriteCommand(0b00001100);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_TurnBlinkOn:
		{
			LCD_voidWriteCommand(0b00001111);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_TurnBlinkOff:
		{
			LCD_voidWriteCommand(0b00001110);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_ShiftStrRight:
		{
			LCD_voidWriteCommand(0b00011100);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_ShiftStrLeft:
		{
			LCD_voidWriteCommand(0b00011000);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_ShiftCursorRight:
		{
			LCD_voidWriteCommand(0b00010100);
			Local_u8FunState=u8OK;
			break;
		}
		case LCD_ShiftCursorLeft:
		{
			LCD_voidWriteCommand(0b00010000);
			Local_u8FunState=u8OK;
			break;
		}
		default:
		{
			Local_u8FunState=u8Error;
			break;
		}

		}
		return Local_u8FunState;


}

extern u8 LCD_u8GoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 Local_u8FunState=u8Error;
	u8 Local_u8Position=0;
	if((Copy_u8X<16)&&(Copy_u8Y<2))
	{
		Local_u8Position=(1<<7)|(Copy_u8Y<<6)|(Copy_u8X);
		LCD_voidWriteCommand(Local_u8Position);
		Local_u8FunState=u8OK;
	}
	else
	{
		Local_u8FunState=u8Error;
	}
	return Local_u8FunState;
}

extern void LCD_voidWriteFloat(f32 Copy_f32Number)
{
	char Local_charBefor[2];
		char Local_charAfter[2];
		u16 Local_u16BeforPoint=(u16)Copy_f32Number;
		u32 Local_u32AfterPoint=(u32)(Copy_f32Number*100)%100;
		itoa(Local_u16BeforPoint,Local_charBefor,10);
		LCD_u8WriteString(Local_charBefor);
		LCD_voidWriteData('.');
		itoa(Local_u32AfterPoint,Local_charAfter,10);
		if(Local_u32AfterPoint<10)
		{
			LCD_u8WriteString("0");
		}
		LCD_u8WriteString(Local_charAfter);
}
