#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xfe"); 
  __asm volatile("LSR R10, R5, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
