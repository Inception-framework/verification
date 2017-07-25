#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x4b"); 
  __asm volatile("mov R2,#0x0e"); 
  __asm volatile("LSL R2, R6, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
