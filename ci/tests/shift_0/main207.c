#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x1d"); 
  __asm volatile("ROR R2, R5, 24");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
