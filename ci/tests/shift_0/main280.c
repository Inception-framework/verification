#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x11"); 
  __asm volatile("mov R4,#0x13"); 
  __asm volatile("LSR R4, R11, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
