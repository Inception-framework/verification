#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x96"); 
  __asm volatile("mov R11,#0x07"); 
  __asm volatile("LSL R6, R12, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
