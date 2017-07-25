#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x4d"); 
  __asm volatile("LSR R0, R2, 18");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
