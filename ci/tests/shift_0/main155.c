#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x99"); 
  __asm volatile("mov R8,#0x1b"); 
  __asm volatile("ASR R2, R6, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
