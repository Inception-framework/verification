#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x42"); 
  __asm volatile("mov R0,#0x99"); 
  __asm volatile("ADD R1, R3, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
