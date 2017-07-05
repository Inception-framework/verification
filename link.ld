OUTPUT_FORMAT("elf32-littlearm")

OUTPUT_ARCH(arm)

SECTIONS
{
 .code 0x10000000:
 {
 *(.text .text.*);
 }

 .data 0x20000000:
 {
 *(.rodata .rodata.*);
 *(.data .data.*);
 *(.bss .bss.*);
 }

 __cs3_stack = 0x20001000;
}
