#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xa4"); 
  __asm volatile("LSR R0, R9, 26");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
