#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xdd"); 
  __asm volatile("LSR R5, R3, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
