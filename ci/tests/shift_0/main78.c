#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x96"); 
  __asm volatile("mov R1,#0x10"); 
  __asm volatile("ROR R8, R2, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
