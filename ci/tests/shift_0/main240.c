#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x8b"); 
  __asm volatile("LSL R6, R10, 7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
