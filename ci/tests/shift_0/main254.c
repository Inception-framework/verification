#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x9c"); 
  __asm volatile("LSR R10, R2, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
