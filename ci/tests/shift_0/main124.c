#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x33"); 
  __asm volatile("mov R7,#0x0a"); 
  __asm volatile("LSR R7, R0, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
