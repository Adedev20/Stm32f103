/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Emmanuel Oyedokun
 * @brief          : Main program body
 * This is a test program to blink Stm32f103c8t6 onboard led (PC13) and another
 * led on PA3.
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
		uint32_t *pPortCModeReg =  (uint32_t*)  0x40011004; //Pointer address for PortC Mode reg
		uint32_t *pPortAModeReg  = (uint32_t*)  0x40010800; //Pointer address for PortA Mode reg
		uint32_t *pPinRegC       = (uint32_t*)  0x4001100C; //Pointer address for PortC ODR
		uint32_t *pPinRegA       = (uint32_t*)  0x4001080C; //Pointer address for PortC ODR


		//Enable the clock for GPIOC
		*pClkcontReg |= (5 << 2);   //enable clock for PortC & PortA




		*pPortCModeReg &= ~(15 << 20);  //Clear the mode register for port c
		*pPortCModeReg |=  (1 << 21);   //Set the mode register for portc
		*pPortAModeReg &= ~(15 << 12);  //clear the mode register for port a
		*pPortAModeReg |=  (1 << 13);   //set the mode register for port a


		while(1)
		{

			*pPinRegC  |= (1 << 13);  //Set the 13th bit to turn pin PC13 turn on
			*pPinRegA |= (1 <<  3);   //Set the 13th bit to turn pin PA3 turn on
			for (int i = 0; i< 200000; i++); //Some delay

			*pPinRegC  &= ~(1 << 13);  //clear the 13th bit to turn pin PC13 turn off
			*pPinRegA &= ~(1 <<  3);   //clear the 3rd bit to turn pin PA3 turn off
			for (int i = 0; i< 200000; i++);

		}

}


