#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x94"); 
  __asm volatile("mov R7,#0x1f"); 
  __asm volatile("LSL R8, R8, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
