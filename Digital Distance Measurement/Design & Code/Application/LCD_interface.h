/*
 * LCD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/*****************************************************************/
/***********************Public Definitions************************/
/*****************************************************************/

#define LCD_ENABLED		1
#define LCD_DISABLED	0


/*****************************************************************/
/***********************Public Functions**************************/
/*****************************************************************/

/*Comment!: Initialization Function */
void LCD_voidInit(void);

/*Comment!: Write Command instruction to LCD controller */
void LCD_voidWrite_Command(u8 Copy_U8Command);

/*Comment!: Write Date to LCD data bus */
void LCD_voidWrite_Data(u8 Copy_U8Data);

void LCD_voidStoreData(u8 Copy_U8Addr,u8* Copy_U8PtrToVal );

void LCD_voidWriteString(u8* CopyU8PtrToVal);


#endif /* LCD_INTERFACE_H_ */
