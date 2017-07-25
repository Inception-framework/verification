#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x91"); 
  __asm volatile("LSR R4, R4, 1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
