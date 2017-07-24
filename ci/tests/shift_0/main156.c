#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xd8"); 
  __asm volatile("LSL R11, R2, 19");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
