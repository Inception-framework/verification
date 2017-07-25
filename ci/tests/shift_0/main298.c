#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xdc"); 
  __asm volatile("LSR R12, R6, 11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
