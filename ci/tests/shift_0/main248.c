#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xf6"); 
  __asm volatile("LSR R10, R7, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}