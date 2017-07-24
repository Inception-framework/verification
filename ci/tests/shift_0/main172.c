#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x00"); 
  __asm volatile("mov R4,#0x1a"); 
  __asm volatile("LSR R10, R0, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
