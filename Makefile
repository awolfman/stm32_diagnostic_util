CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -O0 -g3 -nostdlib
LDFLAGS = -T linker_sram.ld

all: diag_sram.elf

diag_sram.elf: main.c linker_sram.ld
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -o diag_sram.elf

clean:
	rm -f *.elf
