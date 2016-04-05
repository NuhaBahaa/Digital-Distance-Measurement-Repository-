/*
 * UltraSonic_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */
#include "Types.h"
#include "DIO_interface.h"
#include "EXT_INT_interface.h"
#include "Timer_interface.h"
#include "S4MDelay.h"
#include "UltraSonic_private.h"
#include "UltraSonic_config.h"
#include "UltraSonic_interface.h"

u8 static OV_Flag = 0;

void UltraSonic_voidInit(void) {
	SetTIM1_OVF_ISR(ULT_TIM1_ISR_Main);
}


void ULT_TIM1_ISR_Main(void){
	OV_Flag = 1;
	Timer1_voidWriteReg(LOW);

}

u8 UltraSoinc_U8ReadDistance(u16* Copy_U16DisanceVal) {
	u8 Local_U8ErrorFlag = U8_NOERROR;
	u8 Local_EchoVal = 0;
	u16 Local_TimerRead = 0;
	DIO_U8WritePinVal(TRIG, LOW);
	Delay_us(5);
	DIO_U8WritePinVal(TRIG, HIGH);
	Delay_us(10);
	DIO_U8WritePinVal(TRIG, LOW);
	while (!Local_EchoVal) {
		DIO_U8ReadPinVal(ECHO, &Local_EchoVal);
	}
	Timer1_voidInit();
	while (Local_EchoVal) {
		DIO_U8ReadPinVal(ECHO, &Local_EchoVal);
		if (OV_Flag == 1){
			OV_Flag = 0;
			Local_U8ErrorFlag = U8_ERROR;
			break;
		}
	}
	Timer1_Stop();
	Timer1_voidReadReg(&Local_TimerRead);
	*Copy_U16DisanceVal = (Local_TimerRead * 0.028) + 1.093;
	Timer1_voidWriteReg(LOW);

	return Local_U8ErrorFlag;
}




