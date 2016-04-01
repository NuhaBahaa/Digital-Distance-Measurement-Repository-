/*
 * main.c
 *
 *  Created on: Apr 1, 2016
 *      Author: aya osama
 */


#include "Types.h"
#include "DIO_interface.h"
#include "Buzzer_Interface.h"
#include "Delay.h"

int main (void)
{
	DIO_voidInit();
	while(1)
	{
		Buzzer_voidRun();
		DELAY_voidDELAY(500);
		Buzzer_voidStop();
		DELAY_voidDELAY(500);
	}
	return 0;
}
