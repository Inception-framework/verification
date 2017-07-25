#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xe4"); 
  __asm volatile("mov R6,#0x06"); 
  __asm volatile("ROR R12, R11, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
