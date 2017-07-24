#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x1b"); 
  __asm volatile("mov R10,#0x1b"); 
  __asm volatile("LSL R6, R7, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
