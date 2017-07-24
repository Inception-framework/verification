#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xf0"); 
  __asm volatile("LSL R8, R4, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
