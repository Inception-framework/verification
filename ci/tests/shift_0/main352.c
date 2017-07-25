#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x9f"); 
  __asm volatile("LSL R10, R0, 24");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
