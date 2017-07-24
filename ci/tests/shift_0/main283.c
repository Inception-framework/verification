#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x7c"); 
  __asm volatile("mov R9,#0x16"); 
  __asm volatile("LSL R9, R5, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
