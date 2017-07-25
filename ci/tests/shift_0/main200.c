#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xde"); 
  __asm volatile("LSL R6, R10, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
