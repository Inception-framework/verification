#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x04"); 
  __asm volatile("LSR R0, R6, 7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
