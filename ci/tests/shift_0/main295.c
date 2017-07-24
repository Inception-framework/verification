#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x8f"); 
  __asm volatile("mov R4,#0x14"); 
  __asm volatile("LSL R6, R12, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
