#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x34"); 
  __asm volatile("LSL R9, R1, 19");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
