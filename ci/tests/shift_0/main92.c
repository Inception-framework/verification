#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x55"); 
  __asm volatile("mov R6,#0x0d"); 
  __asm volatile("LSR R9, R12, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
