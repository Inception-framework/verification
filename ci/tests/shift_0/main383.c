#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x23"); 
  __asm volatile("ROR R7, R6, 27");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
