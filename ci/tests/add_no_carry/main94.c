#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x67"); 
  __asm volatile("ADD R12, R10, #0x3ce");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
