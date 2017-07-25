#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xc7"); 
  __asm volatile("mov R11,#0x0f"); 
  __asm volatile("LSR R12, R7, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
