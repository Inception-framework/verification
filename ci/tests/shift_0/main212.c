#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xf3"); 
  __asm volatile("mov R3,#0x16"); 
  __asm volatile("LSR R7, R4, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
