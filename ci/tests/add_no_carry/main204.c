#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x2b"); 
  __asm volatile("ADD R3, R10, #0x5f9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
