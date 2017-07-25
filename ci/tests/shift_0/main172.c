#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x9a"); 
  __asm volatile("mov R8,#0x0a"); 
  __asm volatile("LSR R12, R10, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
