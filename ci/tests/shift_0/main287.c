#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x86"); 
  __asm volatile("ROR R8, R9, 30");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
