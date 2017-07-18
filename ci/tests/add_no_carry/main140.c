#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x24"); 
  __asm volatile("ADD R1, R5, #0x3e");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
