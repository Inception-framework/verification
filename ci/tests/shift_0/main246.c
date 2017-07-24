#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xb7"); 
  __asm volatile("LSL R8, R9, 31");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
