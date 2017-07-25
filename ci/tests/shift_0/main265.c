#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x1f"); 
  __asm volatile("mov R0,#0x0f"); 
  __asm volatile("LSL R7, R10, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
