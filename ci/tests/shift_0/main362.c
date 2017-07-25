#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xcd"); 
  __asm volatile("LSR R0, R8, 17");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
