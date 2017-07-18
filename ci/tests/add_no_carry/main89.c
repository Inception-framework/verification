#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x94"); 
  __asm volatile("ADD R1, R6, #0xe5a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
