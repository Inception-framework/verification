#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xca"); 
  __asm volatile("LSL R12, R2, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
