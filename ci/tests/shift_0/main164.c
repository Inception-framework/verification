#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xae"); 
  __asm volatile("LSR R3, R7, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
