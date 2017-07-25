#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x48"); 
  __asm volatile("mov R7,#0x05"); 
  __asm volatile("LSL R7, R6, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
