#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x7f"); 
  __asm volatile("mov R5,#0x1d"); 
  __asm volatile("LSR R11, R11, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
