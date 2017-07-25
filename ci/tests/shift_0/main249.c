#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x6d"); 
  __asm volatile("mov R3,#0x08"); 
  __asm volatile("LSL R9, R12, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
