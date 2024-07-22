/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrhman Marzoq
 * @brief          : Toggle 2 Led using 2 Push button
 * @brief          : One single press and another multi press
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#define BASE_CLOCK   0x40021000
#define RCC_APB2ENR *((volatile unsigned long *)(BASE_CLOCK + 0x18))

#define BASE_GPIOA 0x40010800
#define GPIOA_CRL *((volatile unsigned long *)(BASE_GPIOA + 0x00))
#define GPIOA_CRH *((volatile unsigned long *)(BASE_GPIOA + 0x04))
#define GPIOA_IDR *((volatile unsigned long *)(BASE_GPIOA + 0x08))
#define GPIOA_ODR *((volatile unsigned long *)(BASE_GPIOA + 0x0C))

#define BASE_GPIOB 0x40010C00
#define GPIOB_CRL *((volatile unsigned long *)(BASE_GPIOB + 0x00))
#define GPIOB_CRH *((volatile unsigned long *)(BASE_GPIOB + 0x04))
#define GPIOB_IDR *((volatile unsigned long *)(BASE_GPIOB + 0x08))
#define GPIOB_ODR *((volatile unsigned long *)(BASE_GPIOB + 0x0C))



void clock_init()
{
	//	Bit 3 IOPBEN: IO port B clock enable
	//	Set and cleared by software.
	//	0: IO port B clock disabled
	//	1: IO port B clock enabled
	RCC_APB2ENR |= (1<<3);

	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled
	RCC_APB2ENR |= (1<<2);
}

void GPIO_init()
{
	//pin 1 port A input High Z
	GPIOA_CRL  = 0;
	GPIOA_CRL &= ~(0b11 << 4);
	GPIOA_CRL |=  (0b01 << 6);

	//pin 13 port A input High Z
	GPIOA_CRH = 0;
	GPIOA_CRH &= ~(0b11 << 20);
	GPIOA_CRH |= (0b01 << 22);

	//pin 1 port B OUTPUT
	GPIOB_CRL  = 0;
	GPIOB_CRL |= (0b01 << 4);
	GPIOB_CRL &= ~(0b11 << 6);

	//pin 13 port B OUTPUTs
	GPIOB_CRH = 0;
	GPIOB_CRH |= (0b01 << 20);
	GPIOB_CRH &= ~(0b11 << 22);
}



int main(void)
{
	clock_init();
	GPIO_init();
	while (1)
	{
		// PA1 Push button PUR
		if ( ((GPIOA_IDR & (1<<1)) >> 1) == 0 ) // press
		{
			GPIOB_ODR ^= (1<<1);
			while ( ((GPIOA_IDR & (1<<1)) >> 1) == 0 ); //Single pressing
		}
		// PA13 Push button PDR
		if ( ((GPIOA_IDR & (1<<13)) >> 13) == 1 ) // press
		{
			// Multi Pressing
			GPIOB_ODR ^= (1<<13);
		}
		for(volatile int delay = 0; delay < 20000; delay++);
	}
}
