#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x5c"); 
  __asm volatile("mov R0,#0x1e"); 
  __asm volatile("ASR R5, R6, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
