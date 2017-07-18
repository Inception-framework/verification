#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x0d"); 
  __asm volatile("ADD R1, R9, #0xb79");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
