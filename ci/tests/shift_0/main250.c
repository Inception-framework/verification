#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x61"); 
  __asm volatile("mov R5,#0x13"); 
  __asm volatile("LSR R9, R6, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
