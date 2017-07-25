#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x4b"); 
  __asm volatile("LSR R9, R10, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
