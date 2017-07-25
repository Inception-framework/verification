#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x0d"); 
  __asm volatile("mov R12,#0x1b"); 
  __asm volatile("LSR R11, R6, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
