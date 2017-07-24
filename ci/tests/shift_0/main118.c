#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x29"); 
  __asm volatile("mov R10,#0x0a"); 
  __asm volatile("LSR R9, R11, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
