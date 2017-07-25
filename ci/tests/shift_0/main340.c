#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x4f"); 
  __asm volatile("mov R12,#0x1d"); 
  __asm volatile("LSR R8, R7, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
