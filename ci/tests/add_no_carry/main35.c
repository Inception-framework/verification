#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x24"); 
  __asm volatile("ADD R1, R3, #0x9a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
