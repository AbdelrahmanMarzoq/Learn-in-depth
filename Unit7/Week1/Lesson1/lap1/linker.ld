
MEMORY
{
	flash (RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram (RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{

	.text :
	{
		*(.vectors*)
		*(.text*)
		. = ALIGN(4);    
		END_TEXT = .;
	} > flash

	.data : 
	{
		START_DATA = .;
		*(.data)
		. = ALIGN(4);
		END_DATA = .;
	} > sram AT > flash 
	

	.rodata :
	{
		*(.rodata)
	}

	.bss : 
	{
		START_BSS = .;
		*(.bss)
		. = ALIGN(4);
		END_BSS = .;
		. = ALIGN(4);
		. = . + 0x1000;
		STACK_TOP = .;
	} > sram
}
