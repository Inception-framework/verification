#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xf2"); 
  __asm volatile("ROR R0, R6, 30");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
