/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Emmanuel Adedayo Oyedokun
 * @brief          : Read PB12 state to toggle an led @ PA3
 * @date 		   : 16/03/2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#include <stdint.h>

int main(void)
{
	    uint32_t *pClkcontReg   =  (uint32_t*)  0x40021018; //Pointer address for the clock reg
		//uint32_t *pPortCModeReg =  (uint32_t*)  0x40011004; //Pointer address for PortC Mode reg
		uint32_t *pPortBModeReg =  (uint32_t*)  0x40010C04; //Pointer address for PortB Mode reg
		uint32_t *pPortAModeReg  = (uint32_t*)  0x40010800; //Pointer address for PortA Mode reg
		//uint32_t *pPinRegC       = (uint32_t*)  0x4001100C; //Pointer address for PortC ODR
		uint32_t *pPinRegB       = (uint32_t*)  0x40010C08; //Pointer address for PortB IDR
		uint32_t *pPinRegA       = (uint32_t*)  0x4001080C; //Pointer address for PortA ODR


		//Enable the clock for GPIOC
		*pClkcontReg |= (3 << 2);   //enable clock for PortC, PortA & Port B




		//*pPortCModeReg &= ~(15 << 20);  //Clear the mode register for port c
		//*pPortCModeReg |=  (1 << 21);   //Set the mode register for portc
		*pPortAModeReg &= ~(15 << 12);  //clear the mode register for port a
		*pPortAModeReg |=  (2 << 12);   //set the mode register for port a
		*pPortBModeReg &= ~(15 << 16);   //clear the mode reg b
		*pPortBModeReg |=  (8 << 16);   //set the mode reg b


		while(1)
		{
			//Read status of PB12

			uint16_t pinStatus = (uint16_t)(*pPinRegB & 1 << 12);

			if (pinStatus){

			//*pPinRegC  |= (1 << 13);  //Set the 13th bit to turn pin PC13 turn on
			//*pPinRegA &= ~(1 <<  3);
			*pPinRegA |= (1 <<  3);   //Set the 13th bit to turn pin PA3 turn on
			//for (int i = 0; i< 200000; i++); //Some delay

			}else{

			//*pPinRegC  &= ~(1 << 13);  //clear the 13th bit to turn pin PC13 turn off
			//*pPinRegA |= (1 <<  3);
			*pPinRegA &= ~(1 <<  3);   //clear the 3rd bit to turn pin PA3 turn off
			//for (int i = 0; i< 200000; i++);

		}
	}

}
