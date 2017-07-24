#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x84"); 
  __asm volatile("LSR R5, R11, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
