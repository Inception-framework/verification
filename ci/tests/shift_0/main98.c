#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xa5"); 
  __asm volatile("LSR R8, R7, 32");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
