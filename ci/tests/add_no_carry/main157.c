#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x98"); 
  __asm volatile("ADDS R9, R6, #0xb5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
