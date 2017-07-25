#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xca"); 
  __asm volatile("ROR R6, R10, 31");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
