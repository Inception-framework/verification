#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x39"); 
  __asm volatile("LSL R0, R12, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
