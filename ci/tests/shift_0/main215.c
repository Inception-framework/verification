#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x29"); 
  __asm volatile("mov R3,#0x17"); 
  __asm volatile("ASR R3, R5, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
