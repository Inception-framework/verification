#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xa2"); 
  __asm volatile("mov R5,#0x0d"); 
  __asm volatile("LSR R8, R8, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
