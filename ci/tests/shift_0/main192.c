#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x1a"); 
  __asm volatile("LSL R11, R7, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
