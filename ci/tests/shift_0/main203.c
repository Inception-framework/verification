#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x58"); 
  __asm volatile("mov R3,#0x14"); 
  __asm volatile("ASR R0, R11, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
