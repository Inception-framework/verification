#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x32"); 
  __asm volatile("LSR R0, R1, 12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
