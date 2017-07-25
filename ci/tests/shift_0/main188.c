#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x99"); 
  __asm volatile("mov R5,#0x1f"); 
  __asm volatile("LSR R8, R10, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
