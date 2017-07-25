#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xc6"); 
  __asm volatile("LSL R8, R0, 11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
