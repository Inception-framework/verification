#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xdc"); 
  __asm volatile("mov R10,#0x1b"); 
  __asm volatile("LSR R12, R7, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
