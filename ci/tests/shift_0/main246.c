#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x0c"); 
  __asm volatile("mov R12,#0x05"); 
  __asm volatile("ROR R5, R9, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
