#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xaa"); 
  __asm volatile("LSR R6, R6, 16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
