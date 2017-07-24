#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xa8"); 
  __asm volatile("mov R4,#0x1a"); 
  __asm volatile("LSL R4, R6, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
