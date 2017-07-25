#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x7c"); 
  __asm volatile("LSR R5, R8, 16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
