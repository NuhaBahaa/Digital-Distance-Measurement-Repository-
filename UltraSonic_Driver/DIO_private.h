/*
 * DIO_private.h
 *
 *  Created on: ??�/??�/????
 *      Author: muslim
 */

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/*Comment!: Initialize PORTA Direction */
#define DIO_U8PORTADIR Conc(DIO_U8PIN0_INITDIR, DIO_U8PIN1_INITDIR, DIO_U8PIN2_INITDIR,\
DIO_U8PIN3_INITDIR, DIO_U8PIN4_INITDIR, DIO_U8PIN5_INITDIR, DIO_U8PIN6_INITDIR, DIO_U8PIN7_INITDIR )

/*Comment!: Initialize PORTB Direction */
#define DIO_U8PORTBDIR Conc(DIO_U8PIN8_INITDIR, DIO_U8PIN9_INITDIR, DIO_U8PIN10_INITDIR,\
DIO_U8PIN11_INITDIR, DIO_U8PIN12_INITDIR, DIO_U8PIN13_INITDIR, DIO_U8PIN14_INITDIR, DIO_U8PIN15_INITDIR )

/*Comment!: Initialize PORTC Direction */
#define DIO_U8PORTCDIR Conc(DIO_U8PIN16_INITDIR, DIO_U8PIN17_INITDIR, DIO_U8PIN18_INITDIR,\
DIO_U8PIN19_INITDIR, DIO_U8PIN20_INITDIR, DIO_U8PIN21_INITDIR, DIO_U8PIN22_INITDIR, DIO_U8PIN23_INITDIR )

/*Comment!: Initialize PORTD Direction */
#define DIO_U8PORTDDIR Conc(DIO_U8PIN24_INITDIR, DIO_U8PIN25_INITDIR, DIO_U8PIN26_INITDIR,\
DIO_U8PIN27_INITDIR, DIO_U8PIN28_INITDIR, DIO_U8PIN29_INITDIR, DIO_U8PIN30_INITDIR, DIO_U8PIN31_INITDIR )


/*Comment!: Initialize PORTA Value */
#define DIO_U8PORTAVAL Conc(DIO_U8PIN0_INITVAL, DIO_U8PIN1_INITVAL, DIO_U8PIN2_INITVAL,\
DIO_U8PIN3_INITVAL, DIO_U8PIN4_INITVAL, DIO_U8PIN5_INITVAL, DIO_U8PIN6_INITVAL, DIO_U8PIN7_INITVAL )

/*Comment!: Initialize PORTB Value */
#define DIO_U8PORTBVAL Conc(DIO_U8PIN8_INITVAL, DIO_U8PIN9_INITVAL, DIO_U8PIN10_INITVAL,\
DIO_U8PIN11_INITVAL, DIO_U8PIN12_INITVAL, DIO_U8PIN13_INITVAL, DIO_U8PIN14_INITVAL, DIO_U8PIN15_INITVAL )

/*Comment!: Initialize PORTC Value */
#define DIO_U8PORTCVAL Conc(DIO_U8PIN16_INITVAL, DIO_U8PIN17_INITVAL, DIO_U8PIN18_INITVAL,\
DIO_U8PIN19_INITVAL, DIO_U8PIN20_INITVAL, DIO_U8PIN21_INITVAL, DIO_U8PIN22_INITVAL, DIO_U8PIN23_INITVAL )

/*Comment!: Initialize PORTD Value */
#define DIO_U8PORTDVAL Conc(DIO_U8PIN24_INITVAL, DIO_U8PIN25_INITVAL, DIO_U8PIN26_INITVAL,\
DIO_U8PIN27_INITVAL, DIO_U8PIN28_INITVAL, DIO_U8PIN29_INITVAL, DIO_U8PIN30_INITVAL, DIO_U8PIN31_INITVAL )

/*Comment!: Conc Function */
#define Conc(x1,x2,x3,x4,x5,x6,x7,x8) ConcHelper(x1,x2,x3,x4,x5,x6,x7,x8)
#define ConcHelper(b1,b2,b3,b4,b5,b6,b7,b8) 0b##b8##b7##b6##b5##b4##b3##b2##b1

/*Comment!: DIO Registers */
#define DIO_PORTA 	(volatile u8 *)(0x3B)
#define DIO_DDRA 	(volatile u8 *)(0x3A)
#define DIO_PINA 	(volatile u8 *)(0x39)

#define DIO_PORTB 	(volatile u8 *)(0x38)
#define DIO_DDRB 	(volatile u8 *)(0x37)
#define DIO_PINB 	(volatile u8 *)(0x36)

#define DIO_PORTC 	(volatile u8 *)(0x35)
#define DIO_DDRC 	(volatile u8 *)(0x34)
#define DIO_PINC 	(volatile u8 *)(0x33)

#define DIO_PORTD 	(volatile u8 *)(0x32)
#define DIO_DDRD 	(volatile u8 *)(0x31)
#define DIO_PIND 	(volatile u8 *)(0x30)


#endif /* DIO_PRIVATE_H_ */
