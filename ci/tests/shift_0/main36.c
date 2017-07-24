#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xef"); 
  __asm volatile("LSL R2, R0, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
