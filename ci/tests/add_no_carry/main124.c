#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x43"); 
  __asm volatile("ADD R9, R9, #0xa5d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
