#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x5e"); 
  __asm volatile("LSR R3, R12, 19");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
