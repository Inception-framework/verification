#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xd1"); 
  __asm volatile("mov R4,#0x1e"); 
  __asm volatile("LSR R6, R0, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
