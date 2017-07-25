#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x52"); 
  __asm volatile("mov R2,#0x0b"); 
  __asm volatile("ROR R9, R7, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
