#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xe0"); 
  __asm volatile("mov R0,#0x1b"); 
  __asm volatile("LSR R7, R7, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
