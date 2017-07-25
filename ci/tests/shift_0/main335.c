#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x17"); 
  __asm volatile("ROR R10, R11, 24");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
