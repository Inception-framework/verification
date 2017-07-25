#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x29"); 
  __asm volatile("LSR R6, R10, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
