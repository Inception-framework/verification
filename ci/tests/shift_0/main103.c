#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x83"); 
  __asm volatile("ROR R8, R2, 20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
