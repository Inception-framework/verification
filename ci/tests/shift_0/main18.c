#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x60"); 
  __asm volatile("LSR R4, R2, 12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
