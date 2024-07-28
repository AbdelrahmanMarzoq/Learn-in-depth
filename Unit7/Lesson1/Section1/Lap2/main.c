/*
 * Diploma.c
 *
 * @Created : 7/20/2024 2:42:05 AM
 * @Author  : Eng / Abdelrhman Marzoq
 * @Brief   : Led ON 1 -> 8 and OFF 8 -> 1
 */ 
#include "Atmega32.h"

typedef volatile unsigned long uint32_v;
	
#define SET_BIT(REG, BIT)    (REG |= (1<<BIT))
#define CLEAR_BIT(REG, BIT)  (REG &= ~(1<<BIT))
#define READ_BIT(REG, BIT)   ((REG>>BIT)&1)
#define TOGGLE_BIT(REG, BIT) (REG ^= (1<<BIT))




int main()
{
	int cnt = 0;
	for(int i = 0; i < 3; i++) 	SET_BIT(DDRA,i);
	CLEAR_BIT(DDRC, 0);
	CLEAR_BIT(PORTC,0);
	
	while (1)
	{
		if ( ((PINC & 1) == 0) )
		{
			cnt++;
			if (cnt == 1) SET_BIT(PORTA,0);
			else if (cnt == 2) SET_BIT(PORTA,1);
			else if (cnt == 3) SET_BIT(PORTA,2);
			else if (cnt == 4) CLEAR_BIT(PORTA,2);
			else if (cnt == 5) CLEAR_BIT(PORTA,1);
			else if (cnt == 6)
			{
				 CLEAR_BIT(PORTA,0);
				cnt = 0;
			}
			while( ((PINC & 1) == 0) );
		}
	}
}

