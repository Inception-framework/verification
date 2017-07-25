#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x1b"); 
  __asm volatile("LSR R10, R8, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
