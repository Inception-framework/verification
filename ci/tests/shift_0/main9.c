#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xcc"); 
  __asm volatile("mov R11,#0x00"); 
  __asm volatile("LSL R1, R11, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
