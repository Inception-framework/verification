#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xb7"); 
  __asm volatile("LSL R1, R11, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
