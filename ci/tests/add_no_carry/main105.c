#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x2b"); 
  __asm volatile("ADD R1, R12, #0x14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
