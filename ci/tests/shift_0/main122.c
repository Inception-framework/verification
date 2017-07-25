#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x4d"); 
  __asm volatile("LSR R10, R11, 23");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
