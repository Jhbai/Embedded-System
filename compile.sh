arm-none-eabi-gcc -nostdlib -ffreestanding -O2 -Wl,-Ttext=0x10000 -o output.elf main.c
arm-none-eabi-objcopy -O binary output.elf output.bin
