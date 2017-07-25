#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x00"); 
  __asm volatile("LSL R10, R0, 16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
