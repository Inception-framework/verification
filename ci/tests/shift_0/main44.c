#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x80"); 
  __asm volatile("LSR R6, R10, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
