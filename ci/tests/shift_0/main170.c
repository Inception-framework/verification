#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xcf"); 
  __asm volatile("LSR R12, R3, 18");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
