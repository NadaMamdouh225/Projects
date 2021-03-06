/*
 * SSD_prg.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_int.h"

static const u8 CGS_u8SSD_Nums[10] =
	{
			0b00111111 ,  // 0
			0b00000110 ,  // 1
			0b01011011 ,  // 2
			0b01001111 ,  // 3
			0b01100110 ,  // 4
			0b01101101 ,  // 5
			0b01111101 ,  // 6
			0b00000111 ,  // 7
			0b01111111 ,  // 8
			0b01101111 ,  // 9


	};

void SSD_vInit(void)
{
	DIO_vSetPortDir(SSD_PORT,0xff);
}

void SSD_vDisplayNum(u8 A_u8Num)
{
	/* input validation*/
    if(A_u8Num < 10)
    {
#if SSD_TYPE==COM_CATHODE
    	DIO_vSetPortVal(SSD_PORT, CGS_u8SSD_Nums[A_u8Num]);
#elif SSD_TYPE==COM_ANODE
    	DIO_vSetPortVal(SSD_PORT, ~CGS_u8SSD_Nums[A_u8Num]);
#endif
    }
}
void SSD_vTurnOff(void)
{
#if SSD_TYPE==COM_CATHODE
  DIO_vSetPortVal(SSD_PORT,0x00);
#elif SSD_TYPE==COM_ANODE
  DIO_vSetPortVal(SSD_PORT,0xff);
#endif
}
