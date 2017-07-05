# Giovanni Camurati, Nassim Corteggiani

GCC_ARGS=-march=armv7-m -mthumb -mcpu=cortex-m3 -Wa,-mimplicit-it=thumb
# GCC_ARGS='-march=armv7-a -marm'

main.bin: main.elf
	arm-none-eabi-objcopy -O binary main.elf main.bin
main.elf: link.ld main.o
	arm-none-eabi-ld -T link.ld main.o -o main.elf
main.o: main.c
	arm-none-eabi-gcc ${GCC_ARGS} -g -c main.c -o main.o

clean:
	rm *.elf
	rm *.o
