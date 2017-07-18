#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xfc"); 
  __asm volatile("ADCS R12, R6, #0xeb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
