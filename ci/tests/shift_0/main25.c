#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x3b"); 
  __asm volatile("mov R7,#0x15"); 
  __asm volatile("LSL R1, R5, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
