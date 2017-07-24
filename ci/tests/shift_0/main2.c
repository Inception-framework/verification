#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x6f"); 
  __asm volatile("LSR R7, R5, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
