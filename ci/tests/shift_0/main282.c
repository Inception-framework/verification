#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x6a"); 
  __asm volatile("LSL R6, R4, 7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
