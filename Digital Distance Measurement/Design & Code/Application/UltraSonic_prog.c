/*
 * UltraSonic_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */
#include "Types.h"
#include "DIO_interface.h"
//#include "EXT_INT_interface.h"
#include "Timer_interface.h"
#include "S4MDelay.h"
#include "UltraSonic_private.h"
#include "UltraSonic_config.h"
#include "UltraSonic_interface.h"
#include "LCD_interface.h"

u8 static OV_Flag = 0;  // Flag to check if unexpected timer 1 overflow happened

void UltraSonic_voidInit(void) {		// call back function for timer 1
	SetTIM1_OVF_ISR(ULT_TIM1_ISR_Main); // setting the pointer to fun to be equal my ISR function
}

void ULT_TIM1_ISR_Main(void) { // My ISR function that i want to be executed when overflow happen
	OV_Flag = 1; // Set the flag to indicate overflow occured (error shouldn't happen)
	Timer1_Stop();
	Timer1_voidWriteReg(LOW);	// clear timer 1 register
	Timer1_Stop();
	LCD_voidWrite_Command(0x01);
	LCD_voidWriteString("Out of range");
}

u8 UltraSoinc_U8ReadDistance(u16* Copy_U16DisanceVal) {	// the main function that return distance
	u8 Local_U8ErrorFlag = U8_NOERROR;
	u8 Local_EchoVal = 0;
	u16 Local_TimerRead = 0;
	f64 Local_TempVal = 0;

	u8 Local_arr1[20] = { 0 };

	DIO_U8WritePinVal(TRIG, LOW);		// to initiate the ultrasonic
	Delay_us(5);
	DIO_U8WritePinVal(TRIG, HIGH);		// start ultrasonic
	Delay_us(15);
	DIO_U8WritePinVal(TRIG, LOW);
	//LCD_voidWriteString("lol1");
	while (!Local_EchoVal) {			// w8 for echo to be high
		DIO_U8ReadPinVal(ECHO, &Local_EchoVal);
	}
	//LCD_voidWriteString("lol2");
	Timer1_voidInit();			// start timer 1
	while (Local_EchoVal) {		//w8 for echo to be low
		DIO_U8ReadPinVal(ECHO, &Local_EchoVal);
		if (OV_Flag == 1) {		// if unexpected overflow occur
			OV_Flag = 0;
			Local_U8ErrorFlag = U8_ERROR;
			break;
		}
	}

	Timer1_Stop();			// stop timer 1
	Timer1_voidReadReg(&Local_TimerRead);	// read time


//	LCD_voidWrite_Command(0x01);
//	itoa(Local_TimerRead, Local_arr1, 10);
//	LCD_voidWrite_Command(0x80);
//	LCD_voidWriteString(Local_arr1);

	Timer1_voidWriteReg(LOW);	//clear timer 1 register
	Timer1_Stop();


	Local_TempVal = (((f64) (Local_TimerRead) *0.02941) + 1.284); // convert time to distance
	*Copy_U16DisanceVal = (u16) Local_TempVal;

	Timer1_voidWriteReg(LOW);	//clear timer 1 register
	Timer1_Stop();

//	itoa(*Copy_U16DisanceVal, Local_arr1, 10);
//	LCD_voidWrite_Command((0x80 | 0xC0));
//	LCD_voidWriteString(Local_arr1);

	return Local_U8ErrorFlag;
}

