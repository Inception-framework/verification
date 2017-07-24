#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x24"); 
  __asm volatile("mov R1,#0x16"); 
  __asm volatile("LSL R1, R5, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
