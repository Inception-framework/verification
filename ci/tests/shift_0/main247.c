#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x06"); 
  __asm volatile("mov R3,#0x0a"); 
  __asm volatile("LSL R7, R4, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
