OUTPUT_FORMAT("elf32-littlearm")

OUTPUT_ARCH(arm)

ENTRY(Reset_Handler)

MEMORY {
  VECTORS (rx): ORIGIN = 0x10000100, LENGTH = 0x00000100
  FLASH (rx)  : ORIGIN = 0x10000000, LENGTH = 64k
  RAM  (rwx)  : ORIGIN = 0x20000000, LENGTH = 64k
}

STACK_SIZE = 8200;

SECTIONS
{
  .interrupt_vector :
  {
    KEEP(*(.cs3.interrupt_vector));
  } > RAM

 .code :
 {
   CREATE_OBJECT_SYMBOLS
   *(.text .text.*);
 } > FLASH

 .data :
 {
   *(.rodata .rodata.*);
   *(.data .data.*);
   *(.bss .bss.*);
 } > RAM AT>FLASH

 .bss : {
    *(.bss .bss.*)
    *(COMMON)
    . = ALIGN(4);
 } > FLASH

 .stack : {
  _stack_start_ = .;
  KEEP(*(STACK))
  . += STACK_SIZE;
  . = ALIGN (4);
  _stack_end_ = .;
 } > RAM

STACK = _stack_start_;
}

