#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xd7"); 
  __asm volatile("LSL R6, R12, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
