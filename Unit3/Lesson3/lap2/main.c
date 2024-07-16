
/**
 * Eng  : Abdelrhman marzoq
 * Lab2 : Write startup and linkeer and makefile code and write to toggle led  
 * */




#define RCC_BASE 		0x40021000
#define GPIOA_BASE 		0x40010800


#define GBIOA_CRH 		*(volatile unsigned long*)(GPIOA_BASE + 0x04)
#define GBIOA_ODR		*(volatile unsigned long*)(GPIOA_BASE + 0x0c)


//for clock
#define RCC_AP2ENR 		*(volatile unsigned long*)(RCC_BASE + 0x18)
#define RCC_IOPAEN		(1 << 2)


int main()
{
	RCC_AP2ENR |=RCC_IOPAEN;  //Set PORTA clock enabled

	GBIOA_CRH &= 0xFF0FFFFF;   
	GBIOA_CRH |= 0x00100000;   

	while (1)
	{

		GBIOA_ODR |= (1<<13);
		for (int i = 0; i < 20000; i++);
		GBIOA_ODR ^= (1<<13);	
		for (int i = 0; i < 20000; i++);

	}
	
	return 0;
}