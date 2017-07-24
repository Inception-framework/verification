#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x90"); 
  __asm volatile("mov R3,#0x0f"); 
  __asm volatile("LSL R10, R11, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
