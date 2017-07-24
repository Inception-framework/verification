#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x0e"); 
  __asm volatile("mov R8,#0x03"); 
  __asm volatile("LSR R5, R4, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
