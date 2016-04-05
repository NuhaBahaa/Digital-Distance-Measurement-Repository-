/*
 * Delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: 7ossam
 */

#include "delay_config.h"


#ifndef DELAY_H_
#define DELAY_H_


#define DELAY_voidDELAY(Copy_u8DelayVal)  	do{				\
						u32 Local_u32LoopItelation;									\
						for(Local_u32LoopItelation = (u32)(((Copy_u8DelayVal) * (DELAY_u32SYSCLOCK))/(40000))		\
						; Local_u32LoopItelation > 0 ; Local_u32LoopItelation--)					\
						{												\
							__asm__("NOP");										\
						}}												\
					while(0)

#endif /* DELAY_H_ */
