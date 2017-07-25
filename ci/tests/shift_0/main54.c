#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xd6"); 
  __asm volatile("mov R12,#0x16"); 
  __asm volatile("ROR R0, R6, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
