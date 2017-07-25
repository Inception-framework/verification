#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xa2"); 
  __asm volatile("mov R7,#0x15"); 
  __asm volatile("ROR R11, R8, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
