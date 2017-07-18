#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x33"); 
  __asm volatile("ADD R8, R6, #0x851");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
