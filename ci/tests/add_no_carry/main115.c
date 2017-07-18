#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x86"); 
  __asm volatile("ADD R1, R7, #0x9b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
