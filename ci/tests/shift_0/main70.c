#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xa1"); 
  __asm volatile("mov R5,#0x1f"); 
  __asm volatile("ROR R10, R4, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
