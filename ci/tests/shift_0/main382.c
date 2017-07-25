#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xca"); 
  __asm volatile("mov R3,#0x15"); 
  __asm volatile("ROR R6, R3, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
