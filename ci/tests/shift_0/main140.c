#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xb0"); 
  __asm volatile("LSR R11, R0, 23");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
