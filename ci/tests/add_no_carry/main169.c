#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x98"); 
  __asm volatile("ADD R0, R3, #0x3a9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
