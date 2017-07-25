#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x6a"); 
  __asm volatile("ROR R6, R4, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
