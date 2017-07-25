#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x24"); 
  __asm volatile("LSL R2, R8, 19");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
