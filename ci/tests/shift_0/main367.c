#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x59"); 
  __asm volatile("ROR R2, R2, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
