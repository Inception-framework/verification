#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x5a"); 
  __asm volatile("ROR R5, R0, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
