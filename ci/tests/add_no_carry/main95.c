#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x83"); 
  __asm volatile("ADD R7, R6, #0x6a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
