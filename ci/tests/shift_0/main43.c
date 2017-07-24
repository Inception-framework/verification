#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x9f"); 
  __asm volatile("mov R10,#0x16"); 
  __asm volatile("LSL R10, R6, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
