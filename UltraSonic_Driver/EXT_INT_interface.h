/*
 * EXT_INT_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_




/*****************************************************************/
/***********************Public Functions**************************/
/*****************************************************************/

/*Comment!: Ext_INT initialization function */
void EXT_INT_voidInit(void);

/*Comment!: Choose Ext_INT to enable with it's Characteristic */
void EXT_INT_voidEnable(u8 Copy_U8ExtIntSelect, u8 Copy_U8ExtIntModeSelect,
		u8 Copy_U8ExtIntDisable);

/*Comment!: Choose Ext_INT to disable */
void EXT_INT_voidDisable(u8 Copy_U8ExtIntSelect);

/*Comment!: Set_ISR_FUN for INT0 */
void EXT_INT0_ISR(void (*Copy_voidPtrToFun)(void));

/*Comment!: Set_ISR_FUN for INT1 */
void EXT_INT1_ISR(void (*Copy_voidPtrToFun)(void));

/*Comment!: Set_ISR_FUN for INT2 */
void EXT_INT2_ISR(void (*Copy_voidPtrToFun)(void));



/*****************************************************************/
/***********************Public Definitions************************/
/*****************************************************************/

/*Comment!: Choose EXT_INT Number */
#define E_INT0	0
#define E_INT1	1
#define E_INT2	2

/*Comment!: Choose EXT_INT 0,1 Mode */
#define E_0_1_LOW_LEVER			0
#define E_0_1_LOGICAL_CHANGE	1
#define E_0_1_FALLING_EDGE		2
#define E_0_1_RISING_EDGE		3

/*Comment!: Choose EXT_INT 2 Mode */
#define E_2_FALLING_EDGE	0
#define E_2_RISING_EDGE		1


#endif /* EXT_INT_INTERFACE_H_ */
