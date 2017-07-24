#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xc5"); 
  __asm volatile("mov R5,#0x10"); 
  __asm volatile("LSR R1, R9, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
