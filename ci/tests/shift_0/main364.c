#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x32"); 
  __asm volatile("mov R7,#0x03"); 
  __asm volatile("LSR R5, R5, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
