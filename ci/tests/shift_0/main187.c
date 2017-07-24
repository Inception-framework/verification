#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x1e"); 
  __asm volatile("mov R7,#0x13"); 
  __asm volatile("LSL R7, R10, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
