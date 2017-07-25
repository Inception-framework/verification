#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xae"); 
  __asm volatile("LSL R3, R7, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
