#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x50"); 
  __asm volatile("mov R8,#0x17"); 
  __asm volatile("ROR R6, R5, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
