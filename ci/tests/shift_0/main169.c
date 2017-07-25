#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x2c"); 
  __asm volatile("mov R7,#0x0d"); 
  __asm volatile("LSL R5, R7, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
