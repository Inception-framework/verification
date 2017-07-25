#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x63"); 
  __asm volatile("mov R2,#0x07"); 
  __asm volatile("LSL R9, R0, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
