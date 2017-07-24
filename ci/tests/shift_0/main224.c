#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xc9"); 
  __asm volatile("LSR R6, R8, 3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
