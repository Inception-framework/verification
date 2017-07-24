#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x79"); 
  __asm volatile("mov R2,#0x0f"); 
  __asm volatile("LSL R1, R5, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
