/*
 * Buzzer_Prog.c
 *
 *  Created on: Apr 1, 2016
 *      Author: aya osama
 */


#include "Types.h"
#include "DIO_interface.h"
#include "Buzzer_Interface.h"

extern void Buzzer_voidRun(void)
{
	DIO_u8WritePinVal(DIO_u8PIN0,u8ONE);
}

extern void Buzzer_voidStop(void)
{
	DIO_u8WritePinVal(DIO_u8PIN0,u8ZERO);
}
