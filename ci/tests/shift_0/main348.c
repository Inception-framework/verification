#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xe7"); 
  __asm volatile("mov R5,#0x19"); 
  __asm volatile("LSR R9, R5, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
