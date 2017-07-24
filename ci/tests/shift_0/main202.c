#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x2b"); 
  __asm volatile("mov R2,#0x18"); 
  __asm volatile("LSR R0, R3, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
