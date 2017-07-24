#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x08"); 
  __asm volatile("mov R11,#0x11"); 
  __asm volatile("LSL R3, R3, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
