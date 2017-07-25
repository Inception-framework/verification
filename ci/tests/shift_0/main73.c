#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x6a"); 
  __asm volatile("mov R6,#0x12"); 
  __asm volatile("LSL R8, R2, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
