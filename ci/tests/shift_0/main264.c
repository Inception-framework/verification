#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xb4"); 
  __asm volatile("LSL R10, R2, 1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
