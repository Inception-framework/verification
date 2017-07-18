#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x60"); 
  __asm volatile("ADD R8, R12, #0x13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
