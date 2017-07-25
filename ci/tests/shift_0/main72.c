#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xde"); 
  __asm volatile("LSL R10, R7, 23");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
