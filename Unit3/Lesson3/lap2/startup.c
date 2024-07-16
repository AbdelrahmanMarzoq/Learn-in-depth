extern unsigned int STACK_TOP;
extern unsigned int END_TEXT;
extern unsigned int START_DATA;
extern unsigned int END_DATA;
extern unsigned int START_BSS;
extern unsigned int END_BSS;


extern int main();

void RESET_HANDLER();

void NMI_HANDLER() __attribute__((weak, alias("Default_Handler")));
void H_FAULT_HANDLER() __attribute__((weak, alias("Default_Handler")));
void MM_FAULT_HANDLER() __attribute__((weak, alias("Default_Handler")));
void BUS_FAULT_HANDLER() __attribute__((weak, alias("Default_Handler")));
void USAGE_FAULT_HANDLER() __attribute__((weak, alias("Default_Handler")));


void Default_Handler(void)
{
	RESET_HANDLER();
}

void RESET_HANDLER(){
	

	// cpy data section from flash to sram
	unsigned int DATA_SIZE  = (unsigned char *)&END_DATA - (unsigned char *)&START_DATA;
	unsigned char *data_src = (unsigned char *)&END_TEXT;
	unsigned char *data_dst = (unsigned char *)&START_DATA;                     //SRAM 
	for (int i = 0; i < DATA_SIZE; i++)
	{
		*((unsigned char *)data_dst++) = *((unsigned char *)data_src++);
	}


	unsigned int BSS_SIZE  = (unsigned char *)&END_BSS - (unsigned char *)&START_BSS;
	unsigned char *bss_dst = (unsigned char *)&END_DATA;
	for (int i = 0; i < BSS_SIZE; i++)
	{
		*((unsigned char *)bss_dst++) = (unsigned char)10;
	}

	// jump to main()
	main();

}


unsigned int vectors[] __attribute__((section(".vectors"))) = {
	(unsigned int)&STACK_TOP,
	(unsigned int)&RESET_HANDLER,    
	(unsigned int)&NMI_HANDLER,
	(unsigned int)&H_FAULT_HANDLER,
	(unsigned int)&MM_FAULT_HANDLER,
	(unsigned int)&BUS_FAULT_HANDLER,
	(unsigned int)&USAGE_FAULT_HANDLER
};

