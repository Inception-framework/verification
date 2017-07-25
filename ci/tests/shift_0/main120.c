#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x1c"); 
  __asm volatile("LSL R11, R5, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
