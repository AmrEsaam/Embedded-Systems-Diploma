#copyrights: Amr Zidan

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -gdwarf-2
INCS= -I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
ASS=$(wildcard *.s)
ASSOBJ=$(ASS:.s=.o)
PROJECT_NAME=tiva_c

all: $(PROJECT_NAME).bin
	@echo "-----Build is done-----"
	
#startup.o: startup.s
#	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASSOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(ASSOBJ) $(LIBS) -o $@ -Map=Map_file.map
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf


$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin *.afx

clean: 
	rm *.elf *.bin *.afx




