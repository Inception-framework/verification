#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xd7"); 
  __asm volatile("ADD R3, R1, #0x9c5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
