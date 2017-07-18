#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x60"); 
  __asm volatile("ADD R0, R1, #0x3d4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
