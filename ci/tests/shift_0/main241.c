#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x27"); 
  __asm volatile("mov R2,#0x0d"); 
  __asm volatile("LSL R2, R8, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
