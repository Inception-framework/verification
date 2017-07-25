#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x44"); 
  __asm volatile("mov R7,#0x17"); 
  __asm volatile("ROR R2, R2, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
