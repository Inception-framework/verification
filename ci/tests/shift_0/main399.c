#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xb6"); 
  __asm volatile("ROR R1, R9, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
