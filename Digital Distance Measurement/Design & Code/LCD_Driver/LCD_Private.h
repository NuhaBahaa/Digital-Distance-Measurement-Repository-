/*
 * LCD_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


#define conc(bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7)	conchelper(bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7)
#define conchelper(b0,b1,b2,b3,b4,b5,b6,b7)	0b##b7##b6##b5##b4##b3##b2##b1##b0


#define LCD_DisplayControl	conc(LCD_CursorBlink,LCD_Cursor,LCD_LCDState,1,0,0,0,0)

#define FunctionSet	0b00111100
#define SetCGRAMAddress	0b01000000
#define SetDDRAMAddress	0b10000000

extern void LCD_voidWriteCommand(u8 LCD_u8CopyCommand);

extern void LCD_voidWriteData(u8 LCD_u8CopyData);


#endif /* LCD_PRIVATE_H_ */
