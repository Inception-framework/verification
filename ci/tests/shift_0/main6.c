#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xa1"); 
  __asm volatile("mov R9,#0x15"); 
  __asm volatile("ROR R5, R6, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
