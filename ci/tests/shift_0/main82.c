#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xf6"); 
  __asm volatile("LSR R1, R8, 31");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
