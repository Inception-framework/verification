#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xab"); 
  __asm volatile("mov R7,#0x1f"); 
  __asm volatile("ROR R3, R5, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
