#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xa6"); 
  __asm volatile("LSL R0, R7, 16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
