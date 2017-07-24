#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xf0"); 
  __asm volatile("LSR R5, R11, 11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
