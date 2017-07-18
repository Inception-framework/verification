#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x29"); 
  __asm volatile("ADD R9, R11, #0x4d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
