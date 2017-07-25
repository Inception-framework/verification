#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x80"); 
  __asm volatile("LSR R7, R0, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
