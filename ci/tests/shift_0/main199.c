#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x56"); 
  __asm volatile("ROR R5, R6, 11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
