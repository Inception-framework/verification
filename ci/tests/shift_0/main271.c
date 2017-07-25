#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xec"); 
  __asm volatile("ROR R6, R4, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
