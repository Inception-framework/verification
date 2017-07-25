#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x27"); 
  __asm volatile("ROR R10, R12, 24");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
