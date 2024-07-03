#include "Uart.h"

#define UART0DR  *((volatile unsigned int *const)((unsigned int*)0x101f1000))


void Uart_Send_String(unsigned char *myString)
{
	while(*myString != '\0')
	{
		UART0DR = (unsigned int)(*myString);
		myString++;
	}
}




