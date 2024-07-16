#copyright : Abdelrhman marzoq
CC = arm-none-eabi-
CPU_NAME =-mcpu=cortex-m3
CFLAGS = -gdwarf-2  $(CPU_NAME)
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Poject_Name = learn_in_depth

Result: $(Poject_Name).bin
	echo "=============BUILD IS DONE=============";

Startup.o: Startup.s 
	$(CC)as.exe  $(CFLAGS) Startup.s  -o Startup.o

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Poject_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker.ld $(LIBS) $(OBJ) $(ASOBJ) -Map=myproject.map -o $(Poject_Name).elf
	cp $(Poject_Name).elf $(Poject_Name).axf

$(Poject_Name).bin : $(Poject_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.bin *.elf

clean_all:
	rm *.o *.elf *.bin