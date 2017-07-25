#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x95"); 
  __asm volatile("LSR R5, R12, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
