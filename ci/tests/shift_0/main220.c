#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x16"); 
  __asm volatile("mov R3,#0x18"); 
  __asm volatile("LSR R0, R8, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
