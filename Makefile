# Giovanni Camurati, Nassim Corteggiani

GCC_ARGS=-march=armv7-m -mthumb -mcpu=cortex-m3 -Wa,-mimplicit-it=thumb
# GCC_ARGS='-march=armv7-a -marm'

main/main${ID}.bin: main/main${ID}.elf
	arm-none-eabi-objcopy -O binary main/main${ID}.elf main/main${ID}.bin
main/main${ID}.elf: link.ld main/main${ID}.o
	arm-none-eabi-ld -T link.ld main/main${ID}.o -o main/main${ID}.elf
main/main${ID}.o: main/main${ID}.c
	arm-none-eabi-gcc ${GCC_ARGS} -g -c main/main${ID}.c -o main/main${ID}.o

clean:
	rm main/*${ID}.elf
	rm main/*${ID}.o
