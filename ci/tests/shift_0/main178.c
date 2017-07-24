#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x22"); 
  __asm volatile("mov R6,#0x13"); 
  __asm volatile("LSR R12, R2, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
