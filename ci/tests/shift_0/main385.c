#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xf2"); 
  __asm volatile("mov R3,#0x11"); 
  __asm volatile("LSL R9, R9, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
