#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xdd"); 
  __asm volatile("ROR R12, R6, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
