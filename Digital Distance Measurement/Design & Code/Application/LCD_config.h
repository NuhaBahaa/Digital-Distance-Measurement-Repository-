/*
 * LCD_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



/*Comment!: Choose the DIO pins for LCD pins */
/*Range!: DIO_U8PIN0 ~ DIO_U8PIN31 */
#define LCD_D0	DIO_U8PIN0
#define LCD_D1	DIO_U8PIN1
#define LCD_D2	DIO_U8PIN2
#define LCD_D3	DIO_U8PIN3
#define LCD_D4	DIO_U8PIN4
#define LCD_D5	DIO_U8PIN5
#define	LCD_D6	DIO_U8PIN6
#define LCD_D7	DIO_U8PIN7

#define LCD_RS	DIO_U8PIN16
#define LCD_RW	DIO_U8PIN17
#define LCD_E	DIO_U8PIN18

#define LCD_DATAPORT	DIO_U8PORT3


/*Comment!: Choose the initial state for the LCD */
/*Range!: LCD_DISABLED ~ LCD_ENABLED */
#define INITIAL_STATE	LCD_DISABLED



#endif /* LCD_CONFIG_H_ */
