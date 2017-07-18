#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x0b"); 
  __asm volatile("mov R3,#0x5e"); 
  __asm volatile("ADD R0, R9, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
