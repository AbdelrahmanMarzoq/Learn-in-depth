/**
 * Eng  : Abdelrhman Marzoq
 * lab3 : write baremetal app to Toggle Led on Tiva C 
 * */


#define SYSCTL_RCGC2_R    (*((volatile unsigned long *)((unsigned long *)0x400FE108)))
#define GPIO_PORTF_DIR_R  (*((volatile unsigned long *)((unsigned long *)0x40025400)))
#define GPIO_PORTF_DEN_R  (*((volatile unsigned long *)((unsigned long *)0x400251C)))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long *)((unsigned long *)0x400253FC)))


int main()
{
	//enable port to enable port f write 20
	SYSCTL_RCGC2_R = 0x20;
	//delay to make sure GPIO ON
	for (volatile int delay = 0; delay < 2000; delay++);
	// Direction is OUTPUT
	GPIO_PORTF_DIR_R |= 1<<3;
	//enable PIN 
	GPIO_PORTF_DEN_R |= 1<<3;
	while (1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for (volatile int delay = 0; delay < 200000; delay++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for (volatile int delay = 0; delay < 200000; delay++);
	}
}

