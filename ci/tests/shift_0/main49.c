#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xb7"); 
  __asm volatile("mov R9,#0x08"); 
  __asm volatile("LSL R9, R4, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
