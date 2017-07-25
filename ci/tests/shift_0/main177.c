#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xca"); 
  __asm volatile("mov R7,#0x06"); 
  __asm volatile("LSL R6, R8, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
