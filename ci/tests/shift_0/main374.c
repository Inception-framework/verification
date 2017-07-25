#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x58"); 
  __asm volatile("mov R2,#0x01"); 
  __asm volatile("ROR R10, R6, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
