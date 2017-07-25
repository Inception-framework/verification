#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x8f"); 
  __asm volatile("ROR R0, R8, 5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
