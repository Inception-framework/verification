#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x32"); 
  __asm volatile("LSL R1, R3, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
