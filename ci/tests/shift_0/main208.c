#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x16"); 
  __asm volatile("mov R0,#0x0b"); 
  __asm volatile("LSR R4, R0, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
