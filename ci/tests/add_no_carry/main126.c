#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xfb"); 
  __asm volatile("mov R1,#0x1e"); 
  __asm volatile("ADD R6, R12, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
