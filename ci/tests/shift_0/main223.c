#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xf6"); 
  __asm volatile("ROR R6, R4, 12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
