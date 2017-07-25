#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xef"); 
  __asm volatile("LSL R0, R9, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
