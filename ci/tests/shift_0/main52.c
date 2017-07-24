#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x72"); 
  __asm volatile("mov R10,#0x1d"); 
  __asm volatile("LSR R2, R3, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
