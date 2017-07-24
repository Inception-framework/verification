#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xd7"); 
  __asm volatile("mov R6,#0x0b"); 
  __asm volatile("LSL R6, R2, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
