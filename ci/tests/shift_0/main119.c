#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x7a"); 
  __asm volatile("ROR R10, R2, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
