#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x4b"); 
  __asm volatile("mov R8,#0x14"); 
  __asm volatile("LSL R7, R11, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
