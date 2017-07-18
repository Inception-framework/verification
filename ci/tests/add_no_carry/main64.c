#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x33"); 
  __asm volatile("ADD R11, R2, #0xf38");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
