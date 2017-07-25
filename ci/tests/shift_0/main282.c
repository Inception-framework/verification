#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x4d"); 
  __asm volatile("LSR R4, R10, 30");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
