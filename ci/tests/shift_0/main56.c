#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xf9"); 
  __asm volatile("LSR R7, R8, 1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
