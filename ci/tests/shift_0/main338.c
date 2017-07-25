#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x85"); 
  __asm volatile("LSR R4, R3, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
