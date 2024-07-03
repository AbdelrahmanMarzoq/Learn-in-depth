#include "Uart.h"

unsigned char myname[] = "Learn-In-Depth : Abdelrhman";

unsigned char const myName[] = "Learn-In-Depth : Abdelrhman";

void main(void)
{
	Uart_Send_String(myname);		
}