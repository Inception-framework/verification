#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x04"); 
  __asm volatile("mov R11,#0x1e"); 
  __asm volatile("LSL R2, R5, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
