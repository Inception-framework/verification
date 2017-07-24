#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xa9"); 
  __asm volatile("LSR R2, R2, 1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
