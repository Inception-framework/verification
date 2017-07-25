#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x33"); 
  __asm volatile("mov R11,#0x0d"); 
  __asm volatile("ROR R0, R9, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
