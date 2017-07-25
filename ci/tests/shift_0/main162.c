#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x04"); 
  __asm volatile("LSR R6, R6, 27");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
