#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xf6"); 
  __asm volatile("ROR R7, R12, 18");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
