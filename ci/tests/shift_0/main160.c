#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x2b"); 
  __asm volatile("LSL R10, R5, 15");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
