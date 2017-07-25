#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x6e"); 
  __asm volatile("ROR R9, R9, 8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
