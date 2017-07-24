#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xea"); 
  __asm volatile("mov R10,#0x1c"); 
  __asm volatile("LSR R11, R10, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
