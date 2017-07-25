#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x7c"); 
  __asm volatile("LSL R2, R10, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
