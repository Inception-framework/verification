#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xb1"); 
  __asm volatile("mov R3,#0x0d"); 
  __asm volatile("ROR R1, R11, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
