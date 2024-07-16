
MEMORY
{
	flash (RX) : ORIGIN = 0x08000000, LENGTH = 128k
	sram (RWX) : ORIGIN = 0x20000000, LENGTH = 20k
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
	
	.bss : 
	{
		START_BSS = .;
		*(.bss)
		. = ALIGN(4);
		END_BSS = .;
		. = . + 0x1000;
		STACK_TOP = .;
	} > sram
}
