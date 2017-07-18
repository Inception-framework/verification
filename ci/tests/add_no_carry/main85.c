#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xab"); 
  __asm volatile("ADD R0, R4, #0x4f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
