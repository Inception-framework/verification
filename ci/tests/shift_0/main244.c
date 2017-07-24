#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xb4"); 
  __asm volatile("mov R9,#0x09"); 
  __asm volatile("LSR R12, R6, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
