#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xad"); 
  __asm volatile("LSR R11, R1, 3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
