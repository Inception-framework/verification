#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x4f"); 
  __asm volatile("ASR R1, R6, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
