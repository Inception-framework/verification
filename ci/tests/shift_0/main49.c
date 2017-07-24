#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x43"); 
  __asm volatile("mov R11,#0x13"); 
  __asm volatile("LSL R9, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
