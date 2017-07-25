#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x2e"); 
  __asm volatile("mov R4,#0x01"); 
  __asm volatile("LSL R9, R5, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
