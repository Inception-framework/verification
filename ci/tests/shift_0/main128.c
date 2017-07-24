#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x60"); 
  __asm volatile("LSR R8, R12, 3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
