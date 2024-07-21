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
	for(int i = 5; i < 8; i++) 	SET_BIT(DDRD,i);
	while (1)
	{
		for (int i = 5; i < 8; i++)
		{
			SET_BIT(PORTD,i);
			for(uint32_v i = 0; i < 24000; i++);
		}
		for(uint32_v i = 0; i < 24000; i++);		
		for (int i = 7; i >= 5; i--)
		{
			CLEAR_BIT(PORTD,i);
			for(uint32_v i = 0; i < 24000; i++);
		}
	}
}

