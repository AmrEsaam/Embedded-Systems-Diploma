#copyrights: Amr Zidan

CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -mcpu=arm926ej-s
INCS= -I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
ASS=$(wildcard *.s)
ASSOBJ=$(ASS:.s=.o)
PROJECT_NAME=learn-in-depth

all: $(PROJECT_NAME).bin
	@echo "-----Build is done-----"
	
startup.o: startup.s
	$(CC)as.exe --gdwarf-2 -mcpu=arm926ej-s $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASSOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(ASSOBJ) $(LIBS) -o $@ -Map=Map_file.map

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin

clean: 
	rm *.elf *.bin




