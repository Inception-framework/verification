#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x14"); 
  __asm volatile("ROR R9, R9, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
