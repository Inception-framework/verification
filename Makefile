# Giovanni Camurati, Nassim Corteggiani

GCC_ARGS=-march=armv7-m -mthumb -mcpu=cortex-m3 -Wa,-mimplicit-it=thumb
# GCC_ARGS='-march=armv7-a -marm'

${FOLDER}/main${ID}.bin: ${FOLDER}/main${ID}.elf
	arm-none-eabi-objcopy -O binary ${FOLDER}/main${ID}.elf ${FOLDER}/main${ID}.bin
${FOLDER}/main${ID}.elf: link.ld ${FOLDER}/main${ID}.o
	arm-none-eabi-ld -T link.ld ${FOLDER}/main${ID}.o -o ${FOLDER}/main${ID}.elf
${FOLDER}/main${ID}.o: ${FOLDER}/main${ID}.c
	arm-none-eabi-gcc ${GCC_ARGS} -g -c ${FOLDER}/main${ID}.c -o ${FOLDER}/main${ID}.o

clean:
	rm ${FOLDER}/*${ID}.elf
	rm ${FOLDER}/*${ID}.o
