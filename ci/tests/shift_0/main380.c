#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xd0"); 
  __asm volatile("mov R9,#0x17"); 
  __asm volatile("LSR R1, R2, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
