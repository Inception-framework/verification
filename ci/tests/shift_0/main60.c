#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x6d"); 
  __asm volatile("LSL R5, R0, 0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
