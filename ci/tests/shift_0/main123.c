#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xb1"); 
  __asm volatile("ASR R1, R11, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
