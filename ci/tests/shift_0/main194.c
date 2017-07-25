#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x29"); 
  __asm volatile("LSR R8, R1, 26");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
