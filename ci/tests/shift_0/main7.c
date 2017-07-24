#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xe2"); 
  __asm volatile("mov R8,#0x10"); 
  __asm volatile("LSL R8, R7, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
