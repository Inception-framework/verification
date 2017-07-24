#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xb8"); 
  __asm volatile("mov R6,#0x09"); 
  __asm volatile("LSR R9, R4, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
