#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x50"); 
  __asm volatile("LSL R1, R4, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
