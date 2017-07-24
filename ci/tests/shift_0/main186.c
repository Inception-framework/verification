#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xfa"); 
  __asm volatile("LSL R3, R7, 20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
