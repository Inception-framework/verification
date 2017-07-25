#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x28"); 
  __asm volatile("LSL R5, R11, 16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
