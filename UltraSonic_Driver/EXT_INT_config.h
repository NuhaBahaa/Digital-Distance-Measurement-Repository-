/*
 * EXT_INT_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_



/*Comment!: MCUCR Register */
/*Range!: HIGH ~ LOW */
#define ISC11	LOW
#define ISC10	LOW
#define ISC01	LOW
#define ISC00	HIGH


/*Comment!: MCUCSR Register */
/*Range!: HIGH ~ LOW */
#define ISC2	LOW

/*Comment!: GICR Register */
/*Range!: HIGH ~ LOW */
#define INT1	LOW
#define INT0	HIGH
#define INT2	LOW

/*Comment!: GIFR Register */
/*Range!: HIGH ~ LOW */
#define INTF1	LOW
#define INTF0	LOW
#define INTF2	LOW



#endif /* EXT_INT_CONFIG_H_ */
