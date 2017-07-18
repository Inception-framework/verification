#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x93"); 
  __asm volatile("ADD R2, R12, #0x61");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
