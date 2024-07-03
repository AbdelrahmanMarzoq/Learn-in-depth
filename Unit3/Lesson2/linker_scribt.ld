ENTRY (reset)

MEMORY
{
	MEM (rwx): ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS
{

	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}>MEM
	.text :
	{
		*(.text)
	}>MEM
	.data :
	{
		*(.data)
	}>MEM
	.bss :
	{
		*(.bss)
	}>MEM
	.rodata :
	{
		*(.rodata)
	}>MEM
	. = . + 0x1000;
	Stack_Point = .;
}