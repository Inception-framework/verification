#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x67"); 
  __asm volatile("mov R1,#0x10"); 
  __asm volatile("ROR R8, R7, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
