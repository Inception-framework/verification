#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xfa"); 
  __asm volatile("mov R1,#0x0a"); 
  __asm volatile("ROR R5, R8, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
