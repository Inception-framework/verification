#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xdb"); 
  __asm volatile("LSL R2, R1, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
