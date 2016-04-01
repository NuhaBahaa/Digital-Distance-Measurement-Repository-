/*
 * UltraSonic_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_



void UltraSonic_voidInit(void);

u8 UltraSoinc_U8ReadDistance(u16* Copy_U16DisanceVal);

void ULT_TIM1_ISR_Main(void);


#endif /* ULTRASONIC_INTERFACE_H_ */
