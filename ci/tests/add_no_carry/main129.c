#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x96"); 
  __asm volatile("ADD R6, R12, #0x3e3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
