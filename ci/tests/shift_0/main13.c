#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xfa"); 
  __asm volatile("mov R1,#0x13"); 
  __asm volatile("LSL R1, R5, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
