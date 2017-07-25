#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xb7"); 
  __asm volatile("mov R12,#0x1e"); 
  __asm volatile("LSL R5, R2, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
