#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xea"); 
  __asm volatile("mov R6,#0x17"); 
  __asm volatile("LSL R1, R3, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
