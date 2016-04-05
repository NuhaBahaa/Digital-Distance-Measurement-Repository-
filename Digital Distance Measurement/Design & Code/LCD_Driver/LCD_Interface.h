/*
 * LCD_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define	LCD_u8Disable	0
#define	LCD_u8Enable	1

#define LCD_u8Read	1
#define LCD_u8Write	0

#define LCD_u8CommandMode	0
#define	LCD_u8DataMode	1

#define LCD_CursorIncrement	6
#define LCD_CursorDecrement	4

#define LCD_Clear	1

#define LCD_SetCursorHome	2

#define LCD_TurnOn	10
#define LCD_TurnOff	11

#define LCD_TurnCursorOn	12
#define LCD_TurnCursorOff	13

#define LCD_TurnBlinkOn	14
#define LCD_TurnBlinkOff	15

#define LCD_ShiftStrLeft	16
#define LCD_ShiftStrRight	17

#define LCD_ShiftCursorLeft	18
#define LCD_ShiftCursorRight	19

#define LCD_ON	1
#define LCD_OFF	0

#define	Cursor_On	1
#define Cursor_Off	0

#define BlinkCursor_On	1
#define BlinkCursor_Off	0


extern void LCD_voidInit(void);

extern u8 LCD_u8WriteCustomChar(u8 LCD_u8CopyCharArr[][8],u8 LCD_u8CopyCharCount,u8 Copy_u8X, u8 Copy_u8Y);

extern u8 LCD_u8WriteString(u8* LCD_u8CopyString);

extern u8 LCD_u8Control(u8 Copy_u8Command);

extern u8 LCD_u8GoToXY(u8 Copy_u8X, u8 Copy_u8Y);

extern void LCD_voidWriteFloat(f32 Copy_f32Number);


#endif /* LCD_INTERFACE_H_ */
