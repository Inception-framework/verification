#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x5d"); 
  __asm volatile("ASR R4, R11, 7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
