#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x27"); 
  __asm volatile("LSL R9, R1, 27");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
