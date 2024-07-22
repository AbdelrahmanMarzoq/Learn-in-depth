/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrhman Marzoq
 * @brief          : Main program body
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

#include "../STM32F103C6_MCAL_Drivers/GPIO/STM32F103C6_GPIO_Driver.h"


void clock_init()
{
	// Enable CLK FOR GPIO B
	RCC_GPIOB_CLK_EN;

	// Enable CLK FOR GPIO A
	RCC_GPIOA_CLK_EN;
}


void GPIO_init()
{
	GPIO_PinConfig_t PIN1A;
	PIN1A.GPIO_PinNumber = GPIO_PIN1;
	PIN1A.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	GPIO_INIT(GPIOA, &PIN1A);


	GPIO_PinConfig_t PIN13A;
	PIN13A.GPIO_PinNumber = GPIO_PIN13;
	PIN13A.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	GPIO_INIT(GPIOA, &PIN13A);

	GPIO_PinConfig_t PIN1B;
	PIN1B.GPIO_PinNumber = GPIO_PIN1;
	PIN1B.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PIN1B.GPIO_OUTPUT_Speed = GPIO_SPEED_2M;
	GPIO_INIT(GPIOB, &PIN1B);

	GPIO_PinConfig_t PIN13B;
	PIN13B.GPIO_PinNumber = GPIO_PIN13;
	PIN13B.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PIN13B.GPIO_OUTPUT_Speed = GPIO_SPEED_2M;
	GPIO_INIT(GPIOB, &PIN13B);

}

int main(void)
{
	clock_init();
	GPIO_init();
	while(1)
	{
		if (GPIO_READ_PIN(GPIOA, GPIO_PIN1)  == 0)
		{
			GPIO_TOGGLE_PIN(GPIOB, GPIO_PIN1);
			while(GPIO_READ_PIN(GPIOA, GPIO_PIN1)  == 0);
		}
		for(volatile int delay = 0; delay < 20000; delay++);
		if (GPIO_READ_PIN(GPIOA, GPIO_PIN13)  == 1)
		{
			GPIO_TOGGLE_PIN(GPIOB, GPIO_PIN13);
		}
		for(volatile int delay = 0; delay < 20000; delay++);
	}
}
