#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x77"); 
  __asm volatile("mov R10,#0x03"); 
  __asm volatile("ROR R6, R0, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
