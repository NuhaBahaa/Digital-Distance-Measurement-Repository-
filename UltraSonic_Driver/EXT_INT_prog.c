/*
 * EXT_INT_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#include "Types.h"
#include "EXT_INT_config.h"
#include "EXT_INT_private.h"
#include "EXT_INT_interface.h"
#include "util.h"

static void (*INT0_Ptr_ISR)(void);

static void (*INT1_Ptr_ISR)(void);

static void (*INT2_Ptr_ISR)(void);

void EXT_INT_voidInit(void) {

	Assign(*EXT_MCUCR, EXT_MCUCR_INIT);
	Assign(*EXT_MCUCSR, EXT_MCUCSR_INIT);
	Assign(*EXT_GICR, EXT_GICR_INIT);
	Assign(*EXT_GIFR, EXT_GIFR_INIT);
}

void EXT_INT0_ISR(void (*Copy_voidPtrToFun)(void)) {
	INT0_Ptr_ISR = Copy_voidPtrToFun;
}

void EXT_INT1_ISR(void (*Copy_voidPtrToFun)(void)) {
	INT1_Ptr_ISR = Copy_voidPtrToFun;
}

void EXT_INT2_ISR(void (*Copy_voidPtrToFun)(void)) {
	INT2_Ptr_ISR = Copy_voidPtrToFun;
}

void EXT_INT_voidEnable(u8 Copy_U8ExtIntSelect, u8 Copy_U8ExtIntModeSelect,
		u8 Copy_U8ExtIntDisable) {
	switch (Copy_U8ExtIntSelect) {

	case E_INT0:
		/*Comment!: Set INT0 mode */
		*EXT_MCUCR = ClrBit(*EXT_MCUCR, EXT_ISC00);
		*EXT_MCUCR = ClrBit(*EXT_MCUCR, EXT_ISC01);
		*EXT_MCUCR = AssignBit(*EXT_MCUCR, EXT_ISC00,
				(Copy_U8ExtIntModeSelect & 0x01));
		*EXT_MCUCR = AssignBit(*EXT_MCUCR, EXT_ISC01,
				(Copy_U8ExtIntModeSelect >> 1));
		/*Comment!: Check if Interrupt is Enabled */
		if (Copy_U8ExtIntDisable == LOW) {
			/*Comment!: Enable Interrupt INTO */
			*EXT_GICR = SetBit(*EXT_GICR, EXT_INT0);
		}
		break;
	case E_INT1:
		/*Comment!: Set INT1 mode */
		*EXT_MCUCR = ClrBit(*EXT_MCUCR, EXT_ISC10);
		*EXT_MCUCR = ClrBit(*EXT_MCUCR, EXT_ISC11);
		*EXT_MCUCR = AssignBit(*EXT_MCUCR, EXT_ISC10,
				(Copy_U8ExtIntModeSelect & 0x01));
		*EXT_MCUCR = AssignBit(*EXT_MCUCR, EXT_ISC11,
				(Copy_U8ExtIntModeSelect >> 1));
		/*Comment!: Check if Interrupt is Enabled */
		if (Copy_U8ExtIntDisable == LOW) {
			/*Comment!: Enable Interrupt INT1 */
			*EXT_GICR = SetBit(*EXT_GICR, EXT_INT1);
		}
		break;
	case E_INT2:
		/*Comment!: Set INT2 mode */
		*EXT_MCUCSR = ClrBit(*EXT_MCUCSR, EXT_ISC2);
		*EXT_MCUCSR = AssignBit(*EXT_MCUCSR, EXT_ISC2,
				(Copy_U8ExtIntModeSelect & 0x01));
		/*Comment!: Check if Interrupt is Enabled */
		if (Copy_U8ExtIntDisable == LOW) {
			/*Comment!: Enable Interrupt INT2 */
			*EXT_GICR = SetBit(*EXT_GICR, EXT_INT2);
		}
		break;
	}
}

void EXT_INT_voidDisable(u8 Copy_U8ExtIntSelect) {
	switch (Copy_U8ExtIntSelect) {

	case E_INT0:
		/*Comment!: Disable INT0 */
		*EXT_GICR = ClrBit(*EXT_GICR, EXT_INT0);
		break;
	case E_INT1:
		/*Comment!: Disable INT1 */
		*EXT_GICR = ClrBit(*EXT_GICR, EXT_INT1);
		break;
	case E_INT2:
		/*Comment!: Disable INT2 */
		*EXT_GICR = ClrBit(*EXT_GICR, EXT_INT2);
		break;
	}

}

ISR(__vector_1) {

	INT0_Ptr_ISR();
}

ISR(__vector_2) {

	INT1_Ptr_ISR();
}

ISR(__vector_3) {

	INT2_Ptr_ISR();
}
