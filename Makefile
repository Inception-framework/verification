# Giovanni Camurati, Nassim Corteggiani

GCC_ARGS=-march=armv7-m -mthumb -mcpu=cortex-m3 -Wa,-mimplicit-it=thumb
# GCC_ARGS='-march=armv7-a -marm'

main/main.bin: main/main.elf
	arm-none-eabi-objcopy -O binary main/main.elf main/main.bin
main/main.elf: link.ld main/main.o
	arm-none-eabi-ld -T link.ld main/main.o -o main/main.elf
main/main.o: main/main.c
	arm-none-eabi-gcc ${GCC_ARGS} -g -c main/main.c -o main/main.o

clean:
	rm main/*.elf
	rm main/*.o
