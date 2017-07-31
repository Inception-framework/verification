#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0xfe"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xef"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x71"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xcb"); 
  __asm volatile("SUB R6, R12, #0x13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
