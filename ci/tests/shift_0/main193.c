#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xf1"); 
  __asm volatile("mov R6,#0x00"); 
  __asm volatile("LSL R0, R5, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
