#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x8c"); 
  __asm volatile("mov R6,#0x0a"); 
  __asm volatile("LSR R6, R2, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
