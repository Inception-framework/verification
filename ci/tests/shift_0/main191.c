#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x99"); 
  __asm volatile("ROR R0, R7, 5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
