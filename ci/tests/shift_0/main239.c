#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x19"); 
  __asm volatile("ROR R8, R6, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
