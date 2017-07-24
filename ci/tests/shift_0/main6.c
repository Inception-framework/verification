#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xa1"); 
  __asm volatile("LSL R5, R6, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
