#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x07"); 
  __asm volatile("LSR R0, R12, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
