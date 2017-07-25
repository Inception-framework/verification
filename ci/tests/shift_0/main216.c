#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xcb"); 
  __asm volatile("LSL R3, R9, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
