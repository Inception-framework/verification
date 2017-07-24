#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xea"); 
  __asm volatile("mov R11,#0x0a"); 
  __asm volatile("LSR R9, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
