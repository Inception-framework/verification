#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x4a"); 
  __asm volatile("mov R11,#0x0f"); 
  __asm volatile("LSR R0, R1, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
