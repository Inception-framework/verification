#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xc0"); 
  __asm volatile("LSL R12, R11, 1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
