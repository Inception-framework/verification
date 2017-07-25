#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xb4"); 
  __asm volatile("mov R2,#0x1e"); 
  __asm volatile("ROR R9, R10, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
