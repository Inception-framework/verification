#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x35"); 
  __asm volatile("LSR R8, R2, 32");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
