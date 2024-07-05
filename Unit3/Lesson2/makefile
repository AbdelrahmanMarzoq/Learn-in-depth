#copyright : Abdelrhman marzoq
CC = arm-none-eabi-
CPU_NAME =-mcpu=arm926ej-s
CFLAGS = -g $(CPU_NAME)
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Poject_Name = learn-in-depth

Result: $(Poject_Name).bin
	@echo "=============Build is Done============="

%.o: %.s 
	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Poject_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_scribt.ld $(LIBS) $(OBJ) $(ASOBJ) -o $(Poject_Name).elf

$(Poject_Name).bin : $(Poject_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.bin *.elf

clean_all:
	rm *.o *.elf *.bin