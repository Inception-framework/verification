#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xd5"); 
  __asm volatile("mov R11,#0x1e"); 
  __asm volatile("ROR R4, R8, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
