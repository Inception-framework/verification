#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xe9"); 
  __asm volatile("mov R5,#0x05"); 
  __asm volatile("LSR R12, R3, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
