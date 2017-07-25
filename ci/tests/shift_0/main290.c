#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x8b"); 
  __asm volatile("LSR R0, R0, 3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
