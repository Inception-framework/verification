#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x33"); 
  __asm volatile("mov R5,#0xde"); 
  __asm volatile("ADD R7, R8, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
