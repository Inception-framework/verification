#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0x41"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x24"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x40"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x5b"); 
  __asm volatile("SUB R8, R9, #0x219");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
