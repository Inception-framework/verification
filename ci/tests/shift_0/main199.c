#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xc7"); 
  __asm volatile("mov R6,#0x1f"); 
  __asm volatile("LSL R5, R12, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
