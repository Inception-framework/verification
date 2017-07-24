#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xaa"); 
  __asm volatile("mov R5,#0x17"); 
  __asm volatile("LSL R2, R4, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
