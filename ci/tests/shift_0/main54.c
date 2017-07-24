#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xd6"); 
  __asm volatile("LSL R11, R9, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
