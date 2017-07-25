#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x18"); 
  __asm volatile("LSR R11, R7, 27");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
