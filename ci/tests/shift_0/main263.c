#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x1d"); 
  __asm volatile("ROR R9, R8, 24");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
