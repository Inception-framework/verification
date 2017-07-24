#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xab"); 
  __asm volatile("mov R11,#0x03"); 
  __asm volatile("LSR R11, R1, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
