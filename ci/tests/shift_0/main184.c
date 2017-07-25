#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xce"); 
  __asm volatile("LSL R1, R6, 17");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
