#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xc5"); 
  __asm volatile("mov R5,#0x0f"); 
  __asm volatile("LSL R7, R1, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
