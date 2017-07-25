#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xde"); 
  __asm volatile("mov R7,#0x17"); 
  __asm volatile("ROR R3, R1, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
