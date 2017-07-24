#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xe5"); 
  __asm volatile("LSL R12, R8, 5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
