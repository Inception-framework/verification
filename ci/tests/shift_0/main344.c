#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xea"); 
  __asm volatile("LSL R3, R12, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
