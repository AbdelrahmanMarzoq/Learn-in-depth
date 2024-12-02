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


#define STACK_ALLIGN		0x8
#define STACK_SIZE_TASKB	0x100
#define STACK_SIZE_TASKA	0x100
#define MAIN_STACK_SIZE		0x500


#define OS_SET_PSP(add) 		__asm("mov r0, %0 \n\t msr PSP,r0" : : "r" (add))
#define OS_SP_TO_PSP			__asm("mrs r0, CONTROL \n\t ORR r0,r0,#0x02 \n\t msr CONTROL, r0")
#define OS_SP_TO_MSP			__asm("mrs r0, CONTROL \n\t AND r0,r0,#0x05 \n\t msr CONTROL, r0")

#define OS_GENERATE_EXCEPTION	__asm("SVC #0x3")

#define SWITCH_CPU_TO_PRIV		__asm("mrs r0, CONTROL \n\t LSR r0, r0,#1 \n\t LSL r0, r0,#1  \n\t msr CONTROL, r0")
#define SWITCH_CPU_TO_UNPRIV	__asm("mrs r0, CONTROL \n\t ORR r0, r0, #0x1 \n\t msr CONTROL, r0")



extern _estack;


unsigned int S_MSP   =		(unsigned int)&_estack;

unsigned int E_MSP;
unsigned int S_TASKA;
unsigned int E_TASKA;
unsigned int S_TASKB;
unsigned int E_TASKB;



EXIT_t ext;
unsigned char FLAG_A = 0;
unsigned char FLAG_B = 0;
int IRQ_FLAG = 0;

void EXT_Callback(void);


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

void SVC_Handler()
{
	SWITCH_CPU_TO_PRIV;
}

unsigned int TASKA(int a, int b, int c)
{
	return a+b+c;
}

unsigned int TASKB(int a, int b, int c, int d)
{
	return a+b+c+d;
}

void MainOS()
{
	E_MSP	 =		(S_MSP - MAIN_STACK_SIZE);


	S_TASKA =		(E_MSP   - STACK_ALLIGN);
	E_TASKA =		(S_TASKA - STACK_SIZE_TASKA);


	S_TASKB =		(E_TASKA - STACK_ALLIGN);
	E_TASKB = 		(S_TASKB - STACK_SIZE_TASKB);

}

int main(void)
{
	RCC_GPIOA_CLK_EN;
	RCC_GPIOB_CLK_EN;
	RCC_AFIO_CLK_EN;

	init_Func();

	MainOS();

	unsigned int res = 0;

	while(1)
	{
		if (FLAG_A)
		{
			FLAG_A = 0;
			// SP Shadow To PSP
			OS_SP_TO_PSP;
			// SP Have Address of TASK A
			OS_SET_PSP(S_TASKA);
			// Switch to UnPrivillage Mode
			SWITCH_CPU_TO_UNPRIV;


			// Execute Task A
			res = TASKA(1,2,3);

			// Generate IRQ To be in Handle Mode
			OS_GENERATE_EXCEPTION;

			// SP Shadow To MSP
			OS_SP_TO_MSP;

		}
		else if (FLAG_B)
		{
			FLAG_B = 0;
			// SP Shadow To PSP
			OS_SP_TO_PSP;
			// SP Have Address of TASK A
			OS_SET_PSP(S_TASKB);
			// Switch to UnPrivillage Mode
			SWITCH_CPU_TO_UNPRIV;


			// Execute Task B
			res = TASKB(1,2,3,4);

			// Generate IRQ To be in Handle Mode
			OS_GENERATE_EXCEPTION;

			// SP Shadow To MSP
			OS_SP_TO_MSP;
		}
	}
}

void EXT_Callback(void)
{
	if (IRQ_FLAG == 1)
	{
		IRQ_FLAG = 0;
		FLAG_A = 1;
	}
	else if (IRQ_FLAG == 0)
	{
		IRQ_FLAG = 1;
		FLAG_B = 1;
	}

}

