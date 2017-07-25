#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x17"); 
  __asm volatile("mov R2,#0x02"); 
  __asm volatile("LSR R6, R10, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
