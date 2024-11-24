/**
 ******************************************************************************
 * @File           : main.c
 * @Author         : Abdelrhman Marzoq
 * @Brief          : Main program body
 ******************************************************************************
**/

#include "../STM32F103C6_MCAL_Drivers/UART/STM32F103C6_UART_Driver.h"
#include "../STM32F103C6_MCAL_Drivers/GPIO/STM32F103C6_GPIO_Driver.h"
#include "../STM32F103C6_MCAL_Drivers/SPI/STM32F103C6_SPI_Driver.h"
#include "../STM32F103C6_MCAL_Drivers/I2C/STM32F103C6_I2C_Driver.h"
#include "../STM32F103C6_MCAL_Drivers/EXTI/EXTI.h"
#include "../HAL_Drivers/EEPROM/EEPROM.h"
#include "../HAL_Drivers/LCD/LCD.h"


void EXT_Callback(void);

EXIT_t ext;

int IRQ_FLAG = 0;


void init_Func()
{
	ext.Detect_EXTI = RISING;
	ext.EXTI_PIN 	= EXTI9PB9;
	ext.IRQ_EN 		= EN_EXTI;
	ext.PF_IRQ		= EXT_Callback;
	EXTI_Init(&ext);
}


static void myWait(volatile int ms)
{
	for (volatile int i = 0; i < ms; i++)
	{
		for (volatile int j = 0; j < 255; j++);
	}
}


int main(void)
{
	RCC_GPIOA_CLK_EN;
	RCC_GPIOB_CLK_EN;
	RCC_AFIO_CLK_EN;

	init_Func();


	while(1)
	{

	}
}


void EXT_Callback(void)
{
	IRQ_FLAG = 0;
}

