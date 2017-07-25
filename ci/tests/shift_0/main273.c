#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x01"); 
  __asm volatile("mov R8,#0x08"); 
  __asm volatile("LSL R6, R2, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
