#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x67"); 
  __asm volatile("LSR R12, R10, 8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
