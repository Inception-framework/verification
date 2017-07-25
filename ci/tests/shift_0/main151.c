#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xa7"); 
  __asm volatile("ROR R4, R4, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
