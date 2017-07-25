#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x94"); 
  __asm volatile("mov R4,#0x11"); 
  __asm volatile("ROR R1, R6, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
