#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x8a"); 
  __asm volatile("ROR R0, R1, 29");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
