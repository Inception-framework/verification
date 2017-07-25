#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xbe"); 
  __asm volatile("mov R9,#0x08"); 
  __asm volatile("LSL R4, R7, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
