#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x8a"); 
  __asm volatile("mov R10,#0x13"); 
  __asm volatile("LSR R9, R0, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
