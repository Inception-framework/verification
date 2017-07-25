#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x7b"); 
  __asm volatile("mov R1,#0x0a"); 
  __asm volatile("LSR R1, R1, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
