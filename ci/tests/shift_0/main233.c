#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x92"); 
  __asm volatile("mov R9,#0x0c"); 
  __asm volatile("LSL R6, R1, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
