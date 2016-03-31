/*
 * DIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */
#include"types.h"
#include"DIO_config.h"
#include"DIO_interface.h"
#include"DIO_private.h"
#include"util.h"


/*Comment!: DDR Registers */
static volatile u8* const DIO_u8DDRArr[4]={DIO_u8DDRA, DIO_u8DDRB, DIO_u8DDRC, DIO_u8DDRD};

/*Comment!: Port Registers */
static volatile u8* const DIO_u8PORTArr[4]={DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD};

/*Comment!: PIN Registers */
static volatile u8* const DIO_u8PINArr[4]={DIO_u8PINA, DIO_u8PINB, DIO_u8PINC, DIO_u8PIND};


/* Comment!: Initialization function
 * 	Assign the Initial Dirction and values of the DIO Pins */
extern void DIO_VoidInit(void)
{


	*(DIO_u8DDRArr[0])=DIO_u8PORTADIR;
	*(DIO_u8DDRArr[1])=DIO_u8PORTBDIR;
	*(DIO_u8DDRArr[2])=DIO_u8PORTCDIR;
	*(DIO_u8DDRArr[3])=DIO_u8PORTDDIR;


	*(DIO_u8PORTA) = (~(DIO_u8PORTADIR)&(*(DIO_u8PORTA)))|(DIO_u8PORTADIR&DIO_u8PORTAVAL);
	*(DIO_u8PORTB) = (~(DIO_u8PORTBDIR)&(*(DIO_u8PORTB)))|(DIO_u8PORTBDIR&DIO_u8PORTBVAL);
	*(DIO_u8PORTC) = (~(DIO_u8PORTCDIR)&(*(DIO_u8PORTC)))|(DIO_u8PORTCDIR&DIO_u8PORTCVAL);
	*(DIO_u8PORTD) = (~(DIO_u8PORTDDIR)&(*(DIO_u8PORTD)))|(DIO_u8PORTDDIR&DIO_u8PORTDVAL);


}




/*Comment!: Read Pin Value
 *          Takes a Pin index and a pointer to save the the pin value at
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise*/
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx, u8* Copy_u8PtrToVal)
{
	u8 Local_u8FunState=u8Error;
	u8 Local_u8RegNum=Copy_u8PinIdx/8;
	u8 Local_u8BitNum=Copy_u8PinIdx%8;
	if((Copy_u8PinIdx<=LastPinNum)&&(GetBit((*DIO_u8DDRArr[Local_u8RegNum]), Local_u8BitNum)==DIO_u8INPUT))
	{
		*Copy_u8PtrToVal=GetBit((*DIO_u8PINArr[Local_u8RegNum]), Local_u8BitNum);
		Local_u8FunState=u8OK;

	}
	else
	{
		Local_u8FunState=u8Error;

	}

	return Local_u8FunState;

}


/*Comment!: Write Pin Value
 * 			Takes a Pin index and the pin value
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise */
extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx, u8 Copy_u8PinVal)
{
			u8 Local_u8FunState=u8Error;
			u8 Local_u8RegNum=Copy_u8PinIdx/8;
			u8 Local_u8BitNum=Copy_u8PinIdx%8;
			if((Copy_u8PinIdx<=LastPinNum)&&((GetBit((*DIO_u8DDRArr[Local_u8RegNum]), Local_u8BitNum)==DIO_u8OUTPUT)))
				{
					*DIO_u8PORTArr[Local_u8RegNum]=AssignBit((*DIO_u8PORTArr[Local_u8RegNum]), Local_u8BitNum, Copy_u8PinVal);
					Local_u8FunState=u8OK;

				}
				else
				{
					Local_u8FunState=u8Error;

				}

			return Local_u8FunState;

}


/*Comment!: Read Port Value
 * 			Takes a Port index and a pointer to save the the port value at
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise */
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrToVal)
{
	u8 Local_u8FunState=u8Error;
	if((Copy_u8PortIdx<=LastPortNum)&&(*DIO_u8DDRArr[Copy_u8PortIdx]==DIO_u8ALLINPUT))
					{

						*Copy_u8PtrToVal=*DIO_u8PINArr[Copy_u8PortIdx];
						Local_u8FunState=u8OK;

					}
					else
					{
						Local_u8FunState=u8Error;

					}

	return Local_u8FunState;

}


/*Comment!: Write Port Value
 * 			Takes a Port index and the port value
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise */
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal)
{
	u8 Local_u8FunState=u8Error;
	if((Copy_u8PortIdx<=LastPortNum)&&(*DIO_u8DDRArr[Copy_u8PortIdx]==DIO_u8ALLOUTPUT))
						{
							*DIO_u8PORTArr[Copy_u8PortIdx]= Copy_u8PortVal;
							Local_u8FunState=u8OK;

						}
						else
						{
							Local_u8FunState=u8Error;

						}


		return Local_u8FunState;

}


/*Comment!: Write Pin Direction
 * 			Takes a Pin index and the pin direction
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise */
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx, u8 Copy_u8PinDir)
{
	u8 Local_u8FunState=u8Error;
	u8 Local_u8RegNum=Copy_u8PinIdx/8;
	u8 Local_u8BitNum=Copy_u8PinIdx%8;
	if(Copy_u8PinIdx<=LastPinNum)
					{
						*DIO_u8DDRArr[Local_u8RegNum]=AssignBit((*DIO_u8DDRArr[Local_u8RegNum]), Local_u8BitNum, Copy_u8PinDir);
						Local_u8FunState=u8OK;

					}
					else
					{
						Local_u8FunState=u8Error;

					}



	return Local_u8FunState;


}


/*Comment!: Write Port Direction
 * 			Takes a Port index and the port direction
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise */
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir)
{
	u8 Local_u8FunState=u8Error;
	if(Copy_u8PortIdx<=LastPortNum)
							{
								*DIO_u8DDRArr[Copy_u8PortIdx]= Copy_u8PortDir;
								Local_u8FunState=u8OK;

							}
							else
							{
								Local_u8FunState=u8Error;

							}


			return Local_u8FunState;

}


/* Comment!: Read Pin Direction
 * 			Takes a Pin index and a pointer to the pin direction
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise */
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx, u8* Copy_u8PtrToDir)
{

	u8 Local_u8FunState=u8Error;
	u8 Local_u8RegNum=Copy_u8PinIdx/8;
	u8 Local_u8BitNum=Copy_u8PinIdx%8;
	if(Copy_u8PinIdx<=LastPinNum)
		{
			*Copy_u8PtrToDir=GetBit((*DIO_u8DDRArr[Local_u8RegNum]), Local_u8BitNum);
			Local_u8FunState=u8OK;

		}
		else
		{
			Local_u8FunState=u8Error;

		}


		return Local_u8FunState;

}

/* Comment!: Read Port Direction
 * 			Takes a Port index and a pointer to the port direction
 *           and returns the function state, Error if the Index is out of boundry
 *           and ok otherwise */
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PtrToDir)
{
	u8 Local_u8FunState=u8Error;
	if(Copy_u8PortIdx<=LastPortNum)
						{

							*Copy_u8PtrToDir=*DIO_u8DDRArr[Copy_u8PortIdx];
							Local_u8FunState=u8OK;
						}
						else
						{
							Local_u8FunState=u8Error;

						}

		return Local_u8FunState;

}
