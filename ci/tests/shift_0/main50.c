#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xd4"); 
  __asm volatile("LSR R6, R11, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
