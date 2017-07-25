#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x00"); 
  __asm volatile("mov R0,#0x1f"); 
  __asm volatile("LSL R8, R7, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
