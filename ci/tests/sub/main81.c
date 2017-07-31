#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0xf8"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xf8"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xf0"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x71"); 
  __asm volatile("SUB R8, R9, #0xc6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
