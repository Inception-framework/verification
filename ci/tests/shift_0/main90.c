#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xb7"); 
  __asm volatile("LSL R6, R3, 7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
