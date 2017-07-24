#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x86"); 
  __asm volatile("mov R10,#0x02"); 
  __asm volatile("LSL R12, R8, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
