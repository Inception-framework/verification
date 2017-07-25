#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x0d"); 
  __asm volatile("mov R8,#0x17"); 
  __asm volatile("LSR R1, R9, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
