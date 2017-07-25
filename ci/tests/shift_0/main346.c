#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xaf"); 
  __asm volatile("LSR R8, R1, 1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
