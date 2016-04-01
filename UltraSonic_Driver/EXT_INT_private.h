/*
 * EXT_INT_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_

/*Comment!: EXT_INT control registers */
#define EXT_MCUCR 	(volatile u8*)(0x55)
#define EXT_MCUCSR 	(volatile u8*)(0x54)
#define EXT_GICR	(volatile u8*)(0x5B)
#define EXT_GIFR	(volatile u8*)(0x5A)

/*Comment!: EXT_INT Registers with initial value */
#define EXT_MCUCR_INIT		Conc(ISC00, ISC01, ISC10, ISC11, LOW, LOW, LOW, LOW)
#define EXT_MCUCSR_INIT		Conc(LOW, LOW, LOW, LOW, LOW, LOW, ISC2, LOW)
#define EXT_GICR_INIT		Conc(LOW, LOW, LOW, LOW, LOW, INT2, INT0, INT1)
#define EXT_GIFR_INIT		Conc(LOW, LOW, LOW, LOW, LOW, INTF2, INTF0, INTF1)

/*Comment!: MCUCR Register */
#define EXT_ISC11	3
#define EXT_ISC10	2
#define EXT_ISC01	1
#define EXT_ISC00	0


/*Comment!: MCUCSR Register */
#define EXT_ISC2	6

/*Comment!: GICR Register */
#define EXT_INT1	7
#define EXT_INT0	6
#define EXT_INT2	5

/*Comment!: GIFR Register */
#define EXT_INTF1	7
#define EXT_INTF0	6
#define EXT_INTF2	5

/*Comment!: Concatenation function */
#define Conc(x1,x2,x3,x4,x5,x6,x7,x8) ConcHelper(x1,x2,x3,x4,x5,x6,x7,x8)
#define ConcHelper(b1,b2,b3,b4,b5,b6,b7,b8) 0b##b8##b7##b6##b5##b4##b3##b2##b1

#endif /* EXT_INT_PRIVATE_H_ */
