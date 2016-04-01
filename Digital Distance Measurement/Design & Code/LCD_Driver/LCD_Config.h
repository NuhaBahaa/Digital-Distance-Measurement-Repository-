/*
 * LCD_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*
#define	LCD_D0	DIO_u8PIN0
#define	LCD_D1	DIO_u8PIN1
#define	LCD_D2	DIO_u8PIN2
#define	LCD_D3	DIO_u8PIN3
#define	LCD_D4	DIO_u8PIN4
#define	LCD_D5	DIO_u8PIN5
#define	LCD_D6	DIO_u8PIN6
#define	LCD_D7	DIO_u8PIN7*/

#define LCD_DataPort	DIO_u8Port3

#define	LCD_RSPin	DIO_u8PIN16
#define LCD_RWPin	DIO_u8PIN17
#define	LCD_EnablePin	DIO_u8PIN18

#define	LCD_InitState	LCD_u8Disable

#define LCD_CursorInitDir	LCD_CursorIncrement

#define LCD_LCDState	LCD_ON
#define LCD_Cursor		Cursor_On
#define LCD_CursorBlink	BlinkCursor_Off

#endif /* LCD_CONFIG_H_ */
