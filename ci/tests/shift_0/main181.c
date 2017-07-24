#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x8e"); 
  __asm volatile("mov R4,#0x1c"); 
  __asm volatile("LSL R11, R12, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
