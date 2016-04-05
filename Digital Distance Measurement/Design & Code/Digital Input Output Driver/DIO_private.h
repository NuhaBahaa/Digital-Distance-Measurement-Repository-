/*
 * DIO_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*Comment!: Port Initial Direction  */
#define DIO_u8PORTADIR	conc(DIO_u8PIN0_INITDIR, DIO_u8PIN1_INITDIR, DIO_u8PIN2_INITDIR, DIO_u8PIN3_INITDIR,\
							 DIO_u8PIN4_INITDIR, DIO_u8PIN5_INITDIR, DIO_u8PIN6_INITDIR, DIO_u8PIN7_INITDIR)

#define DIO_u8PORTBDIR	conc(DIO_u8PIN8_INITDIR, DIO_u8PIN9_INITDIR, DIO_u8PIN10_INITDIR, DIO_u8PIN11_INITDIR,\
							 DIO_u8PIN12_INITDIR, DIO_u8PIN13_INITDIR, DIO_u8PIN14_INITDIR, DIO_u8PIN15_INITDIR)

#define DIO_u8PORTCDIR	conc(DIO_u8PIN16_INITDIR, DIO_u8PIN17_INITDIR, DIO_u8PIN18_INITDIR, DIO_u8PIN19_INITDIR,\
							 DIO_u8PIN20_INITDIR, DIO_u8PIN21_INITDIR, DIO_u8PIN22_INITDIR, DIO_u8PIN23_INITDIR)

#define DIO_u8PORTDDIR	conc(DIO_u8PIN24_INITDIR, DIO_u8PIN25_INITDIR, DIO_u8PIN26_INITDIR, DIO_u8PIN27_INITDIR,\
							 DIO_u8PIN28_INITDIR, DIO_u8PIN29_INITDIR, DIO_u8PIN30_INITDIR, DIO_u8PIN31_INITDIR)


/*Comment!: Port Initial Value  */
#define DIO_u8PORTAVAL	conc(DIO_u8PIN0_INITVAL, DIO_u8PIN1_INITVAL,  DIO_u8PIN2_INITVAL,  DIO_u8PIN3_INITVAL,\
							 DIO_u8PIN4_INITVAL, DIO_u8PIN5_INITVAL,  DIO_u8PIN6_INITVAL,  DIO_u8PIN7_INITVAL)

#define DIO_u8PORTBVAL	conc(DIO_u8PIN8_INITVAL, DIO_u8PIN9_INITVAL,  DIO_u8PIN10_INITVAL,  DIO_u8PIN11_INITVAL,\
							 DIO_u8PIN12_INITVAL, DIO_u8PIN13_INITVAL,  DIO_u8PIN14_INITVAL,  DIO_u8PIN15_INITVAL)

#define DIO_u8PORTCVAL	conc(DIO_u8PIN16_INITVAL, DIO_u8PIN17_INITVAL,  DIO_u8PIN18_INITVAL,  DIO_u8PIN19_INITVAL,\
							 DIO_u8PIN20_INITVAL, DIO_u8PIN21_INITVAL,  DIO_u8PIN22_INITVAL,  DIO_u8PIN23_INITVAL)

#define DIO_u8PORTDVAL	conc(DIO_u8PIN24_INITVAL, DIO_u8PIN25_INITVAL,  DIO_u8PIN26_INITVAL,  DIO_u8PIN27_INITVAL,\
							 DIO_u8PIN28_INITVAL, DIO_u8PIN29_INITVAL,  DIO_u8PIN30_INITVAL,  DIO_u8PIN31_INITVAL)







/*Comment!: Concatination function to concatinate 8 bits into one byte   */
#define conc(bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7)	conchelper(bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7)
#define conchelper(b0,b1,b2,b3,b4,b5,b6,b7)	0b##b7##b6##b5##b4##b3##b2##b1##b0


/*Comment!: Define Ports Addresses */
#define DIO_u8PORTA ((volatile u8*)(0x3B))
#define DIO_u8DDRA ((volatile u8*)(0x3A))
#define DIO_u8PINA ((volatile u8*)(0x39))
#define DIO_u8PORTB ((volatile u8*)(0x38))
#define DIO_u8DDRB ((volatile u8*)(0x37))
#define DIO_u8PINB ((volatile u8*)(0x36))
#define DIO_u8PORTC ((volatile u8*)(0x35))
#define DIO_u8DDRC ((volatile u8*)(0x34))
#define DIO_u8PINC ((volatile u8*)(0x33))
#define DIO_u8PORTD ((volatile u8*)(0x32))
#define DIO_u8DDRD ((volatile u8*)(0x31))
#define DIO_u8PIND ((volatile u8*)(0x30))


#define LastPinNum	31
#define LastPortNum	3


#endif /* DIO_PRIVATE_H_ */
