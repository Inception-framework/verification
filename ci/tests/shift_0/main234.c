#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xe2"); 
  __asm volatile("LSR R11, R4, 30");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
