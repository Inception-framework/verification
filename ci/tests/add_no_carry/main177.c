#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x86"); 
  __asm volatile("ADDS R0, R1, #0x9c");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
