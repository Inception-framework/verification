#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x99"); 
  __asm volatile("mov R6,#0x06"); 
  __asm volatile("LSL R6, R5, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
