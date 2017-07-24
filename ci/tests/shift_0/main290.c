#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x83"); 
  __asm volatile("LSR R10, R10, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
