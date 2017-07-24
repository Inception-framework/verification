#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xa6"); 
  __asm volatile("mov R11,#0x05"); 
  __asm volatile("LSR R5, R3, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
