#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xf1"); 
  __asm volatile("mov R1,#0x1f"); 
  __asm volatile("LSL R6, R11, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
