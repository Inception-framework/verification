#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xae"); 
  __asm volatile("mov R6,#0x11"); 
  __asm volatile("LSR R12, R8, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
